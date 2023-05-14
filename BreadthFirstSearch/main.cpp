#include <fstream>
#include "AdjacencyList.h"

// �ؽ�Ʈ ������ �а� Edge�� �߰��ϴ� �Լ�
bool readALFromFile(string fileName, AL& al);

int main()
{
    // graph ���� �� �ؽ�Ʈ���Ͽ��� �ε�
    AL graph1(0);
    if (!readALFromFile("graph1.txt", graph1))
        return 0;

    // graph���� 1�������� BFS ����
    graph1.BFS(1);
    cout << "----- graph1 BFS print -----" << endl;
    // 1����忡�� 1����带 ������ ��� �������� path ���
    for (int i = 2; i < graph1.getSize(); i++)
        graph1.PRINT(1, i);

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