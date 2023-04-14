#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime> 

// hpp files
#include "game.hpp"
#include "organism.hpp"
#include "doodlebug.hpp"
#include "ant.hpp"

using namespace std;

class Game;

// direction for moves
const int LEFT = 1;
const int RIGHT = 2;
const int DOWN = 3;
const int UP = 4;


typedef Organism* OrganismPtr;
typedef Game* GamePtr;


int Game::rand_num(int start, int end) const 
{
  return rand() % (end - start + 1) + start;
}

Game::Game(){
  srand(time(NULL));
  timeStepCount = 0;
  for (int x = 0; x < SIZE; x++)
    for (int y = 0; y < SIZE; y++)
      simulation[x][y] = nullptr;
}

void Game::startGame(){
  int x,y;
  int doodlebugCount = 0;
  int antCount = 0;

  while (doodlebugCount < init_doodle){
    x = rand_num(0, SIZE - 1);
    y = rand_num(0, SIZE - 1);
    if (simulation[x][y] != nullptr) continue;
    simulation[x][y] = new Doodlebug(this, x, y);
    doodlebugCount++;
  }

  while (antCount < init_ant){
    x = rand_num(0, SIZE - 1);
    y = rand_num(0, SIZE - 1);
    if (simulation[x][y] != nullptr) continue;
    simulation[x][y] = new Ant(this, x, y);
    antCount++;
  }
}

void Game::takeTimeStep(){
  timeStepCount++;

// iterates through doodlebugs
  for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
      if (simulation[i][j] == nullptr) continue;
      if (simulation[i][j]->getType() == DOODLEBUG)
        simulation[i][j]->move();
    }
  }

// iterates through ants
  for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
      if (simulation[i][j] == nullptr) continue;

      if (simulation[i][j]->getType() == ANT)
        simulation[i][j]->move();
    }
  }


 // iterates through organisms in simulation and breeds
  for (int i = 0; i < SIZE; i++){
    for (int j = 0; j < SIZE; j++){
      if (simulation[i][j] == nullptr) continue;
      simulation[i][j]->breed();
    }
  }

// iterates through organsims in simulation for starve
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (simulation[i][j] == nullptr) continue;
      if (simulation[i][j]->starve())
      {
        delete simulation[i][j];
        simulation[i][j] = nullptr;
      }
    }
  }
}

// print ASCII characters
void Game::printSimulation() const 
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      if (simulation[i][j] == nullptr)
      {
        cout << '.';
      } 
      else if (simulation[i][j]->getType() == ANT)
      {
         cout << 'o';
      }
      else if (simulation[i][j]->getType() == QUEEN)
      {
         cout << 'Q';
      }
       else if (simulation[i][j]->getType() == WORKER)
      {
         cout << 'w';
      }
       
      else  //DOODLEBUG
        cout << 'X';
    }
    cout << endl;
  }
}

// moves to empty cells
vector<int> Organism::moves_to_empty(int x, int y) const 
{
  vector<int> movesToEmptyCells;
  int temp_X, temp_Y;
  for (int move = LEFT; move <= UP; move++)
  {
    temp_X = x;
    temp_Y = y;
    getCoordinate(temp_X, temp_Y, move);
    if (!valid_cord(temp_X, temp_Y)) continue;
    if (currGame->simulation[temp_X][temp_Y] == nullptr) 
      movesToEmptyCells.push_back(move);
  }
  return movesToEmptyCells;
}

// move organism
void Organism::getCoordinate(int& x, int& y, int move) const 
{
  if (move == LEFT) x--;
  if (move == RIGHT) x++;
  if (move == DOWN) y--;
  if (move == UP) y++;
}

// check if coordinate is valid
bool Organism::valid_cord(int x, int y) const 
{
  if (x < 0 || x >= SIZE || y < 0 || y >= SIZE)
    return false;
  return true;
}

Organism::Organism(GamePtr currGame, int x, int y): currGame(currGame), x(x), y(y), timeTillBreed(0), timeStepCount(0)
{
  this->currGame = currGame;
  this->x = x;
  this->y = y;
  timeTillBreed = 0;
  timeStepCount = currGame->timeStepCount;
}

void Organism::move(){
  if (timeStepCount == currGame->timeStepCount) return;
  timeStepCount++;
  timeTillBreed--;
  int randomMove = currGame->rand_num(LEFT, UP);
  int new_X = x;
  int new_Y = y;
  getCoordinate(new_X, new_Y, randomMove);
  if (valid_cord(new_X, new_Y))
  {
    if (currGame->simulation[new_X][new_Y] != nullptr) return;
    currGame->simulation[x][y] = nullptr;
    currGame->simulation[new_X][new_Y] = this;
    x = new_X;
    y = new_Y;
  }
}

vector<int> Doodlebug::getMovesToAnts(int x, int y) const 
{
  vector<int> movesToAnts;
  int tempX, tempY;
  for (int move = LEFT; move <= UP; move++){
    tempX = x;
    tempY = y;
    getCoordinate(tempX, tempY, move);
    if (!valid_cord(tempX, tempY)) continue;
    if (currGame->simulation[tempX][tempY] == nullptr) continue;
    if (currGame->simulation[tempX][tempY]->getType() == ANT) 
      movesToAnts.push_back(move);
  }
  return movesToAnts;
}

Doodlebug::Doodlebug(GamePtr currGame, int x, int y): Organism(currGame, x, y)
{
  timeTillStarve = doodlebug_time_starve;
  timeTillBreed = doodlebug_time_breed;
}

// breed
void Doodlebug::breed(){
  if (timeTillBreed > 0) return;
  vector<int> validMoves = moves_to_empty(x, y);
  if (validMoves.size() == 0) return;
  int randomMove = validMoves[currGame->rand_num(0, validMoves.size() - 1)];
  int new_X = x;
  int new_Y = y;
  getCoordinate(new_X, new_Y, randomMove);
  currGame->simulation[new_X][new_Y] = new Doodlebug(currGame, new_X, new_Y);
  timeTillBreed = doodlebug_time_breed;
}
//move
void Doodlebug::move(){
  if (timeStepCount == currGame->timeStepCount) return;
  vector<int> movesToAnts = getMovesToAnts(x, y);
  if (movesToAnts.size() == 0){
    Organism::move();
    timeTillStarve--;
    return;
  }
  timeStepCount++;
  timeTillStarve = doodlebug_time_starve;
  int randomMove = movesToAnts[currGame->rand_num(0, movesToAnts.size() - 1)];
  int X = x;
  int Y = y;
  getCoordinate(X, Y, randomMove);
  delete currGame->simulation[X][Y];
  currGame->simulation[X][Y] = this;
  currGame->simulation[x][y] = nullptr;
  x = X;
  y = Y;
}

Ant::Ant(GamePtr currGame, int x, int y): Organism(currGame, x, y)
{
  timeTillBreed = ant_time_breed;
}

void Ant::breed(){
  if (timeTillBreed > 0) return;
  vector<int> validMoves = moves_to_empty(x, y);
  if (validMoves.size() == 0) return;
  int randomMove = validMoves[currGame->rand_num(0, validMoves.size() - 1)];
  int newX = x;
  int newY = y;
  getCoordinate(newX, newY, randomMove);
  currGame->simulation[newX][newY] = new Ant(currGame, newX, newY);
  timeTillBreed = ant_time_breed;
}

// queen class
class Queen: public Ant {

public:
  Queen(): Ant(){}
  Queen(GamePtr currGame, int x, int y) : Ant(currGame, x, y) {}
  void breed()override;
  void move()override;
  int getType() override { return QUEEN; }

};

// Queen::Queen(GamePtr currGame, int x, int y): Ant(currGame, x, y) {
//   timeTillBreed = ant_time_breed;
// }

void Queen::breed() {
  vector<int> moves = moves_to_empty(x, y);
  if (moves.size() == 0) return; // no empty cells to breed
  timeTillBreed = ant_time_breed;
  int move = moves[rand() % moves.size()];
  int new_x = x, new_y = y;
  getCoordinate(new_x, new_y, move);
  //currGame->simulation[new_x][new_y] = new Ant(currGame, new_x, new_y);
}
void Queen::move()
{
  timeStepCount++;
  timeTillBreed--;

  if (timeTillBreed >= 25) {
    breed();
  }
}

class Worker: public Ant 
{
public:
  Worker(): Ant(){}
  Worker(GamePtr currGame, int x, int y): Ant(currGame, x, y){}
  void breed();
  int getType()override{ return WORKER; }
};

void Worker::breed() {
  vector<int> moves = moves_to_empty(x, y);
  if (moves.size() == 0) return; // no empty cells to breed
  timeTillBreed = ant_time_breed;
  int move = moves[rand() % moves.size()];
  int new_x = x, new_y = y;
  getCoordinate(new_x, new_y, move);
  //currGame->simulation[new_x][new_y] = new Ant(currGame, new_x, new_y);
}

int main()
{
  Game g;

  g.startGame();
  
 for(int i = 0; i < iterations; i++)
 {
    g.takeTimeStep();
    g.printSimulation();
    cout<<endl;
  }
 
  return 0;
}