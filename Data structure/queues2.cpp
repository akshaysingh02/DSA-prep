//This is linked list based implementation of Queue Data structure
//In this implementation we will make sure that for time complexcity of the program
//remains constant or O(1)
//Instead of head pointer we will declare two pointer to Node one Front and
//one Rear that will hold the address of the last node of the linked list
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *Front = NULL;
Node *Rear = NULL;

void Enqueue(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = NULL;

    if (Front == NULL && Rear == NULL)
    {
        Front = Rear = temp;
        return;
    }
    Rear->next = temp;
    Rear = temp;
}

void Dequeue()
{
    Node *temp = Front;
    if (Front == NULL)
    {
        cout << "Error: Queue Empty" << endl;
        return;
    }
    if (Front == Rear)
    {
        Front = Rear = NULL;
    }
    else
    {
        Front = Front->next;
    }
    delete temp;
}

bool IsEmpty()
{
    if (Front == NULL && Rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int front()
{
    if (Front == NULL)
    {
        printf("Queue is empty\n");
        return -1;
    }
    return Front->data;
}

void Print(){
    Node* temp = Front;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
	/* Drive code to test the implementation. */
	// Printing elements in Queue after each Enqueue or Dequeue 
	Enqueue(2); Print(); 
	Enqueue(4); Print();
	Enqueue(6); Print();
	Dequeue();  Print();
	Enqueue(8); Print();

    //These last 3 lines is just to test the front and Isempty function
    int f = front();
    int emp = IsEmpty();
    cout<<f<<" "<<emp<<endl;
}