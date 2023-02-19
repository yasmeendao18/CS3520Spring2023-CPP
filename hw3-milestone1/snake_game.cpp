/*snake_hame.cpp -------
*
* Filename: snake_game.cpp
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
#include "game.hpp"
#include <cstdlib>
#include <cstdio>
#include <ncurses.h>

int main(void){

    // // init screen
    initscr();
    printf("thuoeou");
    char ch; 
    mvprintw(10,20,"Welcome to the snake game. Use the arrrow keys to move the snake and collect food. The more food that is collected, the more points are earned and the larger the snake gets!");
    mvprintw(20,20,"Press s to start: "); 
    refresh(); 
    noecho(); 
    ch = getch(); 
    while (ch != 's')
    {
        ch = getch(); 
    }
    game();
    printf("tuenao");
    return(0);
}
