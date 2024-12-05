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

int convertIntoSumTree(Node* &root) {
    //base case if root is null return 0
    if(root == NULL) {
        return 0;
    }
    /*
    we will traverse the left and right subtree of the root node until we reach the leaf node because the sum tree is defined as 
    the current node is sum of left child of curr node and right child of curr node and current node itself
    */
    int leftSubtreeSum = convertIntoSumTree(root->left);
    int rightSubtreeSum = convertIntoSumTree(root->right);

    root->data = leftSubtreeSum + root->data + rightSubtreeSum;

    return root->data;
}

int main() {
    Node* root = NULL;

    createTree(root);
    cout<<"Printing the Tree " <<endl;
    printTree(root);

    convertIntoSumTree(root);
    cout<<"Sum Tree of given Binary Tree is " <<endl;
    printTree(root);

}