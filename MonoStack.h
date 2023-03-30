#ifndef MONOSTACK_H
#define MONOSTACK_H

using namespace std;

template <typename T>
class MonoStack{
    public:
        MonoStack(int size); //default constructor
        MonoStack(int size, char o); //overloaded constructor
        ~MonoStack(); //destructor
        void push(T c, char o);
        T pop();
        T peek();
        bool isFull();
        bool isEmpty();
        int getSize();
        void printContent();
    private:
        char direction;
        int top;
        int maxSize;
        T* myArray;
};

#include "MonoStack.h"
#include <iostream>

template<typename T>
MonoStack<T>::MonoStack(int size){
    myArray = new double[size];
    direction = 'd'; //default MonoStack will be decreasing
    maxSize = size;
    top = -1; // set to -1 for preicrementing later
}

template <typename T>
MonoStack<T>::MonoStack(int size, char o){
    myArray = new double[size];
    direction = o;
    maxSize = size;
    top = -1; // set to -1 for preicrementing later
}

template <typename T>
MonoStack<T>::~MonoStack(){ 
    cout << "Garbage collection time." << endl;
    delete[] myArray;
}



// isFull and isEmpty methods to be used for error handling
template <typename T>
bool MonoStack<T>::isFull(){
    return (top == maxSize-1);
}

template <typename T>
bool MonoStack<T>::isEmpty(){
    return (top == -1);
}



template <typename T>
T MonoStack<T>::pop(){
    //check if stack is empty
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to pop");
    }
    return myArray[top--];
}

template <typename T>
T MonoStack<T>::peek(){
    //check if stack is empty
    if(isEmpty()){
        throw runtime_error("stack is empty, nothing to see here");
    }
    return myArray[top];
}

template <typename T>
void MonoStack<T>::push(T data, char o){
    if(isFull()){ //double size of the array if stack is full
        T* temp = new T[2*maxSize];
        for(int i = 0; i < maxSize; ++i){
            temp[i] = myArray[i];
        }
        maxSize *= 2;
        delete[] myArray;
        myArray = temp;
        myArray[++top] = data;
    }
    else if(isEmpty()){
        myArray[++top] = data;
    }
    else {
        o = tolower(o);
        if (o == 'd'){ //create a decreasing MonoStack
            while (data > peek()){
                pop();
                if(top == -1){
                    break;
                }
            }
            myArray[++top] = data;
        }
        else if (o == 'i'){ //create an increasing MonoStack
            while (data < peek()){
                pop();
                if(top == -1){
                    break;
                }
            }
            myArray[++top] = data;
        }
    }
}

#endif