#ifndef QUEUE_H
#define QUEUE_H

#include <list>

using namespace std;

template<typename T>
class Queue 
{
private:
    list<T> m_data;

public:
    void enqueue(const T& value);
    T dequeue();
    T& front();
    bool empty() const;
};

template<typename T>
void Queue<T>::enqueue(const T& value) 
{
    m_data.push_back(value);
}

template<typename T>
T Queue<T>::dequeue() 
{
    if (m_data.empty()) 
        throw out_of_range("out of range");

    T frontValue = m_data.front();
    m_data.pop_front();
    return frontValue;
}

template<typename T>
T& Queue<T>::front() 
{
    if (m_data.empty()) 
        throw out_of_range("out of range");

    return m_data.front();
}

template<typename T>
bool Queue<T>::empty() const 
{
    return m_data.empty();
}

#endif