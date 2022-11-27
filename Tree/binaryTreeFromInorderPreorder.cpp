#include<iostream>
using namespace std;

// ? Q - Given 2 Arrays of Inorder and preorder traversal. Construct a tree and print the Postorder traversal. 
// Example :
// N = 4
// inorder[] = {1 6 8 7}
// preorder[] = {1 6 7 8}
// Output: 8 7 6 1
// ? Your task is to complete the function buildTree() which takes 3 arguments(inorder traversal array, 
// ? preorder traversal array, and size of tree n) and returns the root node to the tree constructed. 
// * Asked by Amazon and Microsoft

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

int findPosition(int in[], int element, int n){
    for(int i=0; i<n; i++)
        if(in[i] == element)
            return i;

    return -1;
}

Node *solve(int in[] ,int pre[] ,int &index, int inorderStart, int inorderEnd, int n){

    // Base case
    if( index >= n || inorderStart > inorderEnd){
        return NULL;
    }

    int element = pre[index++];
    Node *root  = new Node(element);
    int position = findPosition(in, element, n);

    // recursive calls
    root->left = solve(in, pre, index, inorderStart, position-1, n);
    root->right = solve(in, pre, index, position+1, inorderEnd, n);

    return root;

}

Node* buildTree(int in[],int pre[], int n)
{
    int preOrderIndex = 0;
    Node *ans = solve(in , pre , preOrderIndex, 0, n-1, n);
    return ans;
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

int main(){

    int in[] = {1,6,8,7};
    int pre[] = {1,6,7,8};

    Node *root = NULL;

    root = buildTree(in, pre, 4);

    postorder(root);

    return 0;
}