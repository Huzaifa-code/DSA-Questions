// Q - Reversing a singly Linked List

#include<iostream>
using namespace std;

// --------------------------Linked List code --------------------------------
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

        void reverseLinkedList();
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

// --------------------------- !!! ANSWER !!! ------------------------------------

void LinkedList::reverseLinkedList(){
    
    if( first == NULL || first->next == NULL ){
        return ;
    }
    
    
    node *prev = NULL;
    node *curr = first;
    node *forward = NULL;
        
    while(curr != NULL){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }

    first = prev;
}
// ----------x---------------- !!! ANSWER !!! ------------------x-----------------


int main(){

    LinkedList l;

    l.addAtBeg(1);
    l.addAtBeg(2);
    l.addAtBeg(3);
    l.addAtBeg(4);

    l.print();

    l.reverseLinkedList();

    cout<<"reverse is :"<<endl;
    l.print();


    return 0;
}