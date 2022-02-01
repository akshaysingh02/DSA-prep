//Concept of the circular array is used in this implementation
//The queues data structures is a list or collection with the restriction
//that insertion can be performed at one end (rear) and deletion can be performed at
//other end(front).
//some operations of queues are :- Enqueue, dequeue, front, IsEmpty
// All these must take constant time

//This is the array implimentation of the queue
//Circular imlementation of queue in c++
#include <iostream>
using namespace std;

#define MAX_SIZE 101 //maximum size of array that stores queue

class Queue
{
    int A[MAX_SIZE];
    int front;
    int rear;

public:
    //constructor set the front and rear as -1
    //we're assuming that for an empty queue front and rear should be -1

    Queue()
    {
        front = -1;
        rear = -1;
    }

    //To check whether the queue is empty or not
    bool IsEmpty()
    {
        return (front == -1 && rear == -1);
    }

    //TO check whether the queue is full or not
    bool IsFull()
    {
        if ((rear + 1) % MAX_SIZE == front)
        {
            return true;
        }
        else
            return false;
    }

    //Insert an element in queue at rear end
    void Enqueue(int x)
    {
        cout << "Enqueuing: " <<x<<endl;
        if (IsFull())
        {
            cout << "Error: Queue is Full" << endl;
            return;
        }
        if (IsEmpty())
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
        }
        A[rear] = x;
    }

    //Delete an element of queue from front end
    void Dequeue()
    {
        cout<<"Dequeuing"<<endl;
        if (IsEmpty())
        {
            cout << "Error: Queue is empty" << endl;
            return;
        }
        else if (rear == front)
        {
            front = rear = -1;
        }
        else
        {
            front = (front+1)%MAX_SIZE;
        }
    }

    //Return the element from the front of the queue
    int Front()
    {
        if(front == -1){
            cout<<"Error: Queue is empty"<<endl;
            return -1;
        }
        else{
            return A[front];
        }
    }

    //To print the queue from front to end;
    //This function is just for the test case
    //This is not the standard function for Queue implementation
    void Print()
    {
        //finding the number of elements in queue
        int count = (rear + MAX_SIZE - front)%MAX_SIZE+1;
        cout<<"Queue   : ";
        for (int i=0;i<count;i++){
            cout<<A[(front+i)%MAX_SIZE]<<" ";
        }
        cout<<"\n\n";
    }
};

int main()
{
    /*
    Driver code to test the implementation 
    printing the element after each Enqueue and dequeue
    */

   Queue Q;
    Q.Enqueue(2);  Q.Print();  
   Q.Enqueue(4);  Q.Print();  
   Q.Enqueue(6);  Q.Print();
   Q.Dequeue();	  Q.Print();
   Q.Enqueue(8);  Q.Print();
}
//In circiular array positions are defined as:-
//Next position -> (i+1)%N
//previous position -> (i+N-1)%N
//where N is the length of the array