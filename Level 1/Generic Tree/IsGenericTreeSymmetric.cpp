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
    Node()
    {
    }
    Node(int data)
    {
        this->data = data;
    }
};

void display(Node *node)
{
    string str = to_string(node->data) + " -> ";

    for (Node *child : node->children)
    {
        str += to_string(child->data) + ", ";
    }
    str += ".";
    cout << str << "\n";

    for (Node *child : node->children)
    {
        display(child);
    }
}

bool isMirror(Node *n1, Node *n2)
{
    if (n1->children.size() != n2->children.size())
    {
        return false;
    }

    for (int i = 0; i < n1->children.size(); i++)
    {
        int j = n1->children.size() - 1 - i;
        Node *c1 = n1->children[i];
        Node *c2 = n2->children[j];
        if (isMirror(c1, c2) == false)
        {
            return false;
        }
    }
    return true;
}

bool issym(Node *node)
{
    return isMirror(node, node);       //a tree is symmetric if its right and left childs are mirror images
}

int main()
{
    int n;
    cin >> n;

    // int arr[n];
    int* arr = new int(n);
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
    bool sym = issym(root);
    if (sym == 1)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}