# makefile for p6, for maze generation with disjoint sets

# defining target dependencies and files
p6: main.o Maze.o DisjointSet.o
	g++ -o p6 main.o Maze.o DisjointSet.o -Wall

# defining how each object file is to be built

main.o: main.cpp Maze.h
	g++ -c main.cpp -Wall

Maze.o: Maze.cpp Maze.h DisjointSet.h
	g++ -c Maze.cpp -Wall

DisjointSet.o: DisjointSet.cpp DisjointSet.h
	g++ -c DisjointSet.cpp -Wall

# clean up
clean:
	rm -f p6 *.o *~
