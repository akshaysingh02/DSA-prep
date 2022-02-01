//This is a very famous question in number theory
//Modular exponentiaiton-using recursion


#include<iostream>
using namespace std;

int modexpo(int x,int n,int y){
    if (n==0){
        return 1;
    }
    int temp = modexpo(x,n/2,y);

    if (n%2==0){
        return (temp*temp)%y;
    }
    return (x*temp*temp)%y;
}

int main(){
    int x = modexpo(5,3,7);
    cout<<x;
}