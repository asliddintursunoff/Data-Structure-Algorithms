#include <iostream>
using namespace std;

struct Stack
{
    int top;
    int size;
    int *arr;
};


void creatingStack(Stack* &st){
    //cout<<"Enter a size: ";
    //cin>>st->size;
    st->size = 6;
    st->top = -1;
    st->arr = new int[st->size];

}

void Display(Stack *st){
    for(int i=st->top;i>=0;i--){
        cout<<st->arr[i]<<endl;
    }
    cout<<endl;
}

void push(Stack* &st,int value){
    if(st->top == st->size-1){
        cout<<"stack is full"<<endl;
        return;
    }
    (st->top)++;
    st->arr[st->top] = value;

}

void pop(Stack* &st){
    if(st->top == -1){
        cout<<"Stack is already empty"<<endl;
        return;
    }

    st->top--;
}
int peek(Stack* st, int pos) {
    int index = st->top - pos + 1;
    if (index < 0 || index > st->top) {
        cout << "Invalid position" << endl;
        return -1;
    }
    return st->arr[index];
}
bool isEmpty(Stack *st){
    if(st->top == -1){
        return true;
    }
    return false;
}


bool isFULL(Stack *st){
    if(st->top == st->size-1){
        return true;
    }
    return false;
}

int stackTop(Stack *st){
    if(!isEmpty(st)){

        return st->arr[st->top];
    }
    return -1;
}

int main(){
    Stack* st1 = new Stack();
    creatingStack(st1);
    push(st1,4);
   
    push(st1,2);
    push(st1,6);
    push(st1,7);
    push(st1,5);
    push(st1,32);

    
    // pop(st1);
   
    Display(st1);

    cout<<"element: "<<peek(st1,0)<<endl;
}