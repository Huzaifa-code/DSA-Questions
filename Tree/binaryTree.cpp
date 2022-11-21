#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *buildTree(Node *root){
    cout<<"Enter data"<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for inserting in right of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;

}

void levelOrderTraversal(Node *root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL); //Separator

    while( !q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){ //Purana level traverse ho chuka hai
            cout<<endl;

            if(!q.empty()){ //Queue still has some child nodes
                q.push(NULL);
            }
        }else {
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}

void inorder(node *root){
    
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(node *root){
    
    //base case
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    pretorder(root->right);

}

void postorder(node *root){
    
    //base case
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

int main(){

    Node *root = NULL;

    // Creating a tree
    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order traversal
    cout<<"Printing level order traversal output : \n ";
    levelOrderTraversal(root);

    return 0;
}