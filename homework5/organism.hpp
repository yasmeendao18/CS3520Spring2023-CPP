#ifndef ORGANISM_HPP
#define ORGANISM_HPP

#include <vector>
#include "game.hpp"

class Organism 
{

protected:
  Game* currGame;
  int x;
  int y;
  int timeTillBreed;
  int timeStepCount;
  std::vector<int> moves_to_empty(int x, int y) const;
  bool valid_cord(int x, int y) const;
  void getCoordinate(int& x, int& y, int move) const;

public:
  Organism(): currGame(nullptr), x(0), y(0), timeTillBreed(0), timeStepCount(0){}
  Organism(Game* currGame, int x, int y);
  virtual void breed()  = 0;
  virtual void move() ;
  virtual int getType() = 0;
  virtual bool starve() { return false; }

};

#endif 
