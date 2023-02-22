/*game.cpp -------
*
* Filename: game.cpp
* Description:
* Author: Adeel Bhutta
* Maintainer:
* Created: Sat Sep 12 13:16:12 2022
* Last-Updated: September 12 16:51 2022
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
#include <cstdlib>
#include <ctime>
#include "snake.hpp"
#include "food.hpp"
#include "game_window.hpp"
#include "key.hpp"
#include "game.hpp"
void generate_points(int *food_x, int *food_y, int width, int height, int x_offset, int y_offset){
    *food_x = rand() % width + x_offset+1;
    *food_y = rand() % height + y_offset+1;
}
void game(){
    enum State state = START; // Set the initial state
    static int x_max, y_max; //Max screen size variables
    static int x_offset, y_offset; // distance between the top left corner of your screen and the start of the board
    gamewindow_t *window; // Name of the board
    Snake *snake; // The snake
    Food *foods,*new_food; // List of foods (Not an array)

    const int height = 30; 
    const int width = 70;
    int direction = rand() % 4;
    int points = 0;
    char ch;

    struct timespec timeret;
    timeret.tv_sec = 0;
    timeret.tv_nsec = 999999999/4;

    while(state != EXIT){
        switch(state){
	case START: 
	    initscr();
        // game rules
	    mvprintw(10,20,"Welcome to the snake game!");
            mvprintw(11,20, "Use the arrrow keys to move the snake and collect food.");
            mvprintw(12,20,"If the snake eats Os it grows and points increase.");
            mvprintw(13,20, "If the snake eats Xs it shrinks and points decrease. ");
            mvprintw(14,20, "For every 100 points earned, the speed of the snake increases."); 
            mvprintw(15,20, "Press p to pause and q to quit at any time. "); 
            mvprintw(16,20,"Press s to start: ");
            // we chose to have the snake immediately die if the points reach below 0. 
	    refresh(); 
            keypad(stdscr, TRUE); // making keys work
            curs_set(0); // hide cursor
	    ch = getch();
	    while(ch != 's'){
		ch = getch();
	    }
	    state = INIT;
	    clear();
            break;	
        case INIT:
            //initscr();
            start_color();
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
            draw_Gamewindow(window);

            //Print score
            // noecho();
            mvprintw(0,2, "Score: %d", points); 

            // Init snake
            snake = init_snake(x_offset + (width / 2), y_offset + (height / 2));
            
            // Init foods
            int food_x, food_y, i;
            enum Type type;

            //Generate 20 foods
            generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
            type = (rand() > RAND_MAX/2) ? Increase : Decrease; // Randomly deciding type of food
            foods = create_food(food_x, food_y, type);
            for(i = 1; i < 20; i++){
                generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                while (food_exists(foods,food_x, food_y))
                    generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                type = (rand() > RAND_MAX/2) ? Increase : Decrease;
                new_food = create_food(food_x, food_y, type);
                add_new_food(foods, new_food);
            }
            state = ALIVE;
            break;

        case ALIVE:
            ch = get_char();

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
                else if(points > 0)
                {
                    remove_tail(snake); 
                    points-=10; 
                }else if(points <= 0) {
		    state = DEAD;
		}
		snake->speed = points/100;
                if(snake->speed == 0){
                    timeret.tv_nsec = 999999999/4;  
                }else {
                    float speed = snake->speed *1.5;  
                    timeret.tv_nsec = (999999999/4) / speed;
                }

                // call remove food function
                foods = remove_eaten_food(foods,snake->x,snake->y); 
                //Generate 1 food
                generate_points(&food_x, &food_y, width, height, x_offset, y_offset);
                type = (rand() > RAND_MAX/2) ? Increase : Decrease; // Randomly deciding type of food
                new_food = create_food(food_x, food_y, type);
                add_new_food(foods,new_food);
                 
            }
            
            /* Write your code here */
            // pause and quit 
	if(ch == 'q' || ch == 'Q') {
                state = DEAD;
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
            draw_Gamewindow(window);
            draw_snake(snake);
            draw_food(foods);
            // call score
            mvprintw(0,2, "Score: %d", points); 
            break;
	case PAUSE:
	    ch = get_char();
	    if(ch == 'q' || ch == 'Q') {
		state = DEAD;	
	    }
	    if(ch == 'p'|| ch =='P'){
		state = ALIVE;
	    }
	    break;
        case DEAD:
            endwin();
	    state = EXIT;
	    while(snake->next){
		snake = remove_tail(snake);
	    }
	    Food* temp;
	    while(temp) {
		temp = foods->next;
		free(foods);
	    }
	    free(snake);
	    return;
            break;
        }
        refresh();
        nanosleep(&timeret, NULL);
    }
}
