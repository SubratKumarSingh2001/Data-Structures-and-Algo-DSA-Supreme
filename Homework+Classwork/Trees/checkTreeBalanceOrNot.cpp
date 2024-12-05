#include <iostream>
#include<queue>
using namespace std;

class Node {
    public :
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

//leveL order tree create
void createTree(Node* &root) {
    int data;
    cout<<"Enter the value of root : ";cin>>data;

    if(data == -1) {
        return;
    }

    Node* newNode = new Node(data);
    root = newNode;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        //Step: A
        Node* temp = q.front();

        //Step: B
        q.pop();

        //Step: C 
        cout<<"Enter the data want to add to the left of " << temp->data <<endl;
        cout<<"Enter the data : ";cin>>data;
        if(data != -1) {
            Node* leftChild = new Node(data);
            temp->left = leftChild;
            q.push(leftChild);
            cout<<data <<" pushed to the left of " << temp->data << endl;
        }
        else {
            cout<<"NULL pushed to the left of the " << temp->data <<endl;
        }

        //Step: D
        cout<<"Enter the data want to add to the right of " << temp->data <<endl;
        cout<<"Enter the data : ";cin>>data;
        if(data != -1) {
            Node* rightChild = new Node(data);
            temp->right = rightChild;
            q.push(rightChild);
            cout<<data <<" pushed to the right of " << temp->data << endl;
        }
        else {
            cout<<"NULL pushed to the right of the " << temp->data <<endl;
        }
    }
}

//level order tree print
void printTree(Node* &root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();
        
        if(temp == NULL) {
            cout<<" " <<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout<<temp->data <<" ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

int heightOfTree(Node* &root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    
    int height = max(leftHeight, rightHeight) + 1; // +1 for root node as height calculated for no.of nodes

    return height;

}

bool balanceTree(Node* &root) {
    //base case if no node present consider the tree is balance.

    if(root == NULL) {
        return true;
    }

    /* 
    A tree is said to balanced if for each Node the height of left subtree and right subtree difference is less than
    equal to 1 i.e abs(height of left subtree - height of right subtree ) <= 1
    */
    //So we will find the height of left and right subtree
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    //now the diff
    int diff = abs(leftHeight- rightHeight);
    bool curr = (diff <= 1);

    //recursion for all the child nodes this will perform for all the nodes of the tree
    bool leftSubtree = balanceTree(root->left);
    bool rightSubtree = balanceTree(root->right);

    if(curr && leftSubtree && rightSubtree) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    Node* root = NULL;

    createTree(root);
    printTree(root);

    if(balanceTree(root)) {
        cout <<"Tree is Balanced.." <<endl;
    }
    else {
        cout<<"Tree is not Balanced.." <<endl;
    }
}