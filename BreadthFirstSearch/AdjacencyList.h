#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include "Queue.h"

using namespace std;

enum Color
{
    WHITE,
    GRAY,
    BLACK
};

typedef class AdjacencyList 
{
private:
    int size;
    vector<list<int>> Adj;
    vector<Color> color;
    vector<int> d;
    vector<int> p;
    Queue<int> Q;

public:
    AdjacencyList(int v);
    void addEdge(int src, int dest);
    void BFS(int s);
    void PRINTPATH(int s, int v);
    int getSize();
    int getDistance(int u);
}AL;

#endif // ADJACENCYLIST_H