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

void levelOrderTreeCreate(Node* &root) {
    int data;
    cout<<"Enter the data you want to add in the Tree :";cin>>data;

    if(data == -1) {
        return;
    }
    //first push the root node in the queue
    Node* newNode = new Node(data);                 
    root = newNode; //assign the newNode to the root

    queue<Node*> q;
    q.push(root); 

    while(!q.empty()) {
        //step A: store the front value pushed in the queue in the temporary pointer
        Node* temp = q.front();
        
        //step B: pop the value from the queue means move the front value one step ahead so to access the later on values of queue
        q.pop();

        //step C: now add a node to the left of the temp node
        cout<<"Enter the data you want to add to the left of " << temp->data <<endl;
        cout<<"Enter the data : ";cin>>data;
        if(data != -1) {
            Node* leftChild = new Node(data);
            temp->left = leftChild;
            q.push(leftChild);
            cout<<data <<" added to the left of " << temp->data << endl;
        }
        else {
            cout<<"NULL added to the left of " << temp->data << endl;
        }

        //step D: now add a node to the right of the temp node
        cout<<"Enter the data you want to add to the right of " << temp->data <<endl;
        cout<<"Enter the data : ";cin>>data;
        if(data != -1) {
            Node* rightChild= new Node(data);
            temp->right = rightChild;
            q.push(rightChild);
            cout<<data <<" added to the right of " << temp->data << endl;
        }
        else {
            cout<<"NULL added to the right of " << temp->data << endl;
        }
    }
}

void levelOrderTraversal(Node* &root) {
    queue<Node*> q;
    //root node of a tree will be single node on initial level so after root node pushed in stack push NULL
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout<<endl;
            if(!q.empty()) {
                q.push(NULL); 
            }
        }
        else{
            cout << temp->data << " ";
            if(temp->left) {
                q.push(temp->left);
            }
            if(temp->right) {
                q.push(temp->right);
            }
        }
    }

}

int main() {
    Node* root = NULL;

    levelOrderTreeCreate(root);

    levelOrderTraversal(root);

    return 0;
}