#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(const int& size) 
{
    this->size = size; // size 저장

    // vector resize
    Adj.resize(size);
    color.resize(size);
    d.resize(size);
    p.resize(size);
}

// Edge를 추가하는 함수
void AdjacencyList::addEdge(const int& src, const int& dest) 
{
    // Edge 추가
    Adj[src].push_back(dest);
    Adj[dest].push_back(src);
}

// BFS 함수
void AdjacencyList::BFS(const int& s)
{
    // 강의자료와 동일

    for (int u = 0; u < size; u++)
    {
        if (u == s)
            continue;

        color[u] = WHITE;
        d[u] = INT_MAX;
        p[u] = NULL;
    }

    color[s] = GRAY;
    d[s] = 0;
    p[s] = NULL;
    Q.enqueue(s);

    while (!Q.empty())
    {
        int u = Q.dequeue();
        
        for (const int& v : Adj[u])
        {
            if (color[v] == WHITE)
            {
                color[v] = GRAY;
                d[v] = d[u] + 1;
                p[v] = u;
                Q.enqueue(v);
            }
        }

        color[u] = BLACK;
    }
}

// path와 distance를 출력하는 함수
void AdjacencyList::PRINT(const int& s, const int& v)
{
    if(PRINTPATH(s, v))                         // path 출력에 성공했다면
        cout << ": " << getDistance(v) << endl; // distance 출력
}

// path를 print하는 함수
bool AdjacencyList::PRINTPATH(const int& s, const int& v) 
{
    // 강의자료와 동일

    if (v == s)
    {
        cout << s;
        return true; // path가 존재하다면 true 반환
    }
    else if (p[v] == NULL)
    {
        cout << "no path from " << s << " to " << v << " exists" << endl;
        return false; // path가 없다면 false 반환
    }
    else
    {
        PRINTPATH(s, p[v]);
        cout << " -> " << v;
    }
}

// size를 반환하는 함수
const int& AdjacencyList::getSize()
{
    return size; // size 반환
}

// distance를 반환하는 함수
const int& AdjacencyList::getDistance(const int& u)
{
    return d[u]; // distance 반환
}