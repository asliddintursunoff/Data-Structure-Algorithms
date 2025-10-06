#include <iostream>
using namespace std;


class DoubleNode{
    public:
        int value;
        DoubleNode* prev;
        DoubleNode* next;

        DoubleNode(int v){
            value = v ;
            prev = NULL;
            next = NULL;
        }

        

};

void traversing(DoubleNode* head){
    DoubleNode* temp = head;
    while(temp !=NULL){
        cout<<temp->value<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

void insert_beginning(DoubleNode* &head,int new_value){
    DoubleNode* new_node = new DoubleNode(new_value);
    if(head ==NULL){
        head = new_node;
        return;
    }
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}

void insert_end(DoubleNode* &head,int new_value){
    DoubleNode* newNode = new DoubleNode(new_value);
    if(head==NULL){
        head = newNode;
        return;
    }
    DoubleNode* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    
}

void insert(DoubleNode* &head,int new_value,int pos){
    DoubleNode* newNode = new DoubleNode(new_value);
    DoubleNode* temp = head;
    int count = 1;
    if(pos==0){
        insert_beginning(head,new_value);
        return;
    }
    while(count<=pos){
        count++;
        temp = temp->next;

        if (temp->next!=NULL){
            insert_end(head,new_value);
            return;
        }

    }

    
    newNode->next = temp;
    newNode->prev = temp->prev;
    temp->prev->next = newNode;


    
}

void delete_start(DoubleNode* &head) {
    if (head == nullptr) { 
        return;
    }

    DoubleNode* temp = head;

    if (head->next != nullptr) {
        head = head->next;     
        head->prev = nullptr;  
    } else {
        head = nullptr;
    }

    delete temp;
}


void delete_end(DoubleNode* &head){
    DoubleNode* temp = head;

    if(head == NULL){
        return;
    }
    if(head->next==NULL){
        delete head;
        head = NULL;
        return;

    }
    while(temp->next != NULL){
        temp = temp->next;
    }

    temp->prev->next = NULL;
    delete temp;
}

void delete_at_position(DoubleNode* &head,int pos){

    DoubleNode* temp = head;
    if(head == NULL){
        return;
    }
    if(pos == 0){
        delete_start(head);
        return;
    }
    for(int i=0;i<pos;i++){
        temp = temp->next;

        if(temp == NULL){
            return;
        }


        
    }
    if(temp->next == NULL){
            temp->prev->next = NULL;
            delete temp;
            
        }
    else{
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;}
}
int main(){

    DoubleNode* node1 = new DoubleNode(7);
    DoubleNode* node2 = new DoubleNode(2);
    DoubleNode* node3 = new DoubleNode(5);
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    
    DoubleNode* head = node1;

    traversing(head);

    insert_beginning( head,-2);
    traversing(head);

    insert_end( head,32);
    traversing(head);

    insert(head,0,6);
    traversing(head);

    delete_start(head);
    traversing(head);

    delete_end(head);
    traversing(head);

    delete_at_position(head,3);
    traversing(head);

}