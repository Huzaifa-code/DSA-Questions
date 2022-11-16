#include<iostream>
using namespace std;

struct pqnode{
    char c;
    int p;
    pqnode *next;
};

class PQ{
    pqnode *start;

    public:
        PQ(){
            start = NULL;
        }

        void enqueue(char c, int pr){
            pqnode *t;
            t = new pqnode;

            t->c = c;
            t->p = pr;
            t->next = NULL;

            if(start == NULL){
                start = t;
                return;
            } 

            if(pr > start->p){
                t->next = start;
                start = t;
                return;
            }

            pqnode *temp;
            temp = start;

            while(temp->next != NULL){
                if(pr > temp->next->p){
                    break;
                }else {
                    temp = temp->next;
                }
            }

            t->next = temp->next;
            temp->next = t;
        }

        char dequeue(){
            if(start == NULL){
                cout<<"Queue is empty";
            }
            
            pqnode *t;
            t = start;
            start = start->next;

            char x = t->c;
            delete t;
            return x;
        }

        void display(){
            pqnode *temp = start;

            if(start == NULL){
                cout<<"Queue is empty";
                return;
            }

            while(temp != NULL){
                cout<<temp->c<<"\t";
                temp = temp->next;
            }
        }
};

int main(){

    PQ p;

    p.enqueue('a', 5);
    p.enqueue('x', 7);
    p.enqueue('b', 3);
    p.enqueue('c', 2);

    p.display();

    return 0;
}