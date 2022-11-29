#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
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
        void addAtEnd(int);
        int removeFront();
        int removeLast();
        int removePos(int);
        int getSize();
        void addAtPos(int data , int pos);
        void addAtMiddle(int data);
        void print();
        int middle();

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

void LinkedList::addAtEnd(int d){

    node *t = new node;
    t->data = d;
    t->next = NULL;

    if(first == NULL){
        first = t;
    }else{

        node *temp = first;

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = t;

    }

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

int LinkedList::removeLast(){
    if(first == NULL){
        return 0;
    }

    node *temp = first;

    while(temp->next->next != NULL){
        temp = temp->next;
    }

    node *t = temp->next;
    int d = t->data;

    temp->next = NULL;

    delete t;
    return d;

}

int LinkedList::removePos(int pos){
    
    node *temp = first;
    int count = 1;
    while(count < pos-1){
        temp = temp->next;
        count++;
    }

    node *t = temp->next;
    int d = t->data;
    temp->next = temp->next->next;
    delete t;
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

void LinkedList::addAtPos(int data , int pos){

    int count = 1;
    node *temp = first;

    node *t = new node;
    t->data = data;

    while(count < pos-1){
        temp = temp->next;
        count++;
    }

    t->next = temp->next;
    temp->next = t;

    // just also see for the case if pos = 1
}

void LinkedList::addAtMiddle(int data ){
    int size;

    // for getting size
        size = 0;
        node *x = first;
        while( x !=NULL ){
            x = x->next;
            size++;
        }
    // ----------------

    int mid = size/2;
    int count = 0;

    node *temp = first;
    while(count < mid-1){
        temp = temp->next;
        count++;
    }

    node *t = new node;
    t->data = data;

    t->next = temp->next;
    temp->next = t;

    
}

// Q-6
int LinkedList::middle(){
    node *fast = first;
    node *slow = first;

    if(first == NULL){
        cout<<"Empty";
    }

    while(fast->next != NULL && fast->next->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow->data;

}

void LinkedList::print(){
    node *temp = first;

    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}


int main(){

    LinkedList l;

    l.addAtEnd(6);
    l.addAtEnd(5);
    l.addAtEnd(4);
    l.addAtEnd(3);
    l.addAtEnd(2);
    l.addAtEnd(1);

    l.print();

    cout<<endl;
    // l.addAtMiddle(0);
    // l.print();

    // int a = l.middle();
    // cout<<a<<endl;
    // cout<<l.removePos(3);

    return 0;
}