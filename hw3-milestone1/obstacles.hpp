/*food.hpp -------
*
* Filename: obstacles.hpp
* Description:
* Author: Elizabeth Yasmeen
* Maintainer:
* Created: Sat Sep 12 13:21:55 2022
* Last-Updated: September 12 16:01 2022
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

//Structure to hold properties of obstacles
struct Obstacles{
  int x;
  int y;
  struct Obstacles* next;
};

typedef struct Obstacles Obstacles; 

//Function prototypes 
void add_new_obstacles(Obstacles* obstacles, Obstacles* new_obstacles);
bool obstacles_exists(Obstacles* obstacles, int x, int y);
Obstacles* create_obstacles(int x, int y);
void draw_obstacles(Obstacles *obstacles);
