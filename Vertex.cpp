#include "Vertex.h"
using namespace std;

int Vertex::COUNT = 0;

Vertex::Vertex() : ID(COUNT++), x(0), y(0), dist(INFINITY)
{}
Vertex::Vertex(double x, double y) : ID(COUNT++), x(x), y(y), dist(INFINITY)
{}
Vertex::Vertex(string input) : ID(COUNT++), dist(INFINITY)
{
    string temp = "";
    for(char c : input)
    {
        if(' ' != c)
        {
            temp += c;
        }
        else
        {
            x = stod(temp);
            temp = "";
        }
    }
    y = stod(temp);
}
void Vertex::addNeighbor(Vertex* a)
{
    neighbors.push_back(a);
}
double Vertex::distanceFrom(Vertex* a)
{
    return sqrt((a->x-x)*(a->x-x) + (a->y-y)*(a->y-y));
}

void Vertex::print()
{
    /*
    cout << ID << ": " << x << ", " << y << ". Nei: ";
    for(Vertex* n : neighbors)
    {
        cout << n->ID << ", ";
    }
    */
    cout << ID << ": ";
    for(int i=pathToSelf.size()-1; i>=0; i--)
    {
        cout << pathToSelf[i]->ID << ", ";
    }
    cout << endl;
}
