// Jon Zivku, jzivku, jonzivku@me.com, main.cpp, A06 Maze Generation
/*
  Programming for generating navigable mazes. Implementation of the mazes is with a disjoint set w/ Union Find data structure. 
  Comments: this was a nice & straight-forward problem, without the complications of IO that I had with the last assignment.
  I'd like to play around with the connect function to see if I can get some neat structure.
  Status: compiling/working/tested up to 1000x1000
 */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include "Maze.h"

int main(int argc, char* argv[]){
  if(argc != 2 || !std::isdigit(argv[1][0]) || std::atoi(argv[1])<3 ){
    std::cerr << "USAGE:\t./p6 n , where n is a natural number 3 or greater." << std::endl;
    std::cerr << "\tPrints a 'n x n' maze." << std::endl;
    return -1;
  }
  int size = std::atoi(argv[1]);  
  Maze A(size);
  A.print();
  // A.check();
}


