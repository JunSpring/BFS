#include <fstream>
#include "AdjacencyList.h"

bool readALFromFile(string fileName, AL& al);

int main()
{
    AL graph1(0);
    if (!readALFromFile("graph1.txt", graph1))
        return 0;

    graph1.BFS(1);
    for (int i = 2; i < graph1.getSize(); i++)
        graph1.PRINT(1, i);

    return 0;
}

bool readALFromFile(string fileName, AL& al) 
{
    ifstream inputFile;
    inputFile.open(fileName);

    if (!inputFile.is_open()) {
        cout << "Failed to open file." << endl;
        return false;
    }

    int vertexCount;
    inputFile >> vertexCount;

    al = AL(vertexCount);

    for (int i = 0; i < vertexCount; i++) {
        for (int j = 0; j < vertexCount; j++) {
            int val;
            inputFile >> val;

            if (val == 1) {
                al.addEdge(i, j);
            }
        }
    }

    inputFile.close();
    return true;
}