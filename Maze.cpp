// Jon Zivku, jzivku, jonzivku@me.com, Maze.cpp, A06 Maze Generation
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include "Maze.h"

Maze::Maze(int pN){
  std::srand( std::time( 0));
  if(pN < 3)
    pN = 3;
  n = pN;
  nxn = n * n;
  A = new DisjointSet(nxn);
  order = new int[nxn];
  maze = new unsigned char[nxn];
  mazeGen();
}

Maze::~Maze(){
  delete A;
  delete [] order;
  delete [] maze;
}

void Maze::print(){
  std::vector<char> outMaze = format();
  for(int i=0; i<nxn; i++){
    std::cout << outMaze[i];
    if( (i+1)%n == 0 )
      std::cout << std::endl;
  }
}

void Maze::check(){
  int check = A->find(0);
  int error = 0;
  for(int i = 1; i < nxn; i++){
    if(check != A->find(i)){
      std::cout << "Error at index " << i << std::endl;
      error++;
    }
    check = A->find(i);
  }
  std::cout << "Check ended with " << error << " errors" << std::endl;
}

std::vector<char> Maze::format(){
  std::vector<char> outMaze(nxn);
  for(int i=0; i<nxn; i++){
    if(maze[i] < 10)
      outMaze[i] = maze[i] + 48;
    else if(maze[i] >= 10)
      outMaze[i] = maze[i] + 87;
  }
  return outMaze;
}

void Maze::mazeGen(){
  for(int i=0; i<nxn; i++){
    order[i] = i;
    maze[i] = 0x0F;
  }
  // set beginning and end;
  maze[0] = 0x0B;
  maze[nxn-1] = 0x0E;

  shuffleOrder();
  //with numSets
  for(int i = 0; i < nxn && A->getSets() > 1; i++){
    connect(order[i]);
  }
}

void Maze::shuffleOrder(){
  int temp;
  int randInd;
  //fisher-yates, durstenfeld
  for(int i = nxn-1; i > 0; i--){
    randInd = std::rand()%i;
    temp = order[i];
    order[i] = order[randInd];
    order[randInd] = temp;
  }
}

void Maze::connect(int i){
  //look right
  if( right(i)%n != 0 && A->unionFind(i, right(i) ) ){
    maze[i]        = maze[i]        & 0x0E;
    maze[right(i)] = maze[right(i)] & 0x0B;
  }
  //look down
  if( below(i) < nxn && A->unionFind(i, below(i) ) ){
    maze[i]        = maze[i]        & 0x0D;
    maze[below(i)] = maze[below(i)] & 0x07;
  }
  // look left
  if( (left(i)+1)%n != 0 && A->unionFind(i, left(i) ) ){
    maze[i]       = maze[i]       & 0x0B;
    maze[left(i)] = maze[left(i)] & 0x0E;
  }
  // look above
  if( above(i)>0 && A->unionFind(i, above(i) ) ){
    maze[i]        = maze[i]        & 0x07;
    maze[above(i)] = maze[above(i)] & 0x0D;
  }
}
