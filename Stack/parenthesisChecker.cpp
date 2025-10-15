#include <iostream>
using namespace std;
struct StackForm
{
    int top=-1;
    int size;
    char *arr;

    StackForm(int size){
        this->size = size;
        this->arr= new char[size];
    }
    ~StackForm(){
        delete []arr; 
    }

};
class Stack{
    StackForm *st;
    public:
        Stack(StackForm *st){this->st = st;}


        bool isEmpty(){
            if(st->top==-1){return true;}
            return false;
        }
        bool isFull(){
            if(st->top==st->size-1){
                return true;
            }return false;
        }
        void push(char val){
            if(isFull()){
                cout<<"You cannot push StackForm is full!"<<endl;
                return;
            }
            st->top++;
            st->arr[st->top] = val;

        }
        void pop(){
            if(isEmpty()){
                cout<<"You cannot pop StackForm is empty!"<<endl;
                return;
            }
            st->top--;
        }
        
        void Display(){
            
            for(int i=st->top;i>-1;i--){
                cout<<st->arr[i]<<" ";
            }
        }
        //parenthesis chekcer function +_+_+_+_+_+_++__+_+_+_++_+
    bool check_parenthesis(string equation){
        for(int i =0;i<equation.length();i++){
            if(equation[i]=='('){
                push('(');
            }
            else if(equation[i]==')'){
                if(isEmpty()){return false;}
                pop();
            }
            Display();
            cout<<endl;
        }
        if(isEmpty()){return true;}
        return false;
    }
};

int main(){
    StackForm *obj = new StackForm(5);
    Stack stack(obj);
    
    stack.Display();
    bool result = stack.check_parenthesis("((3+5)∗(2−1))/(4+(6∗2))");
    if(result){
        cout<<"correct"<<endl;
    }else{
        cout<<"inncorrect"<<endl;
    }
}