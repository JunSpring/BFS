#ifndef QUEUE_H
#define QUEUE_H

#include <list>
// Queue를 연결리스트로 다루면 좋기 때문에
// list 자료구조 사용

using namespace std;

template<typename T>
class Queue 
{
private:
    list<T> q_data; // Queue 데이터를 저장할 연결 리스트

public:
    void enqueue(const T& value);   // Queue 입력함수
    T dequeue();                    // Queue 출력함수
    bool empty() const;             // 비어있는 여부 반환함수
};

// Queue 입력함수
template<typename T>
void Queue<T>::enqueue(const T& value) 
{
    q_data.push_back(value);
    // 연결리스트 push_back
}

// Queue 출력함수
template<typename T>
T Queue<T>::dequeue() 
{
    if (q_data.empty()) 
        throw out_of_range("out of range");
    // 비어있을 경우 예외처리

    T frontValue = q_data.front();  // 가장 앞의 데이터 저장
    q_data.pop_front();             // 가장 앞의 데이터 삭제
    return frontValue;              // 가장 앞의 데이터 반환
}

// 비어있는 여부 반환함수
template<typename T>
bool Queue<T>::empty() const 
{
    return q_data.empty(); // 비어있는 여부반환
}

#endif