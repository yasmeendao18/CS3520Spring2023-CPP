/*obstacles.cpp -------
*
* Filename: food.cpp
* Description:
* Authors: Elizabeth Peters and Yasmeen Dao
 * Maintainer:
 * Created: Sunday Feb 26 2023
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

#include <cstdlib>
#include <ncurses.h>
#include <cstdbool>
#include "obstacles.hpp"

//Create new obstacle
Obstacles* create_obstacles(int x, int y){
    Obstacles* new_obstacles = (Obstacles*)malloc(sizeof(Obstacles));
     
    new_obstacles->x = x;
    new_obstacles->y = y;

    return new_obstacles;
}


//Check if obstacle exists at coordinates
bool obstacles_exists(Obstacles* obstacles, int x, int y){
    Obstacles* temp = obstacles;
    while(temp){
        if(temp->x == x && temp->y == y)
            return true;
        temp = temp->next;
    }
    return false;
}

//Add new obstacles to end of food list
void add_new_obstacles(Obstacles* obstacles, Obstacles* new_obstacles){
    Obstacles* temp = obstacles;
    while(temp->next) {
        temp = temp->next;
    }
    temp->next = new_obstacles;
}

// Display all the obstacles
void draw_obstacles(Obstacles *obstacles)
{   Obstacles* temp = obstacles;
    while(temp) {
        mvprintw(temp->y, temp->x, "%c", '@');
        temp = temp->next;
    }
}


