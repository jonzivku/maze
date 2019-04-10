// Jon Zivku, jzivku, jonzivku@me.com, Maze.h, A06 Maze Generation
// generates an nxn maze, where n >= 3. 
#ifndef MAZE__H
#define MAZE__H

#include <string>
#include "DisjointSet.h"


class Maze{
 public:
  Maze(int=-1);
  ~Maze();

  void mazeGen();//testing as public  
  void print();
 private:
  
  
  void format();
  void shuffleOrder();

  void connect(int);
  
 
  int right(int i){ return i+1; }
  int below(int i){ return i+n; }
  int left(int i){ return i-1; }
  int above(int i){ return i-n; }
  bool flip(){ return std::rand()%2 == 1; }
  unsigned char *maze; //holds the maze
  int *order; // holds the order for randomizing the maze
  DisjointSet *A;
  int n;
  int nxn;
};


#endif
