#include<iostream>
using namespace std;

struct dnode{
    float data;
    dnode *prev;
    dnode *next;
};

class DLinkedList{
    dnode *start;

    public:
        DLinkedList(){
            start = NULL;
        }

        void addAtBeg(float x){
            dnode *t = new dnode;
            t->data = x;
            t->prev = NULL;

            if(start == NULL){
                t->next = NULL;
                start = t;
            }else {
                start->prev = t;
                t->next = start;
                start = t;
            }
        }

        void addAtLast(float x){
            dnode *t = new dnode;
            t->data = x;
            t->next = NULL;

            if(start == NULL){
                t->prev = NULL;
                start = t;
            }else {
                dnode *temp = start;

                while(temp->next != NULL){
                    temp = temp->next;
                }

                t->prev = temp;
                temp->next = t;
            }
        }

        float removeLast(){

            if(start == NULL){
                return 0.0;
            }

            if(start->next == NULL){
                float d = start->data;

                delete start;
                start = NULL;
                return d;
            }

            dnode *temp = start;

            while(temp->next != NULL){
                temp = temp->next;
            }

            float d = temp->data;

            temp->prev->next = NULL;
            delete temp;

            return d;
        
        }

        float removeFront(){

            if(start == NULL){
                return 0.0;
            }

            dnode *temp = start;
            start = start->next;
            start->prev = NULL;

            float d = temp->data;
            delete temp;
            return d;


        }

        void print(){
            dnode *temp = start;

            while(temp != NULL){

                cout<<temp->data<<"\t";

                temp = temp->next;
            }
        }

        int getSize(){
            dnode *t;
            int count = 0;
            t = start;

            while(t != NULL){
                count++;
                t = t->next;
            }

            return count;
        }

};

int main(){

    DLinkedList d;

    d.addAtBeg(1);
    d.addAtLast(2);
    d.addAtLast(3);
    d.addAtLast(4);
    d.addAtLast(5);

    d.print();

    cout<<"\n Removed : "<<d.removeFront();
    cout<<endl;            
    d.print();

    return 0;
}