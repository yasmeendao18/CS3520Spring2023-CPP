/* key.cpp -------
 *
 * Filename: key.cpp
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

/* Copyright (c) 2022 Adeel Bhutta
 *
 * All rights reserved.
 *
 * Additional copyrights may follow
 */


#include <ncurses.h>
#include <cstdlib>
#include "key.hpp"

int get_char(){
  int ch = getch();
  switch(ch){
    case KEY_LEFT:
      return LEFT;
      break;
    case KEY_RIGHT:
      return RIGHT;
      break;
    case KEY_UP:
      return UP;
      break;
    case KEY_DOWN:
      return DOWN;
      break;
    default:
      return(ch);
      break;
  }
}
