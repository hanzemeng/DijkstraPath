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


    int ID;
    double dist;
    double x;
    double y;
    std::vector<Vertex*> neighbors;
    std::vector<Vertex*> pathToSelf;

    static int COUNT;
};

#endif
