#include "AdjacencyList.h"

AdjacencyList::AdjacencyList(int size) 
{
    this->size = size;

    Adj.resize(size);
    color.resize(size);
    d.resize(size);
    p.resize(size);
}

void AdjacencyList::addEdge(int src, int dest) 
{
    Adj[src].push_back(dest);
    Adj[dest].push_back(src);
}

void AdjacencyList::BFS(int s)
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
        
        for (const auto& v : Adj[u])
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

void AdjacencyList::PRINTPATH(int s, int v) 
{
    if (v == s)
        cout << s << ' ';
    else if (p[v] == NULL)
        cout << "no path from " << s << " to " << v << "exists" << endl;
    else
    {
        PRINTPATH(s, p[v]);
        cout << v << " -> ";
    }
}

int AdjacencyList::getSize()
{
    return size;
}

int AdjacencyList::getDistance(int u)
{
    return d[u];
}