#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Node
{
public:
    int data;
    vector<Node *> children;
};

static Node *predecessor;
static Node *sucessor;
static int state;

void prnsc(Node *node, int data)
{
    if (state == 0)                                 //last element in state 0 -> p  first element in state 1 -> s
    {
        if (node->data == data)
        {
            state = 1;
        }
        else
        {
            predecessor = node;
        }
    }
    else if (state == 1)
    {
        sucessor = node;
        state = 2;
    }

    for (Node *child : node->children)
    {
        prnsc(child, data);
    }
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
            Node *t = new Node();
            t->data = arr[i];

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
    int data;
    cin >> data;
    predecessor = NULL;
    sucessor = NULL;
    state = 0;
    prnsc(root, data);
    if (predecessor == NULL)
    {
        cout << "Predecessor = Not found"
             << "\n";
    }
    else
    {
        cout << "Predecessor = " << predecessor->data << "\n";
    }

    if (sucessor == NULL)
    {
        cout << "Successor = Not found"
             << "\n";
    }
    else
    {
        cout << "Successor = " << sucessor->data << "\n";
    }

    return 0;
}