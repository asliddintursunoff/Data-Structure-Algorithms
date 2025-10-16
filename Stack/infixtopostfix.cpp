#include <iostream>

using namespace std;
struct Stack{
    int size;
    int top=-1;
    char *arr;
    Stack(int size){
        this->size = size;
        arr = new char[size];

    }    
};

class Infix{
    string expression;
    Stack *stack;
    public:
        Infix(string expression){
            this->expression = expression;
            stack = new Stack(expression.length());
        }
        
        bool isOperand(char x){
            if(x=='+' || x=='-'||x == '*'|| x=='/'){
                return false;
            }
            else{
                return true;
            }
        }

        int presidence(char x){
            if(x=='+' || x=='-'){
                return 1;
            }
            else if (x == '*'||x=='/')
            {
                return 2;
            }
            else if (x == '^')
            {
                return 3;
            }
            return 0;
        }

        void infixToPostfix(){
            string result="";
            cout<<result<<endl;
            for(int i=0;i<expression.length();i++){
                if (expression[i] == ' ') continue;

                if(isOperand(expression[i])){
                    result +=expression[i];
                    
                }
                else{
                    int p =presidence(expression[i]);
                    if(stack->top==-1){
                        stack->top++;
                        stack->arr[stack->top] = expression[i];
                    }
                    
                    else{
                            
                            while(stack->top !=-1 && p<=presidence(stack->arr[stack->top]) ){
                                
                                result += stack->arr[stack->top];
                                stack->top --;   
                                // p = presidence(stack->arr[stack->top]);

                            }
                            stack->top++;
                            stack->arr[stack->top] = expression[i];
                        }
                    
                    
                }
            }
            while(stack->top!=-1){
                result += stack->arr[stack->top];
                stack->top--;
            }
            cout<<result<<endl;
        }

};
int main(){
  
    Infix ex("- a + b * c + d * e ^ f");
    ex.infixToPostfix();
    
}