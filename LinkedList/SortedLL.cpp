// Q - Write a function to insert a new node (with given data value) in a 
//sorted position of a sorted link list. void insertatsorted(int data)

#include<iostream>
using namespace std;


struct node{
    int data;
    node * next;
};



class LinkedList{
    node *first;

    public:
        LinkedList(){
            first = NULL;
        }

        void print();

        void insertSorted(int d){

            node *t = new node;
            t->data = d;
            t->next = NULL;

            
            if(first == NULL){
                first = t;
                return;
            }

            if( d < first->data){
                t->next = first;
                first = t;
                return;
            }

            node *temp = first;

            while(temp->next != NULL){
                if(temp->next->data > d){
                    break;
                }

                temp = temp->next;
            }

            t->next = temp->next;
            temp->next = t;


        }
};


void LinkedList::print(){
    node *temp = first;

    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main(){

    LinkedList l;

    l.insertSorted(2);
    l.insertSorted(1);
    l.insertSorted(3);
    l.insertSorted(4);
    l.insertSorted(5);

    l.print();

    return 0;
}