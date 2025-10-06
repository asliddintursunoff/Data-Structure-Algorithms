#include <iostream>
using namespace std;

class DoubleNode{
    public:
        int value;
        DoubleNode* next;
        DoubleNode* prev;

        DoubleNode(int v){
            value = v;
            prev = NULL;
            next = NULL;
        }


        void traversing(){
            DoubleNode* temp = this;

            while(temp != NULL){
                cout<<temp->value<<"--";
                temp = temp->next;
            }
            cout<<"NULL"<<endl;
        }


        
};
void reverse(DoubleNode* &head){
            
            if(head==NULL){
                return;
            }
            DoubleNode* ptr1 = head;
            DoubleNode* ptr2 = ptr1->next;
            ptr1->next =NULL;
            ptr1->prev = ptr2;

            while(ptr2!=NULL){
                ptr1 = ptr2;
                ptr2 = ptr2->next;
                ptr1->next = ptr1->prev;
                ptr1->prev = ptr2;
            }

            head = ptr1;
        }
int main(){

    DoubleNode* node1 = new DoubleNode(7);
    DoubleNode* node2 = new DoubleNode(2);
    DoubleNode* node3 = new DoubleNode(5);
    DoubleNode* node4 = new DoubleNode(9);
    DoubleNode* node5 = new DoubleNode(-13);
    DoubleNode* node6 = new DoubleNode(0);
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = node4;
    node4->prev = node3;
    node4->next = node5;
    node5->prev = node4;
    node5->next = node6;
    node6->prev = node5;
    DoubleNode* head = node1;

    head->traversing();
    reverse(head);
    head ->traversing();
}