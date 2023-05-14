#ifndef QUEUE_H
#define QUEUE_H

#include <list>
// Queue�� ���Ḯ��Ʈ�� �ٷ�� ���� ������
// list �ڷᱸ�� ���

using namespace std;

template<typename T>
class Queue 
{
private:
    list<T> q_data; // Queue �����͸� ������ ���� ����Ʈ

public:
    void enqueue(const T& value);   // Queue �Է��Լ�
    T dequeue();                    // Queue ����Լ�
    bool empty() const;             // ����ִ� ���� ��ȯ�Լ�
};

// Queue �Է��Լ�
template<typename T>
void Queue<T>::enqueue(const T& value) 
{
    q_data.push_back(value);
    // ���Ḯ��Ʈ push_back
}

// Queue ����Լ�
template<typename T>
T Queue<T>::dequeue() 
{
    if (q_data.empty()) 
        throw out_of_range("out of range");
    // ������� ��� ����ó��

    T frontValue = q_data.front();  // ���� ���� ������ ����
    q_data.pop_front();             // ���� ���� ������ ����
    return frontValue;              // ���� ���� ������ ��ȯ
}

// ����ִ� ���� ��ȯ�Լ�
template<typename T>
bool Queue<T>::empty() const 
{
    return q_data.empty(); // ����ִ� ���ι�ȯ
}

#endif