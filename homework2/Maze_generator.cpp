// Yasmeen Dao
// 2/7/23 Generates and prints maze of random size

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

// create class
class MazeGenerator {
public:
  // call functions in class
  MazeGenerator(int size);
  // initialize vector
  vector<vector<char> > vec;
  void printMaze(int size);
};

// function , constructor to generate maze
// take in size
MazeGenerator::MazeGenerator(int size) {
  // call vector
  vector<vector<char> > temp(size, vector<char>(size));
  vec = temp;
  // loop through rows and cols
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      // generate random number 0-2
      int num = rand() % 2;
      // place # if random number equals 0
      if (num == 0) {
        vec[row][col] = '#';
      } else {
        // otherwise place .
        vec[row][col] = '.';
      }
    }
  }
}

// function to print maze
void MazeGenerator::printMaze(int size) {

  // loop through rows and cols
  for (int row = 0; row < size; row++) {
    for (int col = 0; col < size; col++) {
      // print the vector
      cout << vec[row][col] << " ";
    }
    cout << endl;
  }
}

int main() {

  /*
  Pseudocode:
   - Write  a  class  called  MazeGenerator  that  produces  a  randomly
  generated  maze  of  a  given size.
   -  function {with appropriate name} that can be used to generate the maze.
   -  This function should take the size as argument and return a
  two-dimensional built-in array of chars or a vector of vectors (i.e.,
  representing maze). Feel free to use any symbol (like #).
   - The class should also have  another function that can  print a given maze.
  To test your program, generate  several  randomly  generated  mazes  and print
  them.  Considering  that  your  mazes are randomly generated, how many of
  these have a valid path inside?
  -  input validation to ensure that user has entered the correct size.
  */

  int size;

  // user input for validation
  cout << "Enter size for maze: ";
  cin >> size;
  // cout << size << endl;
  //  validate size
  while (size <= 0) {
    cout << "re-enter: ";
    cin >> size;
  }

  // call maze generator function
  MazeGenerator obj(size);
  // print the given maze
  obj.printMaze(size);

} // end of main

/*
Questions:
Many of the randomly generated mazes don't have valid paths. The larger sized mazes tend to have more shorter valid paths. 
*/