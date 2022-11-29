#include<iostream>
#include<queue>
using namespace std;

// ? Binary Search Tree :
// * The left subtree of a node contains only nodes with keys lesser than the node’s key.
// * The right subtree of a node contains only nodes with keys greater than the node’s key.

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

// --------------- Insert ---------------------------
Node* insertIntoBST(Node* root, int d){

    //Base case
    if(root == NULL){
        root = new Node(d);
        return root;
    }

    if( d > root->data){
        //Right part me insert karna hai
        root->right = insertIntoBST(root->right, d);
    } else {
        //Insert in left part   
        root->left = insertIntoBST(root->left, d);
    }

    return root;

    // * Time Complexity for insertion in BST is O(log n)

}

void takeInput(Node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin>>data; 
    }
}
// ------x-------- Insert -------------x-------------


// ----------------- Search ------------------------
bool searchInBST1(Node *root , int key){

    // Base case
    if(root == NULL){
        return false;
    }

    if( root->data == key ){
        return true;
    }

    if(root->data > key){
        return searchInBST1(root->left, key);
    }
    else {
        // right part 
        return searchInBST1( root->right , key);
    }

    // ? Space complexity = O(n) and Time complexity = For avg case O(H or log n) | in worst case O(n) for skewed bst

}

bool searchInBST2(Node *root , int key){
    
    // * Iteratively - SECOND METHOD
    Node *temp = root;

    while( temp != NULL){

        if(temp->data == key){
            return true;
        }

        if(temp->data > key){
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }

    }

    return false;

}

// -------x--------- Search ------------x-----------


// Max and Min value in BST 
// ? Minimum value is the leftmost leaf of BST
Node* minVal(Node* root){
    Node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }

    return temp;
}
Node* maxVal(Node* root){
    Node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;
    }

    return temp;
}

// ------------------- Deleting a node in BST -------------------------
// * IMPORTANT ASKED IN INTERVIEWS
Node* deleteFromBST(Node* root, int val){
    //Base case
    if(root == NULL){
        return root;
    }

    if(root->data == val){
        // case 1 : 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // case 2 : 1 child
            // 1 child is left child
                if(root->left != NULL && root->right == NULL){
                    Node* temp = root->left;
                    delete root;
                    return temp;    
                }

            // 1 child is right child
                if(root->right != NULL && root->left == NULL){
                    Node* temp = root->right;
                    delete root;
                    return temp;    
                }

        // case 3 : 2 child
        if(root->left != NULL && root->right != NULL){
            // minimum value from right subtree 
            int mini = minVal(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }


    }
    else if( root->data > val ){
        root->left = deleteFromBST(root->left, val);
        return root;
    } else {
        root->right = deleteFromBST(root->right, val);
        return root;
    }
}
// ----------x-------- Deleting a node in BST -----------x-------------


int main(){

    Node *root = NULL;

    cout<<"Enter data to create BST \n";
    takeInput(root);

    cout<<"\n Level order Traversal : \n";
    levelOrderTraversal(root);

    root = deleteFromBST(root, 30);


    cout<<"\n Level order Traversal after deleting 30 : \n";
    levelOrderTraversal(root);

    return 0;
}