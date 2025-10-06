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

void insert_beginning(Node* &head,int value){
    Node* newNode = new Node(value);
    if(head == NULL){
        head = newNode;
        newNode->next = newNode;
        return;
    }
    Node* temp = head;

    while(temp->next != head){
        temp = temp->next;
    }

    
    newNode->next = head;
    temp->next = newNode;
    head = newNode;

    
    
}

void insert_end(Node* &head,int value){
    Node* newNode = new Node(value);

    if(head==NULL){
        head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

}


void deletion_beginning(Node* &head){
    if(head == NULL){
        return;
    }
    if(head->next == head){
        delete head;
        return;
    }

    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }

    Node* node = head;
    
    temp->next =head->next;
    
    head = head->next;
    delete node;

}

void delete_end(Node* head){
    if(head == NULL){
        return;
    }
    if(head->next == head){
        delete head;
        return;
    }

    Node* temp = head;
    while(temp->next->next != head){
        temp = temp->next;
    }

    delete temp->next;
    temp->next = head;
    
}
int main(){
    Node* node1 = new Node(4);
    Node* node2 = new Node(-9);
    Node* node3 = new Node(0);

    node1->next = node2;
    node2->next= node3;
    node3->next= node1;



    Node*head = node1;
    traversing(head);

    insert_beginning(head,8);
    traversing(head);

    insert_end(head,77);
    traversing(head);

    deletion_beginning(head);
    traversing(head);


    delete_end(head);
    traversing(head);


}