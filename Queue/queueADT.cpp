#include <iostream>
using namespace std;

struct queueADT
{
    int size;
    int front = -1,rear =-1;
    int *arr;

    queueADT(int size){
        this->size = size;
        arr = new int(size);
    }
};

class Queue{
    
    queueADT* queue;
    public:
        Queue(queueADT* &queue){
            this->queue = queue;

        }
        
        bool isFull(){
            if(queue->rear == queue->size-1){
                return true;
            }
            else{return false;}
        }

        bool isEmpty(){
            if(queue->front == queue->rear){return true;}
            else{return false;}

        }

        void enQueue(int val){
            if(isFull()){cout<<"Queue is full"<<endl;return;}
            else{
                queue->arr[++queue->rear] = val;
            }
        }
        void deQueue(){
            if(isEmpty()){
                cout<<"Queue is empty\nYou cannot delete it."<<endl;
                return;
            }
            else{
                queue->front++;
            }
        }

        void first(){
            if(isEmpty()){return;}

            cout<< queue->arr[1+queue->front]<<endl;
        }

        void last(){
            if(isEmpty()){return;}
            cout<<queue->arr[queue->rear];
        }

        void Display(){
            for(int i = queue->front+1; i<=queue->rear;i++){
                cout<<queue->arr[i]<<" ";
            }
            cout<<endl;
        }
        
};


int main(){
    queueADT* obj = new queueADT(8);
    Queue queue(obj);

    cout<<queue.isEmpty()<<endl;
    queue.enQueue(8);
    queue.enQueue(2);
    queue.enQueue(5);
    queue.Display();
    queue.deQueue();
    queue.Display();
    cout<<queue.isEmpty()<<endl;
}
