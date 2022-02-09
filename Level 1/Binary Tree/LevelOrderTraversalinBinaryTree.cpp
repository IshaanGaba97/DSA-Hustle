#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <algorithm>
#include <ctype.h>
#include <climits>
#include <vector>
using namespace std;

struct Node
{
    int data;
    vector<Node *> children;
};

Node *newNode(int key)
{
    Node *temp = new Node;
    temp->data = key;
    return temp;
}

Node *construct(int arr[], int n)
{
    Node *root = NULL;
    stack<Node *> st;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *t = newNode(arr[i]);
            if (st.size() > 0)
            {
                st.top()->children.push_back(t);
            }
            else
            {
                root = t;
            }
            st.push(t);
        }
    }
    return root;
}

void levelorder(Node *node)
{
    queue<Node *> mq;
    mq.push(node);
    while (mq.size() > 0)
    {
        int count = mq.size();
        for (int i = 0; i < count; i++)
        {
            node = mq.front();
            mq.pop();
            cout << node->data << " ";
            for (Node *child : node->children)
            {
                if (child != NULL)
                {
                    mq.push(child);
                }
            }
            // if(node->left != NULL){
            //     mq.push(node->left);
            // }
            // if(node->right != NULL){
            //     mq.push(node->right);
            // }
        }
    }
    cout << ".";
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    // int arr[n];
    int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = construct(arr, n);
    levelorder(root);
}