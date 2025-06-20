#include <iostream>
#include <vector>
#include <limits.h>
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

vector<int> nodesBetweenCriticalPoints(Node *head)
{
    // TC : Overall is O(n), where n is the length of linked list
    // SC: O(k), where k is no. of critical points
    vector<int> ans; // we can exclude this, can write without any extra space
    int cnt = 1;
    Node *prev = head;
    Node *curr = prev->next;
    Node *nextNode = curr->next;
    while (nextNode)
    {
        // inc. the cnt value, which tell which no. node we are standing (1st node etc)
        cnt++;
        // Critical Point: Local Maxima and Local Minima
        if (((curr->val > prev->val) && (curr->val > nextNode->val)) ||
            ((curr->val < prev->val) && (curr->val < nextNode->val)))
        {
            ans.push_back(cnt);
        }
        prev = curr;
        curr = nextNode;
        nextNode = curr->next;
    }

    // now we have an array of all critical points in the linked list
    // if the size of an array is not empty then min and max value will be there
    if (ans.size() >= 2)
    {
        // here min distance b/w any two distinct critical points
        int minDist = INT_MAX;
        for (int i = 1; i < ans.size(); i++)
        {
            minDist = min(minDist, ans[i] - ans[i - 1]);
        }
        return {minDist, ans[ans.size() - 1] - ans[0] /*maxDist*/};
    }
    else
    {
        return {-1, -1};
    }

    return {-1, -1};
}

int main()
{
    int size;
    cout << "Enter the size (no.of linked list element you want) : ";
    cin >> size;

    Node *head = NULL;
    int val;
    cout << "Enter the values you want to insert in linked list : ";
    for (int i = 0; i < size; i++) {
        cin >> val;
        createLL(head, val);
    }
    
    vector<int> ans = nodesBetweenCriticalPoints(head);
    for(auto i : ans) {
        cout<< i <<" ";
    } 
}