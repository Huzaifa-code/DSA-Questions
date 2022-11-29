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

int height(Node *root){

    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;
    return ans;

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

void inorder(Node *root){
    
    //base case
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(Node *root){
    
    //base case
    if(root == NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node *root){
    
    //base case
    if(root == NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

int diameter(Node *root){

    // ? Diameter = is number of nodes on the longest path between 2 end nodes

    // base case
    if(root == NULL){
        return 0;
    }

    int op1 = diameter(root->left);
    int op2 = diameter(root->right);
    int op3 = height(root->left) + 1 + height(root->right);

    int ans = max(op1 , max(op2,op3)); 
    return ans; 
}

bool isBalanced(Node *root){
    // ? Check if tree is balanced  - difference between heights of left and right subtrees is not more than one for all nodes of tree

    // Base case 
    if(root == NULL){
        return true;
    }

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs( height(root->left) - height(root->right) ) <= 1;

    if(left && right && diff){
        return true;
    }else {
        return false;
    }

    // * Time Complexity = O(n^2)
}

// ? TO check if 2 Trees are Identical 
bool isIdentical(Node *r1, Node *r2){   

    // Base case
    if(r1 == NULL && r2 == NULL){
        return true;
    }

    if( r1 == NULL && r2 != NULL){
        return false;
    }
    if( r1 != NULL && r2 == NULL){
        return false;
    }

    bool left = isIdentical(r1->left , r2->left );
    bool right = isIdentical(r1->right , r2->right);

    bool value = r1->data == r2->data;

    if(left && right && value){
        return true;
    }else {
        return false;
    }

}

int main(){

    Node *root = NULL;

    // Creating a tree
    root = buildTree(root); 
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    // level order traversal
    cout<<"Printing level order traversal output : \n ";
    levelOrderTraversal(root);

    cout<<"\n Height is : "<<height(root)<<endl;

    return 0;
}