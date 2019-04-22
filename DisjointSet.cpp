// Jon Zivku, jzivku, jonzivku@me.com, DisjointSet.cpp, A06 Maze Generation

#include <iostream>
#include <iomanip>
#include "DisjointSet.h"

DisjointSet::DisjointSet(int pSize){
  if(pSize < 0)
    pSize = -pSize;
  size = pSize;
  numSets = pSize;
  parent = new int[size];
  rank = new int[size];
  for(int i = 0; i < size; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}

DisjointSet::~DisjointSet(){
  delete [] parent;
  delete [] rank;
}

bool DisjointSet::unionFind(int x, int y){
  if( x>=size || y>=size || x<0 || y<0 )
    return false;
  if(find(x) == find(y))
     return false;
  link(find(x), find(y));
  numSets--;
  // std::cout << numSets << std::endl; //testing
  return true;
}

int DisjointSet::find(int x){
  if( x>=size || x<0 )
    return -1;
  if( x!=parent[x] ){
    parent[x] = find(parent[x]);
  }
  return parent[x];
}

void DisjointSet::print(){
  std::cout << std::setw(8) << "elemnt:\t";
  for(int i = 0; i < size; i++)
    std::cout << std::setw(3) << i;
  std::cout << std::endl;

  std::cout << std::setw(8) << "parent:\t";
  for(int i = 0; i < size; i++)
    std::cout << std::setw(3) << parent[i];
  std::cout << std::endl;

  std::cout << std::setw(8) << "rank:  \t";
  for(int i = 0; i < size; i++)
    std::cout << std::setw(3) << rank[i];
  std::cout << std::endl << std::endl;
}

void DisjointSet::link(int x, int y){
  if( rank[x] > rank[y]){
    parent[y] = x;
  }else{
    parent[x] = y;
    if( rank[x]==rank[y] ){
      rank[y]++;
    }
  }
}
