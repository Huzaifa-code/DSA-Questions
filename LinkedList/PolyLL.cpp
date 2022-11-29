// Write a class to implement the Polynomial using link list.
// Write function for addition, subtraction and multiplication of polynomial.

#include<iostream>
using namespace std;

struct pnode{
    int c; //coefficient
    int p; //Power
    pnode *next;
};

class Poly{
    public:
        pnode *start;

        Poly(){
            start = NULL;
        }

        void addTerm(int c, int p){    //Time complexity = O(n)

            if(start == NULL){
                start = new pnode;
                start->c = c;
                start->p = p;
                start->next = NULL;

                return;
            }

            if(p > start->p){
                pnode *t = new pnode;
                t->c = c;
                t->p = p;
                
                t->next = start;
                start = t;
                return;
            }

            pnode *temp = start;

            while(temp != NULL){
                if(p == temp->p){
                    temp->c += c;
                    return;
                }

                temp = temp->next;
            }

            temp = start;
            while(temp->next != NULL){
                if(temp->next->p < p){
                    break;
                }
                temp = temp->next;
            }

            pnode *t = new pnode;
            t->c = c;
            t->p = p;
            t->next = temp->next;
            temp->next = t;
        }

        Poly addPoly(Poly p2){
            pnode *t1 = start;
            pnode *t2 = p2.start;

            Poly p3;

            while(t1 != NULL || t2 != NULL){
                if(t1 == NULL){
                    p3.addTerm(t2->c, t2->p);
                    t2 = t2->next;
                    continue;
                }

                if(t2 == NULL){
                    p3.addTerm(t1->c, t1->p);
                    t1 = t1->next;
                    continue;
                }

                if(t1->p == t2->p){
                    p3.addTerm(t1->c + t2->c, t1->p);
                    t1 = t1->next;
                    t2 = t2->next;
                    continue;
                }

                if(t1->p > t2->p){
                    p3.addTerm(t1->c , t1->p);
                    t1 = t1->next;
                }else {
                    p3.addTerm(t2->c , t2->p);
                    t2 = t2->next;
                }

            }


            return p3;

        }

        Poly subPoly(Poly p2){
            pnode *t1 = start;
            pnode *t2 = p2.start;

            Poly p3;

            while(t1 != NULL || t2 != NULL){
                if(t1 == NULL){
                    p3.addTerm(t2->c, t2->p);
                    t2 = t2->next;
                    continue;
                }

                if(t2 == NULL){
                    p3.addTerm(t1->c, t1->p);
                    t1 = t1->next;
                    continue;
                }

                if(t1->p == t2->p){
                    p3.addTerm(t1->c - t2->c, t1->p);
                    t1 = t1->next;
                    t2 = t2->next;
                    continue;
                }

                if(t1->p > t2->p){
                    p3.addTerm(t1->c , t1->p);
                    t1 = t1->next;
                }else {
                    p3.addTerm(t2->c , t2->p);
                    t2 = t2->next;
                }

            }


            return p3;

        }

        void print(){
            pnode *temp = start;

            while(temp != NULL){
                cout<<"Coefficient :"<<temp->c<<"\t";
                cout<<"power :"<<temp->p;
                temp = temp->next;
                cout<<endl;
            }    
        }

};

int main(){
    Poly p1,p2;

    p1.addTerm(5,3);
    p1.addTerm(4,2);
    p1.addTerm(3,1);

    cout<<"P1 : \n";
    p1.print();

    p2.addTerm(5,3);
    p2.addTerm(4,2);
    p2.addTerm(3,1);

    cout<<"P2 : \n";
    p2.print();

    // cout<<"P3 : \n";
    // Poly p3 = p1.addPoly(p2);

    // p3.print();

    cout<<"P3 : \n";
    Poly p3 = p1.subPoly(p2);

    p3.print();

    return 0;
}