//This is the basic implimentation of stack not the ideal implimentation that we use. 
//Stack implementation using array
#include<iostream>
using namespace std;

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1; // for empty stack

void push(int x){
    if (top == MAX_SIZE -1){
        cout<<"Error : Stack overflow"<<endl;
        return;
    }
    else{
    top++;
    A[top] = x;
    }
}

void pop(){
    if(top==-1){
        cout<<"Error: Stack underflow"<<endl;
        return;
    }
 top--;
}

void IsEmpty(){ // we will normally use bool data type
    if(top==-1){
        // return true;
        cout<<"stack is empty"<<endl;
    }
    else{
        // return false;
        cout<<"stack is not empty"<<endl;
    }
}

int Top(){
    return A[top];
}

void print(){
    cout<<"stack : ";
    for(int i = 0;i<=top; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){

    push(2); print();
    push(4); print();
    push(7); print();
    pop(); print();
    push(3); print();
    push(12); print();
    IsEmpty();

}