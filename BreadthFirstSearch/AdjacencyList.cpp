#include "AdjacencyList.h"

// size�� �ް� vector resize�ϴ� ������
AdjacencyList::AdjacencyList(const int& size) 
{
    this->size = size; // size ����

    // vector resize
    Adj.resize(size);
    color.resize(size);
    d.resize(size);
    p.resize(size);
}

// Edge�� �߰��ϴ� �Լ�
void AdjacencyList::addEdge(const int& src, const int& dest) 
{
    // Edge �߰�
    Adj[src].push_back(dest);
}

// BFS �Լ�
void AdjacencyList::BFS(const int& s)
{
    // �����ڷ�� ����

    for (int u = 0; u < size; u++)
    {
        if (u == s)
            continue;

        color[u] = WHITE;
        d[u] = INT_MAX;
        p[u] = -1;
    }

    color[s] = GRAY;
    d[s] = 0;
    p[s] = -1;
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

// path�� distance�� ����ϴ� �Լ�
void AdjacencyList::PRINT(const int& s, const int& v)
{
    if(PRINTPATH(s, v))                         // path ��¿� �����ߴٸ�
        cout << ": " << getDistance(v) << endl; // distance ���
}

// path�� print�ϴ� �Լ�
bool AdjacencyList::PRINTPATH(const int& s, const int& v) 
{
    // �����ڷ�� ����

    if (v == s)
    {
        cout << s + 1;
        return true; // path�� �����ϴٸ� true ��ȯ
    }
    else if (p[v] == -1)
    {
        cout << "no path from " << s + 1 << " to " << v + 1 << " exists" << endl;
        return false; // path�� ���ٸ� false ��ȯ
    }
    else
    {
        if (PRINTPATH(s, p[v]))
            cout << " -> " << v + 1;
    }
}

// size�� ��ȯ�ϴ� �Լ�
const int& AdjacencyList::getSize()
{
    return size; // size ��ȯ
}

// distance�� ��ȯ�ϴ� �Լ�
const int& AdjacencyList::getDistance(const int& u)
{
    return d[u]; // distance ��ȯ
}