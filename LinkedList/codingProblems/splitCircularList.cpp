#include <iostream>
using namespace std;


class Node{
    public:
        int value;
        Node* next;
        
        Node(int v){
            value = v;
        }
};

void traversing(Node* &head){
    Node* temp = head;
    do{
        cout<<temp->value<<"->";
        temp = temp->next;
    }while(temp != head);
    cout<<endl;
}

void splitting_middle(Node* &head){
    Node* ptr1 = head;
    Node* ptr2 = head;

    while(ptr2->next != head && ptr2->next->next != head){
        ptr1 = ptr1->next;
        ptr2 = ptr2->next->next;
     
    }
    
    

    if(ptr2->next->next == head){
        ptr2 = ptr2->next;
    }
    Node* head2 = ptr1->next;
    ptr2->next = head2;
    ptr1->next = head;

    traversing(head);
    traversing(head2);

}
int main(){
    Node* node1 = new Node(4);
    Node* node2 = new Node(-9);
    Node* node3 = new Node(0);
    Node* node4 = new Node(7);
    Node* node5 = new Node(77);

    node1->next = node2;
    node2->next= node3;
    node3->next= node4;
    node4->next = node5;
    node5->next = node1;



    Node*head = node1;
    traversing(head);

    splitting_middle(head);

}