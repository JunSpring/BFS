#include <fstream>
#include "AdjacencyList.h"

// size�� �ް� vector resize�ϴ� ������
bool readALFromFile(string fileName, AL& al);

int main()
{
    // graph ���� �� �ؽ�Ʈ���Ͽ��� �ε�
    AL graph(0);
    if (!readALFromFile("graph4.txt", graph))
        return 0;

    // graph���� 1�������� BFS ����
    graph.BFS(0);
    cout << "----- graph4 BFS print -----" << endl;
    // 1����忡�� 1����带 ������ ��� �������� path ���
    for (int i = 1; i < graph.getSize(); i++)
        graph.PRINT(0, i);

    return 0;
}

// �ؽ�Ʈ ������ �а� Edge�� �߰��ϴ� �Լ�
bool readALFromFile(string fileName, AL& al) 
{
    ifstream inputFile;
    inputFile.open(fileName);

    // ������ �� �� ���ٸ� false ��ȯ
    if (!inputFile.is_open()) 
        return false;

    // vertex�� ����
    int vertexCount;
    inputFile >> vertexCount;

    al = AL(vertexCount);

    for (int i = 0; i < vertexCount; i++) 
    {
        for (int j = 0; j < vertexCount; j++) 
        {
            int val;
            inputFile >> val;

            if (val == 1) 
            {
                al.addEdge(i, j); // Edge �߰�
            }
        }
    }

    inputFile.close();
    return true; // ������ ���� Edge �߰��� �����ϸ� true ��ȯ
}