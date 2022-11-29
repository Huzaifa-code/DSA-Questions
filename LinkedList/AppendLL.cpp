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
        void print();
        void appendLL(LinkedList l2){

            node *t1 = first;
            node *t2 = l2.first;

            while(t1->next != NULL){
                t1= t1->next;
            }

            t1->next = t2; 
   
        }

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

void LinkedList::print(){
    node *temp = first;

    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

int main(){
    LinkedList l1,l2;

    l2.addAtBeg(1);
    l2.addAtBeg(2);
    l2.addAtBeg(3);

    cout<<"l2 :"<<endl;
    l2.print();
    cout<<endl;

    l1.addAtBeg(4);
    l1.addAtBeg(5);

    cout<<"l1 :"<<endl;
    l1.print();
    cout<<endl;

    l1.appendLL(l2);

    cout<<"Appended"<<endl;
    l1.print();

    return 0;
}