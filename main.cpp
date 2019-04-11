// Jon Zivku, jzivku, jonzivku@me.com, main.cpp, A06 Maze Generation
/*
  Programming for generating navigable mazes. Implementation of the mazes is
  with a disjoint set w/ Union Find data structure.
  Comments: this was a nice & straight-forward problem, without the
  complications of IO that plagued the last assignment. I'd like to play around
  with the connect function to see if I can get some neat structures out of it,
  some preliminary testing shows that changing the order of my if-tree in
  connect can have *some* effect on the structure. Future routes of exploration
  include making Maze::shuffleOrder() semi-random/strange like a minheap

  Per your suggestion, I implemented numSets. It improves the time by about 5%
  for n = 2000, this is because it ends the loop in Maze::mazeGen() a little
  earlier. The way that my maze generation process works, when each cell has had
  connect run on it, that there must be only one set remaining, and so that is
  what Maze::mazeGen() does.
  Definitely good to implement counters. This is a technique that I failed to
  use in MonsterList last semester, and I forget how efficient of an operation
  that it can be.

  Status: compiling/working/tested up to n = 10000
 */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Maze.h"

int main(int argc, char* argv[]){
  if(argc != 2 || !std::isdigit(argv[1][0]) || std::atoi(argv[1])<3 ){
    std::cerr << "USAGE:\t./p6 n , where n is a natural number 3 or greater."
	      << std::endl;
    std::cerr << "\tPrints a 'n x n' maze." << std::endl;
    return -1;
  }
  int size = std::atoi(argv[1]);
  Maze A(size);
  A.print();

}
