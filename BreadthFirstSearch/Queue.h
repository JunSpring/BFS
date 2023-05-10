#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& item) : data(item), next(nullptr) {}
    };
    Node* head;
    Node* tail;
    int count;
public:
    Queue() : head(nullptr), tail(nullptr), count(0) {}
    ~Queue();
    void enqueue(const T& item);
    T dequeue();
    bool isEmpty();
    int size();
};

template <typename T>
Queue<T>::~Queue() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::enqueue(const T& item) {
    Node* newNode = new Node(item);
    if (tail == nullptr) {
        head = newNode;
    }
    else {
        tail->next = newNode;
    }
    tail = newNode;
    count++;
}

template <typename T>
T Queue<T>::dequeue() {
    if (head == nullptr) {
        throw out_of_range("Queue is empty.");
    }
    T data = head->data;
    Node* temp = head;
    head = head->next;
    delete temp;
    count--;
    if (head == nullptr) {
        tail = nullptr;
    }
    return data;
}

template <typename T>
bool Queue<T>::isEmpty() {
    return count == 0;
}

template <typename T>
int Queue<T>::size() {
    return count;
}

#endif // QUEUE_H