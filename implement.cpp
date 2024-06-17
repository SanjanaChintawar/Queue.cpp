#include<iostream>
#include<queue>
using namespace std;

class Queue{
    private:
        int *arr;
        int size;
        int qfront;
        int rear;
    public:
        Queue(int size){
            this -> size = size;
            arr = new int[size];
            qfront = 0;
            rear = 0;
        }

        // push in queue
        void push(int data){
            if(rear == size){
                cout<<"Queue if full"<<endl;
            }
            else{
                arr[rear] = data;
                rear++;
                cout<<"Data pushed successfuly"<<endl;
            }
        }

        // pop in queue
        int pop(){
            if(qfront == rear){
                cout<<"Queue is underflow"<<endl;
                return -1;
            }
            else{
                int ans = arr[qfront];
                arr[qfront] = -1;
                qfront++;

                if(qfront == rear){
                    qfront = 0;
                    rear = 0;
                }
                return ans;
            }
        }

        // front element
        int front(){
            if(qfront == rear){
                return -1;
            }
            else{
                return arr[qfront];
            }
        }

        // empty or not
        bool empty(){
            if(qfront == rear){
                return true;
            }
            else{
                return false;
            }
        }

};

int main(){

    Queue q(5);
    q.push(10);
    q.push(20);
    cout<<"front element: "<<q.front()<<endl;
    cout<<"poped element: "<<q.pop()<<endl;
    cout<<"front element: "<<q.front()<<endl;
    cout<<"poped element: "<<q.pop()<<endl;
    q.push(20);
    cout<<"poped element: "<<q.pop()<<endl;
    cout<<"front element: "<<q.front()<<endl;

}