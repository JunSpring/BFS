#ifndef ADJACENCYLIST_H
#define ADJACENCYLIST_H

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include "Queue.h"

using namespace std;

// color 벡터에 저장할 enum
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
    AdjacencyList(const int& v);                    // size를 받고 vector resize하는 생성자
    void addEdge(const int& src, const int& dest);  // Edge를 추가하는 함수
    void BFS(const int& s);                         // BFS 함수
    void PRINT(const int& s, const int& v);         // path와 distance를 출력하는 함수
    bool PRINTPATH(const int& s, const int& v);     // path를 print하는 함수
    const int& getSize();                           // size를 반환하는 함수
    const int& getDistance(const int& u);           // distance를 반환하는 함수
}AL;

#endif // ADJACENCYLIST_H