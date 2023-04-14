#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "organism.hpp"

class Doodlebug: public Organism 
{

private:
  int timeTillStarve;
  std::vector<int> getMovesToAnts(int x, int y) const;

public:
  Doodlebug(): Organism(), timeTillStarve(0){}
  Doodlebug(Game* currGame, int x, int y);
  void breed();
  void move();
  int getType() override { return DOODLEBUG; }
  bool starve() override { return timeTillStarve == 0; }

};

#endif
