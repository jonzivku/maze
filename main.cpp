// Jon Zivku, jzivku, jonzivku@me.com, main.cpp, A06 Maze Generation

// needs to continue until all elements are in the same set
#include <iostream>
#include <cstdlib>
#include <cctype>

#include "Maze.h"

using std::cout;

int main(int argc, char* argv[]){

  if(argc != 2 || !std::isdigit(argv[1][0]) || std::atoi(argv[1])<3 ){
    std::cerr << "USAGE:\t./p6 n , where n is a natural number 3 or greater." << std::endl;
    std::cerr << "\tPrints a 'n x n' maze." << std::endl;
    return -1;
  }
   
  int size = std::atoi(argv[1]);  

  Maze A(size);

  
  A.print();
  

  /*
  //testing
  std::cout << size << std::endl;

  DisjointSet A(size);

  A.unionFind(0,1);
  A.print();
  
  A.unionFind(2,0);
  A.print();                                                                              

  A.unionFind(3,4);
  A.print();                                                                                         

  A.unionFind(1,3);
  A.print();

  return 0;
  */
}


