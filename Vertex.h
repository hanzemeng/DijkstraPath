#ifndef VERTEX
#define VERTEX

#include <vector>
#include <string>
#include <cmath>
#include <iostream>

struct Vertex
{
    Vertex();
    Vertex(double, double);
    Vertex(std::string);
    void addNeighbor(Vertex*);
    double distanceFrom(Vertex*);
    void print();
    std::string printPath();
    std::string printPath(Vertex*);


    int ID;
    double dist;
    double x;
    double y;
    std::vector<Vertex*> neighbors;
    Vertex* prev;
    static int COUNT;
};

#endif
