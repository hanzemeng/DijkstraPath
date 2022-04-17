#include "Vertex.h"
#include <iostream>
#include <fstream>
#include <string>
#include <set>
using namespace std;

int VERTEX_COUNT;
vector<Vertex> vertices;

void setUp(string path);
void DijkstraPath();

int main(int argc, char** argv)
{
    setUp(argv[1]);
    DijkstraPath();
    for(Vertex& v : vertices)
    {
        v.print();
    }
    return 0;
}

struct comp
{
    bool operator()(const Vertex* lhs, const Vertex* rhs) const
    {
        if(lhs->dist == rhs->dist)
        {
            return lhs->ID < rhs->ID;
        }
        return lhs->dist < rhs->dist;
    }
};

void DijkstraPath()
{
    set<Vertex*, comp> uncheckedVertices;
    vertices[0].dist = 0;
    vertices[0].pathToSelf.push_back(&vertices[0]);
    uncheckedVertices.insert(&vertices[0]);
    for(int i=1; i<VERTEX_COUNT; i++)
    {
        uncheckedVertices.insert(&vertices[i]);
    }

    while(!uncheckedVertices.empty())
    {
        Vertex* currentVertex = *uncheckedVertices.begin();
        uncheckedVertices.erase(uncheckedVertices.begin());

        for(Vertex* n : currentVertex->neighbors)
        {
            double newDist = currentVertex->dist + currentVertex->distanceFrom(n);
            if(n->dist > newDist)
            {
                uncheckedVertices.erase(n);
                n->dist = newDist;
                n->pathToSelf = currentVertex->pathToSelf;
                n->pathToSelf.push_back(n);
                uncheckedVertices.insert(n);
            }
        }
    }
}

void setUp(string path)
{
    fstream inFile;
    inFile.open(path);
    string temp;
    getline(inFile, temp);
    int count = stoi(temp);
    VERTEX_COUNT = count;
    vertices.reserve(count);
    while(count-->0)
    {
        getline(inFile, temp);
        vertices.push_back(Vertex(temp));
    }
    getline(inFile, temp);
    count = stoi(temp);
    while(count-->0)
    {
        getline(inFile, temp);
        temp += " ";
        string index = "";
        int v1 = -1;
        int v2 = -1;
        for(char c : temp)
        {
            if(' ' != c)
            {
                index += c;
            }
            else
            {
                if(-1 == v1)
                {
                    v1 = stoi(index);
                    index = "";
                }
                else
                {
                    v2 = stoi(index);
                }
            }
        }
        vertices[v1].addNeighbor(&vertices[v2]);
        vertices[v2].addNeighbor(&vertices[v1]);
    }
}
