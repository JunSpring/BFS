#ifndef QUEUE_H
#define QUEUE_H

#include <list>

using namespace std;

template<typename T>
class Queue 
{
private:
    list<T> q_data;

public:
    void enqueue(const T& value);
    T dequeue();
    T& front();
    bool empty() const;
};

template<typename T>
void Queue<T>::enqueue(const T& value) 
{
    q_data.push_back(value);
}

template<typename T>
T Queue<T>::dequeue() 
{
    if (q_data.empty()) 
        throw out_of_range("out of range");

    T frontValue = q_data.front();
    q_data.pop_front();
    return frontValue;
}

template<typename T>
T& Queue<T>::front() 
{
    if (q_data.empty()) 
        throw out_of_range("out of range");

    return q_data.front();
}

template<typename T>
bool Queue<T>::empty() const 
{
    return q_data.empty();
}

#endif