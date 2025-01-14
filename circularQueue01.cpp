#include<iostream>
#include<queue>
using namespace std;


class CircularQueue{
    int *arr;
    int front;
    int rear;
    int n;

    public:
    // Initialize your data structure.
    CircularQueue(int n){
        this -> n =n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        if((rear == (front-1) % (n - 1)) || (front == 0 && rear == n-1))
        {
            return false;
        }
        else if(front == -1) //first elememt
        {
            front = rear =0;
        }
        else if(rear == n-1 && front != 0)
        {
            rear = 0; 
        }
        else
        {
            rear++;
        }

        arr[rear] = value;
        return true;

    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        
        if(front == -1)
        {
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear)//single element
        {     
            front = rear = -1;
        }
        else if(front == n-1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        return ans;
    }
};