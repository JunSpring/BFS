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
    AdjacencyList(const int& v);
    void addEdge(const int& src, const int& dest);
    void BFS(const int& s);
    void PRINT(const int& s, const int& v);
    bool PRINTPATH(const int& s, const int& v);
    const int& getSize();
    const int& getDistance(const int& u);
}AL;

#endif // ADJACENCYLIST_H