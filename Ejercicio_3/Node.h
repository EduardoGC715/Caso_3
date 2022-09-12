#include <iostream>

#ifndef NODE

#define NODE 1

using namespace std;

template <class T>
class Node {
private:
    T *data;
    int priority;
    Node *next;
    Node *previous;

public:
    Node() {
        priority=NULL;
        data = NULL;
        next = NULL;
        previous=NULL;
    }

    Node(T *pData, int pPriority=0) {
        this->data = pData;
        priority=pPriority;
        next = NULL;
        previous=NULL;
    }

    int getPriority() {
        return priority;
    }

    T* getData() {
        return data;
    }

    Node* getNext() {
        return next;
    }

    Node* getPrevious() {
        return previous;
    }

    void setNext(Node *pValue) {
        this->next = pValue;
    }

    void setPrevious(Node *pValue) {
        this->previous = pValue;
    }

};

#endif
