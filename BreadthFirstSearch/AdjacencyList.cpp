#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(const int& size) 
{
    this->size = size;

    Adj.resize(size);
    color.resize(size);
    d.resize(size);
    p.resize(size);
}

void AdjacencyList::addEdge(const int& src, const int& dest) 
{
    Adj[src].push_back(dest);
    Adj[dest].push_back(src);
}

void AdjacencyList::BFS(const int& s)
{
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

void AdjacencyList::PRINT(const int& s, const int& v)
{
    if(PRINTPATH(s, v))
        cout << ": " << getDistance(v) << endl;
}

bool AdjacencyList::PRINTPATH(const int& s, const int& v) 
{
    if (v == s)
    {
        cout << s;
        return true;
    }
    else if (p[v] == NULL)
    {
        cout << "no path from " << s << " to " << v << " exists" << endl;
        return false;
    }
    else
    {
        PRINTPATH(s, p[v]);
        cout << " -> " << v;
    }
}

const int& AdjacencyList::getSize()
{
    return size;
}

const int& AdjacencyList::getDistance(const int& u)
{
    return d[u];
}