/*game.cpp -------
*
* Filename: game.cpp
* Description:
* Authors: Elizabeth Peters and Yasmeen Dao
 * Maintainer:
 * Created: Saturday Feb 18 2023
 * Last-Updated: 2/22/23
*
*/

/* Commentary:
*
*
*
*/

/* Change log:
*
*
*/

/*Copyright (c) 2022 Adeel Bhutta
*
* All rights reserved.
*
* Additional copyrights may follow
*/
#include <ncurses.h>
#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "snake.hpp"
#include "food.hpp"
#include "game_window.hpp"
#include "key.hpp"
#include "game.hpp"
#include "obstacles.hpp"
#include <bitset>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <limits.h>
using namespace std;
void generate_points(int *food_x, int *food_y, int width, int height, int x_offset, int y_offset){
    *food_x = rand() % width + x_offset+1;
    *food_y = rand() % height + y_offset+1;
}
bool obstacles_exists_size(Obstacles *obstacles,int obstacles_x, int obstacles_y, int size)
{
    int i = 0;
    bool exists = false; 
    while (!exists && i < size)
    {
        exists = exists || obstacles_exists(obstacles,obstacles_x+i, obstacles_y); 
	i++;
    }
    return exists; 
}

bool ontop_of_snake(int snake_x, int snake_y, int obstacles_x, int obstacles_y, int size)
{
    for(int i = 0; i<size; i++){
    	if(obstacles_y == snake_y || obstacles_y == snake_y-1 || obstacles_y == snake_y+1 || obstacles_y == snake_y+2 || obstacles_y == snake_y-2) 	
	{
	    if(obstacles_x == snake_x+1 || obstacles_x == snake_x-1 || obstacles_x == snake_x ||obstacles_x == snake_x-2){
		return true;
	    }
	}
    }
    return false; 
}
bool outside_limits(int min_x, int max_x, int min_y, int max_y, int curr_x, int curr_y){
    return curr_x <= min_x || curr_x >= max_x ||  curr_y <=  min_y || curr_y >= max_y;
}
    
void game()
{
    enum State state = START; // Set the initial state
    enum Mode mode = EASY;
    static int x_max, y_max; //Max screen size variables
    static int x_offset, y_offset; // distance between the top left corner of your screen and the start of the board
    gamewindow_t *window; // Name of the board
    Snake *snake; // The snake
    Food *foods,*new_food; // List of foods (Not an array)
    Obstacles *obstacles, *new_obstacles; 
    const int height = 30; 
    const int width = 70;
    int direction = rand() % 4;
    if(direction == 1)
    {
	direction = 2;
    }
    int points = 0;
    char ch;
    int size = 3;
    int lives = 3; 
    int num_obstacles;
    int num_foods;
    long base_wait_time;
    struct timespec timeret;
    timeret.tv_sec = 0;
    timeret.tv_nsec = 999999999/4;

    while(state != EXIT)
    {
        switch(state)
        {
	        case START: 
	            initscr();
                // game rules
                mvprintw(10,20,"Welcome to the snake game!");
                mvprintw(11,20, "Use the arrrow keys to move the snake and collect food.");
                mvprintw(12,20,"If the snake eats Os it grows and points increase.");
                mvprintw(13,20, "If the snake eats Xs it shrinks and points decrease. ");
                mvprintw(14,20, "For every 100 points earned, the speed of the snake increases."); 
                mvprintw(15,20, "Press p to pause and q to quit at any time. ");
		mvprintw(16,20, "Choose a mode!");
		mvprintw(17,20, "To choose easy, press e!");
		mvprintw(18,20, "To choose medium, press m!");
		mvprintw(19,20, "To choose hard, press h!");
		mvprintw(20,20, "If you do not choose a mode the default is easy"); 
                mvprintw(21,20,"Press s to start: ");
                // we chose to have the snake immediately die if the points reach below 0. 
                refresh(); 
                keypad(stdscr, TRUE); // making keys work
                curs_set(0); // hide cursor
                ch = getch();
		if(ch == 'e') {
                	mode = EASY;
                } else if( ch == 'm'){
                        mode = MEDIUM;
                } else if(ch == 'h'){
                        mode = HARD;
                }
                while(ch != 's')
                {
                    ch = getch();
		    if(ch == 'e') {
			mode = EASY;
		    } else if( ch == 'm'){
			mode = MEDIUM;
		    } else if(ch == 'h'){
			mode = HARD;
		    }
                }
		//Set mode settings
		if(mode ==EASY){
			num_obstacles = 3;
			num_foods = 10;
			base_wait_time = 999999999/4;
		}
		if(mode ==MEDIUM){
			num_obstacles = 6;
			num_foods = 15;
                        base_wait_time = 999999999/8;
		}
		if(mode == HARD){
			num_obstacles = 10;
			num_foods = 20;
                        base_wait_time = 999999999/16;
		}
		timeret.tv_nsec = base_wait_time;
                state = INIT;
                clear();
                break;	
            case INIT:
                start_color();
		//border color
		init_pair(1, COLOR_YELLOW, COLOR_GREEN);
		//snake color
		init_pair(2, COLOR_RED, COLOR_GREEN);
		//obstacles
		init_pair(3, COLOR_BLUE, COLOR_GREEN);
		//Food
		init_pair(4, COLOR_CYAN, COLOR_WHITE);
                nodelay(stdscr, TRUE); //Dont wait for char
                noecho(); // Don't echo input chars
                getmaxyx(stdscr, y_max, x_max);
                keypad(stdscr, TRUE); // making keys work
                curs_set(0); // hide cursor
                timeout(100);

                // Setting height and width of the board
                x_offset = (x_max / 2) - (width / 2);
                y_offset = (y_max / 2) - (height / 2);
                
                //Init board
                window = init_GameWindow(x_offset, y_offset, width, height);
		attron(COLOR_PAIR(1));
                draw_Gamewindow(window);
		attroff(COLOR_PAIR(1));
                //Print score
                mvprintw(0,2, "Score: %d", points); 
                mvprintw(0,3, "Lives Left: %d", lives);

                // Init snake
                snake = init_snake(x_offset + (width / 2), y_offset + (height / 2));
                
                       //Init obstacles
                int obstacles_x, obstacles_y, i;

                //Generate obstacles
                size = rand() % (width/2) +1;
                generate_points(&obstacles_x, &obstacles_y, width-size, height, x_offset, y_offset);
                obstacles = create_obstacles(obstacles_x, obstacles_y);
		for(int j = 1; j < size; j++)
                {
                        new_obstacles = create_obstacles(obstacles_x+j, obstacles_y);
                        add_new_obstacles(obstacles, new_obstacles);
                 }
                for(i = 1; i < num_obstacles; i++){
		    size = rand() % (width/2) +1;
                    generate_points(&obstacles_x, &obstacles_y, width-size, height, x_offset, y_offset);
                    while (obstacles_exists_size(obstacles,obstacles_x, obstacles_y, size)|| ontop_of_snake(snake->x, snake->y, obstacles_x, obstacles_y, size))
                        generate_points(&obstacles_x, &obstacles_y, width-size, height, x_offset, y_offset);

                    for(int j = 0; j < size; j++)
                    {
                        new_obstacles = create_obstacles(obstacles_x+j, obstacles_y);
                        add_new_obstacles(obstacles, new_obstacles);
                    }
                     
                }

                // Init foods
                int food_x, food_y;
                enum Type type;

                //Generate 10 foods
                generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                type = (rand() > RAND_MAX/2) ? Increase : Decrease; // Randomly deciding type of food
                foods = create_food(food_x, food_y, type);
                for(i = 1; i < num_foods; i++){
                    generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                    while (food_exists(foods,food_x, food_y) && obstacles_exists(obstacles,obstacles_x, obstacles_y))
                        generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                    type = (rand() > RAND_MAX/2) ? Increase : Decrease;
                    new_food = create_food(food_x, food_y, type);
                    add_new_food(foods, new_food);
                }


                state = ALIVE;
                break;

            case ALIVE:
                ch = get_char();

                if(eat_itself(snake) || obstacles_exists(obstacles,snake->x, snake->y) ||
			outside_limits(x_offset, x_offset+width, y_offset, y_offset+height, snake->x, snake->y))
                {
                    state = DEAD;
                    break; 
                }
                // check if food is at position
                if(food_exists(foods, snake->x, snake->y))
                {
                    // if the food is a O points increase and snake grows
                    if(food_type(foods, snake->x, snake->y)==Increase)
                    {
                        Snake* end = snake;
                        while(end->next)
                            end = end->next;
                        end->next = create_tail(end->x, end->y); 
                        points+=20;
                    }
                    else if(length(snake) > 1)
                    {
                        remove_tail(snake); 
                        points-=10; 
                    }else if(length(snake) <= 1) 
                    {
		                state = DEAD; 
		            }
		            snake->speed = points/100;
                    if(snake->speed == 0){
                        timeret.tv_nsec = 999999999/4;  
                    }else {
                        float speed = snake->speed *1.5;  
                        timeret.tv_nsec = base_wait_time / speed;
                    }

                    // call remove food function
                    foods = remove_eaten_food(foods,snake->x,snake->y); 
                    //Generate 1 food
                    generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                    type = (rand() > RAND_MAX/2) ? Increase : Decrease; // Randomly deciding type of food
                    new_food = create_food(food_x, food_y, type);
                    add_new_food(foods,new_food);    
                }

            
                // pause and quit 
                if(ch == 'q' || ch == 'Q') {
                        state = EXIT;
                }
                if(ch == 'p'|| ch =='P'){
                    state = PAUSE;
                }

                // move snake based on keys
                if(ch == LEFT || ch == RIGHT || ch == UP || ch == DOWN)
                {
                    if((direction == RIGHT && ch != LEFT) 
                    ||(direction == LEFT && ch != RIGHT) 
                    ||(direction == UP && ch != DOWN) 
                    ||(direction == DOWN && ch != UP))
                    {
                        direction = ch;
                    }
                }
                snake = move_snake(snake, direction);
                // Draw everything on the screen
                clear();
                mvprintw(20,20, "Key entered: %c", ch);
		attron(COLOR_PAIR(1));
                draw_Gamewindow(window);
		attroff(COLOR_PAIR(1));
		attron(COLOR_PAIR(2));
                draw_snake(snake);
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(4));
                draw_food(foods);
		attroff(COLOR_PAIR(4));
		attron(COLOR_PAIR(3));
                draw_obstacles(obstacles);
		attroff(COLOR_PAIR(3));
                // call score
                mvprintw(0,2, "Score: %d", points); 
                // call lives
                mvprintw(1,2, "Lives Left: %d", lives);
                break;
            case PAUSE:
                ch = get_char();
                if(ch == 'q' || ch == 'Q') {
                    state = EXIT;	
                }
                if(ch == 'p'|| ch =='P'){
                    state = PAUSE;
                }
                break;
            case DEAD:
                // clear screen
                clear(); 
                lives--; 
                mvprintw(9,20, "You have %d points", points); 

                // check for lives
                if(lives > 0)
                {
                    // dead screen
                    mvprintw(10,20,"Sorry, you died! You have %d lives left.", lives);
                    mvprintw(11,20,"To play again press e: ");
                    mvprintw(12,20,"To quit press q: ");
                    ch = getch();
                    while(true)
                    {
                        ch = getch();
                        if(ch == 'e')
                        {
			    while(snake->next){
				snake = remove_tail(snake);
			    }
			    free(snake);
			    snake = init_snake(x_offset + (width / 2), y_offset + (height / 2));
                            state = ALIVE;
			    if(direction == 1)
    			    {
				direction = 2;
			    }
                            break;
                        }
                        else if (ch == 'q')
                        {
                            state = EXIT;
                            break;
                        }
                    }
                }
                else
                {
                    mvprintw(10,20,"Sorry, you died! You have no lives left.");
                    mvprintw(11,20,"Press q to quit: ");
                    ch = getch();
                    while(true)
                    {
                        ch = getch();
                        if(ch == 'q')
                        {
                            state = EXIT;
                            break;
                        }
                
                    }
                }

                break;
        }// end of cases
        refresh();
        nanosleep(&timeret, NULL);
    }
    //exiting
    endwin();
    // open file

    ifstream infile("./saves/save_best_10.game");
    //fstream file_name; file_name.open("in.txt", ios:in);
    if(!infile){
    cout<<"can't open the in file"<<endl;
    }

    // read into array of 10
    int array[10]; 
    string line;  
    int i = 0;
    while(getline(infile, line)){
        array[i] = stoi(line); 
        i++; 
    }
    for(int j = i; j<10; j++)
    {
        array[j] = INT_MIN; 
    }

    // array[i] = points; 
    
    i = 9; 
    //insert score into array
    while (i >= 0 && points > array[i] ){
        i--; 
    }
    i++; 
    int mover1; 
    int mover2 = points; 
    for (int j = i; j < 10; j++)
    {
        mover1 = array[j]; 
        array[j] = mover2; 
        mover2 = mover1; 
    }

    ofstream outfile("./saves/save_best_10.game"); //open or overwrite

    if(!outfile)
    {   
        cout<<"can't open the out file"<<endl;
    }

    for(int j = 0; j < 10; j++)
    {
        if(array[j] != INT_MIN)
        {
            outfile << array[j] << endl;
        }
    }

    

    //  read info from file into storage
    //  check if score is > min score
    // if (points > points)
    // if it is place score into right location in the structure
    // read structure back into file
                
    state = EXIT;
    while(snake->next){
        snake = remove_tail(snake);
    }
    Food* temp = foods;
    while(temp) {
        temp = foods->next;
        free(foods);
        foods = temp; 
    }
    free(snake);
}
