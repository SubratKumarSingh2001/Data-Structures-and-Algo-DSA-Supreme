#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;

    Node()
    {
        this->val = 0;
        this->next = NULL;
    }
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

Node *createNode(int val)
{
    Node *newNode = new Node(val);
    newNode->next = NULL;

    return newNode;
}

void createLL(Node *&head, int val)
{
    Node *newNode = createNode(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayLL(Node *&head)
{ // here head is pass by reference as any changes made will be made at original head pointer
    Node *temp = head;
    while (temp)
    {
        cout << temp->val << "->";
        temp = temp->next;
    }
}

Node *deleteNNodeAfterSkipMNodes(Node *&head, int m, int n) 
{
    /*TC: Outer-loop*inner-loop, Outer Loop : O(L/m+n) Approx val
    for outer loop and Inner Loop : O(m+n)
    Total TC: O(L/m+n)*O(m+n) = O(l) where l = len of Ll
    */
    // SC: O(1)
    if (head->next == NULL)
        return head;

    Node *temp = head;
    while (temp)
    {
        // first we will skip the m-1 nodes
        for (int i = 0; i < m - 1; i++)
        {
            if (!temp)
                break; // this when the m nodes not there
            temp = temp->next;
        }

        // when temp become null come out of the loop
        if (!temp)
            break;

        // now delete the n nodes
        Node *del = temp->next;
        for (int i = 0; i < n; i++)
        {
            if (!del)
                break;
            Node *nodeDelete = del;
            del = del->next;
            delete (nodeDelete);
        }

        // now we will attach the pointer temp pointer to maintain LL
        temp->next = del;

        // now we will perform for the next segment
        temp = del;
    }

    return head;

    // we can do this with recursion... easy
}

int main()
{
    int size;
    cout << "Enter the size (no.of linked list element you want) : ";
    cin >> size;

    Node *head = NULL;
    int val;
    cout << "Enter the values you want to insert in linked list : ";
    for (int i = 0; i < size; i++)
    {
        cin >> val;
        createLL(head, val);
    }
    int m, n;
    cout << "Enter the value of m : ";
    cin >> m;
    cout << "Enter the value of n : ";
    cin >> n;
    head = deleteNNodeAfterSkipMNodes(head, m, n);
    displayLL(head);
}