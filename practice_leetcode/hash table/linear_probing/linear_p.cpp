#include <iostream>
using namespace std;

const int SIZE = 10;

int hash_t(int key)
{
    return key%SIZE;
}

//This probe function is looking for the free space
int probe(int H[],int key){

    int index = hash_t(key);
    int i = 0;
    while(H[(index+i)%SIZE]!=0){
        i++;
    }
    return (index+i)%SIZE;

}

void insert(int HT[],int key){
    int index = hash_t(key);

    if(HT[index] != 0){
        index = probe(HT,key);
    }
    HT[index] = key;
}

//This probe function is looking for the key
int search(int HT[],int key){
    int index = hash_t(key);

    int i =0;
    while(HT[(index+i)%SIZE]!=key){
        i++;
    }
    return (index+i)%SIZE;

}

int main(){

    int HT[10] = {0}; //This will initialize an array with values 0 at all indexes
    insert(HT, 20);
    insert(HT, 12);   
    insert(HT, 45);   
    insert(HT, 55);   

    cout<<search(HT,45);


    return 0;
}