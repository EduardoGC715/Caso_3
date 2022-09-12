//isEmpty, enqueue, dequeue, front.
#include <iostream>
#include "stack.h"
using namespace std;

template <class T>
class Queue {
private:
    Stack<T>* queueStack_Main;
    Stack<T>* queueStack_Aux;

public:
    Queue() {
        queueStack_Main = NULL;
        queueStack_Main = new Stack<T>();
        queueStack_Aux = new Stack<T>();

    }
    void enqueue(T pValue) {
        queueStack_Main->push(pValue);
    }

    T dequeue() {
        T result;
        while (!queueStack_Main->isEmpty()) {
            queueStack_Aux->push(queueStack_Main->pop());
        }
        result=queueStack_Aux->pop();
        while (!queueStack_Aux->isEmpty()) {
            queueStack_Main->push(queueStack_Aux->pop());
        }
        return result;
    }

    T front() {
        T result;
        while (!queueStack_Main->isEmpty()) {
            queueStack_Aux->push(queueStack_Main->pop());
        }
        result=queueStack_Aux->top();
        while (!queueStack_Aux->isEmpty()) {
            queueStack_Main->push(queueStack_Aux->pop());
        }
        return result;
    }

    bool isEmpty() {
        return queueStack_Main->isEmpty();
    }
};

int main() {
    auto* queue_prueba = new Queue<int>();
    queue_prueba->enqueue(1);
    queue_prueba->enqueue(2);
    queue_prueba->enqueue(3);
    queue_prueba->enqueue(4);

    cout<<queue_prueba->front()<<endl;
    cout<<queue_prueba->dequeue()<<endl;
    cout<<queue_prueba->dequeue()<<endl;
    cout<<queue_prueba->dequeue()<<endl;
    cout<<queue_prueba->front()<<endl;
    cout<<queue_prueba->dequeue()<<endl;

    if(queue_prueba->isEmpty()){
        cout<<"esta vacia."<<endl;
    }
    else{
        cout<<"no esta vacia."<<endl;
    }

}
