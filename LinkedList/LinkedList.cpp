#include <iostream>
using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(int v){
            value = v;
            next = NULL;
        }
};
void traversing(Node *head){
    Node* temp  = head;
    while(temp!=NULL){
        cout<<temp->value<<" ->  ";
        temp = temp->next;

    }
    cout<<"NULL"<<endl;
}

void inserting_beginning(Node* &head,int value){
    Node *new_node = new Node(value);
    new_node->next = head;
    head = new_node;
 
}

void inserting_end(Node* &head, int value){

    Node* temp=head;
    if(head==NULL){
        inserting_beginning(head,value);
        return;
    }
    while(temp->next!=NULL and temp != NULL ){
        
        temp = temp->next;
    }
    Node* last_node = new Node(value);
    temp->next= last_node;
}

void insert(Node* &head,int postion,int value){

    Node *temp = head;
    
    if(postion == 0){

        inserting_beginning(head,value);
  
        return;
    }
    
    int i=0;
    while(i<(postion-1)){
        temp = temp->next;
        i++;

    }
    // if(postion-1>i){
    //     return;
    // }
    Node *new_node = new Node(value);
    new_node->next = temp->next;
    temp->next = new_node;
    
}


void delete_beginning(Node* &head){

    if(head==NULL){
        return; 
    }
    Node* temp = head;
    head = temp->next;
    delete temp;

}

void delete_end(Node* &head){
    Node* temp = head;

    if(temp == NULL){
        return;
    }
    if(temp->next ==NULL){
        delete temp;
        head = NULL;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }

    Node* last = temp->next;
    delete temp->next;
    temp->next = NULL;
}

void delete_position(Node* &head,int position){
    int k=0;
    Node* previous = head;

    if(position==0){
        delete_beginning(head);
        return;
    }
    while(k<(position-1)){
        previous = previous->next;
        k++;
    }

    Node* current = previous->next;
    previous->next = current->next;
    delete current;


}

void update(Node *head,int value,int position){
    Node* temp  = head;
    int count =0;

    while(count<position){
        count++;
        temp = temp->next;

    }
    temp->value = value;
}
int main(){
    
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    
    node1->next = node2;
    node2->next = node3;
    Node* head = node1;

    cout<<"Original list(traversing)"<<endl;
    traversing(head);

    cout<<"Inserting beginning (12)"<<endl;
    inserting_beginning(head,12);
    traversing(head);
    
    cout<<"Inserting at the end (42)"<<endl;
    inserting_end(head,42);
    traversing(head);

    cout<<"Inserting at the postion 0(-666)"<<endl;
    insert(head,0,-666);
    traversing(head);

    cout<<"deleting beginning"<<endl;
    delete_beginning(head);
    traversing(head);

    cout<<"deleting end"<<endl;
    delete_end(head);
    traversing(head);

    cout<<"deleting postion 1"<<endl;
    delete_position(head,1);
    traversing(head);

    cout<<"updating postion 1 element"<<endl;
    update(head,-99,1);
    traversing(head);

}