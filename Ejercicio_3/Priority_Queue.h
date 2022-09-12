#include "Node.h"
#ifndef PRIORITY_QUEUE
#define PRIORITY_QUEUE 1

template <class T>
class Queue {
private:
    Node<T> *first;
    Node<T> *last;
    int quantity;
    Node<T> *searchPosition = NULL;
public:
    Queue() {
        first = NULL;
        last = NULL;
        quantity = 0;
    }

    void enqueue(T* pData, int pPriority=0) {
        auto *newNode = new Node<T>(pData, pPriority);
        if (this->quantity>0) {
            if(pPriority<this->first->getPriority()) {
                this->first->setNext(newNode);
                newNode->setPrevious(this->first);
                this->first=newNode;
            }
            else if(pPriority>=this->last->getPriority()){
                newNode->setNext(last);
                this->last->setPrevious(newNode);
                this->last = newNode;
            }
            else{
                searchPosition=this->first->getPrevious();

                while (searchPosition != NULL){
                    if (searchPosition->getPriority()>pPriority) {
                        newNode->setNext(searchPosition->getNext());
                        newNode->setPrevious(searchPosition);
                        searchPosition->getNext()->setPrevious(newNode);
                        searchPosition->setNext(newNode);
                        break;
                    }
                    else{
                        searchPosition= searchPosition->getPrevious();
                    }
                }
            }
        }
        else {
            this->first = newNode;
            this->last = newNode;
        }
        this->quantity++;
    }
    T* dequeue() {
        if(!this->isEmpty()){
            T* data = this->first->getData();
            if(this->first!=this->last){
                this->first=this->first->getPrevious();
                this->first->getNext()->setNext(NULL);
            }
            else{
                this->first=NULL;
                this->last=NULL;
            }
            this->quantity--;
            return data;
        }
    }

    T* front(){
        if(!this->isEmpty()){
            T* data = this->first->getData();
        }
    }

    bool isEmpty() {
        return !quantity;
    }
};
#endif