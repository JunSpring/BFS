#include <fstream>
#include "AdjacencyList.h"

// size를 받고 vector resize하는 생성자
bool readALFromFile(string fileName, AL& al);

int main()
{
    // graph 선언 및 텍스트파일에서 로드
    AL graph(0);
    if (!readALFromFile("graph4.txt", graph))
        return 0;

    // graph에서 1번노드부터 BFS 실행
    graph.BFS(0);
    cout << "----- graph4 BFS print -----" << endl;
    // 1번노드에서 1번노드를 제외한 모든 노드까지의 path 출력
    for (int i = 1; i < graph.getSize(); i++)
        graph.PRINT(0, i);

    return 0;
}

// 텍스트 파일을 읽고 Edge를 추가하는 함수
bool readALFromFile(string fileName, AL& al) 
{
    ifstream inputFile;
    inputFile.open(fileName);

    // 파일을 열 수 없다면 false 반환
    if (!inputFile.is_open()) 
        return false;

    // vertex수 저장
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
                al.addEdge(i, j); // Edge 추가
            }
        }
    }

    inputFile.close();
    return true; // 파일을 열고 Edge 추가에 성공하면 true 반환
}