#include <iostream>
using namespace std;

struct cnode{
    int x;
    cnode* next;
};

class clinklist{
    cnode* start;
    public:
    clinklist(){
        start = NULL;
    }

    void addatbeg(int data){
        cnode* temp = new cnode;
        temp->x = data;
        temp->next = NULL;

        if(start == NULL){
            temp->next = temp;
            start = temp;
        }
        else{
            cnode* curr = start;
            while (curr->next != start)
            {
                curr = curr->next;
            }
            curr->next = temp;
            temp->next = start;
            start = temp;
        }
    }
   
    void display(){
        cnode* curr = start->next;
        if (start == NULL)
        {
            return;
        }
        
        cout<<start->x<<" ";

        while (curr != start)
        {
            cout<<curr->x<<" ";
            curr = curr->next;
        }
        
    }
    
    void addatend(int data){
        cnode* temp = new cnode;
        temp->x = data;
        temp->next = NULL;
        if (start == NULL)
        {
            start = temp;
        }
        cnode* curr = start;
        while (curr->next != start)
        {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = start;
        
    }
    
    int removefront(){
        if(start == NULL){
            return -1;
        }
        
        if(start->next == start){
            int c = start->x;
            start->next = NULL;
            delete start;
            return c;

        }
        cnode* curr = start;
        int c = start->x;
        while (curr->next != start)
        {
            curr = curr->next;
        }
        cnode* s = start;
        curr->next = start->next;
        start = start->next;
        delete s;
        
        return c;
        
        
    }
    
    int removelast(){
        if(start == NULL){
            return -1;
        }
        if(start->next == start){
            int c = start->x;
            start->next = NULL;
            delete start;
            return c;
        }
        cnode* curr = start;
        while (curr->next->next != start)
        {
            curr = curr->next;
        }
        int c = curr->next->x;
        cnode* s = curr->next;
        curr->next = start;
        delete s;
        return c;
    }
    
    int getlength(){
        if(start == NULL){
            return -1;
        }
        int cnt = 1;
        if(start->next == start){
            return cnt;
        }
        cnode* curr = start->next;
        while (curr != start)
        {
            cnt++;
            curr = curr->next;
        }
        return cnt;
        
    }
    
    void addatmiddle(int data){
        
        cnode* temp = new cnode;
        temp->x = data;
        temp->next = NULL;
        if (start == NULL)
        {
            start = temp;
            temp->next = start;
        }
        else{

            cnode* slow = start;
            cnode* fast = start;
            while (fast->next!=start && fast->next->next!=start)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            temp->next = slow->next;
            slow->next = temp;
        }
        
    }
    
};
int main(){
    clinklist c1;
    c1.addatbeg(5);
    c1.addatbeg(10);
    c1.addatend(15);
    c1.addatend(25);
    c1.display();
    cout<<endl;
    // cout<<c1.removefront();
    // cout<<endl;
    // c1.display();
    // cout<<endl;
    // cout<<c1.removelast();
    // cout<<endl;
    // c1.display();
    // cout<<endl;
    // cout<<c1.removelast();
    // cout<<endl;
    // cout<<c1.getlength();
    // c1.addatmiddle(20);
    // c1.display();
    return 0;
}