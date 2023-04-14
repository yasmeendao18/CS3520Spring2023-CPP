#ifndef ANT_HPP
#define ANT_HPP

#include "organism.hpp"

class Ant: public Organism 
{

public:
  Ant(): Organism(){}
  Ant(Game* currGame, int x, int y);
  void breed();
  int getType() override { return ANT; }

};

#endif 
