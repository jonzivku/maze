// Jon Zivku, jzivku, jonzivku@me.com, Maze.h, A06 Maze Generation
/* generates an nxn maze, where n >= 3.
   example code to print an nxn maze:
   Maze A(n);
   A.print(); */
#ifndef MAZE__H
#define MAZE__H

#include <vector>
#include "DisjointSet.h"

class Maze{
 public:
  Maze(int=-1);
  ~Maze();
  void print();
  // public function for printing the current maze
  void check();
  // public function for checking the validity of the maze
 private:
  std::vector<char> format();
  // returns a vector of the current maze in printable ASCII format
  void mazeGen();
  // helper function for preparing the data structures.
  void shuffleOrder();
  // shuffles member array "order"
  void connect(int);
  // checks each surrounding cell for a union in A. if not unioned,
  //   unions in A and breaks down walls between the two cells.
  int right(int i){ return i+1; }
  int below(int i){ return i+n; }
  int left(int i){ return i-1; }
  int above(int i){ return i-n; }
  unsigned char *maze; //holds the maze
  int *order; // holds the order for randomizing the maze
  DisjointSet *A;
  int n; //length of side
  int nxn; // total number of cells in the maze
};

#endif
