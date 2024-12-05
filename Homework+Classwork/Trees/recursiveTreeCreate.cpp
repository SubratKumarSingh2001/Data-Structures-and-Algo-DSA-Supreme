#include <iostream>
#include <queue>
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

//creating a tree : recursively 
Node* buildTree( ) {
    int data;
    cout<<"Enter the data want to add in the Tree : ";cin>>data;

    //base case when we get input as -1 then mark it as NULL and return 
    if(data == -1) {
        return NULL;
    }

    //recursive statements
    //Step A create a root node
    Node* root = new Node(data);

    //Step B
    cout<<"Enter the data left of " << data <<" Node" <<endl;
    root->left = buildTree();

    //Step C
    cout<<"Enter the data right of " << data <<" Node" <<endl;
    root->right = buildTree();

    return root;
}

//very important keep in mind
void levelOrderTraversal(Node* root) {
    queue<Node*> q;

    //initially push the root element in the queue
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        //steps for level order traversal
        //step A store the front value in temp variable and queue consists of addresses of Node queue<Node*>q, therefore use pointer
        Node* temp = q.front();

        //step B remove the front value from the queue, which means moving the front variable forward
        q.pop();

        if(temp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            //step C display the data of front value which have been recently pop out
            cout << temp->data << " ";

            //step D display the child nodes of temp 
            if(temp->left) { //this will basically check whether the temp node consists of any left and right node i.e child nodes if so push into queue
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    //LNR
    inOrderTraversal(root->left);
    cout<<root->data<<" ";
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }
    //NLR
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }  
    //LRN
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int heightOfTree(Node* root) {
    if(root == NULL) {
        return 0;
    }

    //calculate the height of left and right subtree
    int leftHeight = heightOfTree(root->left);
    int rightHeight = heightOfTree(root->right);

    //we have to check which subtree contains the max no of nodes 
    int height = max(leftHeight, rightHeight) + 1; // +1 because here we consider the height of root node is 1

    return height;
}

int diameterOfTree(Node* root) {
    //base case
    if(root == NULL) return 0 ;

    //here the maximum depth between two nodes can include the root node or not
    /* 
    if we have to calculate the max dept between two nodes on the basics of no of edges or no of nodes we can say that 
    no of nodes  = no of edges + 1. here we are considering the no of edges
    */
    int leftDepth = diameterOfTree(root->left);
    int rightDepth = diameterOfTree(root->right);
    int includeRootDepth = heightOfTree(root->left) + heightOfTree(root->right);

    //ans would be the max of all three which gives the maximum depth
    int ans = max(leftDepth, max(rightDepth, includeRootDepth));

    return ans;
}

int main() {

    Node* root = NULL;
    root = buildTree();
    
    cout<<"The Level Order Traversal is ";
    cout<<endl;
    levelOrderTraversal(root);
    cout<<"The Inorder Traversal is : ";
    inOrderTraversal(root);
    cout<<endl;
    cout<<"The Preorder Traversal is : ";
    preOrderTraversal(root);
    cout<<endl;
    cout<<"The Postorder Traversal is : ";
    postOrderTraversal(root);
    cout<<endl;

    int height = heightOfTree(root);
    cout<<"Height of the Tree is : " << height <<endl;

    int diameter = diameterOfTree(root);
    cout<<"Diameter of the Tree is : " << diameter <<endl;
}