#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime> 

class Organism;
class Doodlebug;
class Ant; //male
class Queen;
class Worker;

// initiallizations
const int SIZE = 20;
const int iterations = 800;

const int init_doodle = 15;
const int init_ant = 50;

const int doodlebug_time_breed = 10;
const int ant_time_breed = 3;

const int ant_time_starve = 5;

const int doodlebug_time_starve = 10;

const int DOODLEBUG = 1;
const int ANT = 2;
const int QUEEN = 3;
const int WORKER = 4;

typedef Organism* OrganismPtr;

class Game 
{

  friend class Organism;
  friend class Ant;
  friend class Doodlebug;

private:
  OrganismPtr simulation[SIZE][SIZE];
  int timeStepCount;
  int rand_num(int start, int end) const;

public:
  Game();
  void startGame();
  void takeTimeStep();
  void printSimulation() const;

};

#endif 
