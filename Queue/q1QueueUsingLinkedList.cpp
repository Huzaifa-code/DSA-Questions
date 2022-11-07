// Consider you are given a link list implementation SList, which has defined operations addAtBeg(), 5
// removeFront() and getSize(). These operations have usual functionality as name suggests with
// required parameters and return value. You are not allowed to make any change in SList
// implementation. Using SList , you are required to implement a Queue. Write code fragments for this
// task. ( Hint. You can use multiple instance of SList)

#include<iostream>
using namespace std;

//Linked List code :
struct node{
    int data;
    node* next;
};

class LinkedList{
    node *first;
    int count;

    public:
        LinkedList(){
            count = 0;
            first = NULL;
        }

        void addAtBeg(int);
        int getSize();
        int removeFront();
        void print();
};

void LinkedList::addAtBeg(int d){
    node *temp = new node;

    temp->data = d;

    if(first == NULL){
        first = temp;
    }else {
        temp->next = first;
    }

    first = temp;
}

int LinkedList::removeFront(){
   
    if(first == NULL){
        return 0;
    }

    node *temp = first;
    first = first->next;

    int d = temp->data;

    delete temp;
    return d;

}

int LinkedList::getSize(){
    node *t;
    count = 0;
    t = first;

    while(t != NULL){
        count++;
        t = t->next;
    }

    return count;
}

void LinkedList::print(){
    node *temp = first;

    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}
//  ------------- x ------ LinkedList -------- x -------------------------


// ---------------------------- Queue ------------------------------------
class Queue{

    LinkedList l;

    public:

        // Entry Insert Queue
        void enqueue(int x){
            l.addAtBeg(x);
        }

        void dequeue(){
            if(l.getSize() == 0){
                cout<<"Queue is empty"<<endl;
                return;
            }else{
                LinkedList l2;
                
                while(l.getSize() != 1){
                    
                    l2.addAtBeg(l.removeFront());
                   
                }

                l = l2;
            }

        }

        int sizeOfQueue(){
            return l.getSize();
        }

};
// -------------x-------------- Queue ----------------x-------------------

int main(){

    // LinkedList l;

    // l.addAtBeg(1);
    // l.addAtBeg(2);
    // l.addAtBeg(3);
    // l.addAtBeg(4);
    // cout<<"Size "<<l.getSize()<<endl;
    // l.removeFront();
    // cout<<"Size "<<l.getSize()<<endl;

    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    cout<<"Size is "<<q.sizeOfQueue()<<endl;
    q.dequeue();
    cout<<"Size is "<<q.sizeOfQueue()<<endl;


    return 0;
}


// Coded by Huzaifa Qureshi