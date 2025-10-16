#include <iostream>
using namespace std;

struct queueADT
{
    int size;
    int front = 0,rear =0;
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
            if((queue->rear+1)%queue->size == queue->front){
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
                queue->rear = (queue->rear+1)%queue->size;
                queue->arr[queue->rear] = val;
            }
        }
        void deQueue(){
            if(isEmpty()){
                cout<<"Queue is empty\nYou cannot delete it."<<endl;
                return;
            }
            else{
                queue->front = (queue->front+1)%queue->size;
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
            if(isEmpty()){
                cout << "Queue is empty" << endl;
                return;
            }

            int i = (queue->front + 1) % queue->size;
            while(i != (queue->rear + 1) % queue->size){
                cout << queue->arr[i] << " ";
                i = (i + 1) % queue->size;
            }
            cout << endl;
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
