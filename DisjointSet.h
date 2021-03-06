// Jon Zivku, jzivku, jonzivku@me.com, DisjointSet.h, A06 Maze Generation
#ifndef DISJOINTSET__H
#define DISJOINTSET__H

class DisjointSet{
 public:
  DisjointSet(int=0);
  ~DisjointSet();
  bool unionFind(int x, int y);
  // unions set containing x with set containing y.
  //pre-cond: x and y are elements from [0,size).
  //postcond: if x and y are in different sets, the sets have been unioned;
  //          return true. if not, no change; return false. also returns false
  //          if preconditions not set

  int find(int x);
  //pre-cond: x is an element from [0,size)
  //postcond: returns the representative of the set containing x and compresses
  //          the path of all elements from x to the set representative

  void print();
  // prints all members of the set, and their respective ranks and parents
  int getSets(){return numSets;};
  // returns the number of sets in the disjoint set
 private:
  void link(int x, int y);
  int size;
  int *parent;
  int *rank; //array of ranks
  int numSets;
};

#endif
