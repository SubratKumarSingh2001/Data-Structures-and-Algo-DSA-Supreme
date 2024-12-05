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
    cout<<" Enter the value of root : ";cin>>data;

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

int heightOfTree(Node* root) {
    if(root == NULL) {
        return 0;
    }

    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);
    
    int height = max(leftHeight, rightHeight) + 1; // +1 for root node as height calculated for no.of nodes