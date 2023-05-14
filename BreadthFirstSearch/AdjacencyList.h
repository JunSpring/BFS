#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include "Queue.h"

using namespace std;

// color ���Ϳ� ������ enum
enum Color
{
    WHITE,
    GRAY,
    BLACK
};

// AdjacencyList Class
typedef class AdjacencyList 
{
private:
    int size;               // AdjacencyList size
    vector<list<int>> Adj;  // AdjacencyList
    vector<Color> color;    // color vector
    vector<int> d;          // distance vector
    vector<int> p;          // pi vector
    Queue<int> Q;           // Queue

public:
    AdjacencyList(const int& v);                    // size�� �ް� vector resize�ϴ� ������
    void addEdge(const int& src, const int& dest);  // Edge�� �߰��ϴ� �Լ�
    void BFS(const int& s);                         // BFS �Լ�
    void PRINT(const int& s, const int& v);         // path�� distance�� ����ϴ� �Լ�
    bool PRINTPATH(const int& s, const int& v);     // path�� print�ϴ� �Լ�
    const int& getSize();                           // size�� ��ȯ�ϴ� �Լ�
    const int& getDistance(const int& u);           // distance�� ��ȯ�ϴ� �Լ�
}AL;

#endif // ADJACENCYLIST_H