#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data, Node *left, Node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

int idx = 0;
Node *constructTree(vector<int> &arr)
{

    if (idx == arr.size() || arr[idx] == -1)
    {
        idx++;
        return nullptr;
    }
    Node *node = new Node(arr[idx++], nullptr, nullptr);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    string str = "";
    str += node->left == nullptr ? "." : to_string(node->left->data) + "";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right == nullptr ? "." : to_string(node->right->data) + "";
    cout << str << endl;

    display(node->left);
    display(node->right);
}

void printSingleChildNodes(Node *node, Node *parent)
{
    // write your code here
    if (node == nullptr)
    {
        return;
    }
    if (parent != nullptr && parent->left == node && parent->right == nullptr)
    {
        cout << node->data << endl;
    }
    else if (parent != nullptr && parent->right == node && parent->left == nullptr)
    {
        cout << node->data << endl;
    }
    printSingleChildNodes(node->left, node);  // node->left parent is node
    printSingleChildNodes(node->right, node); // node->right parent is node
}

int main()
{
    vector<int> arr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string inp;
        cin >> inp;
        if (inp != "n")
        {
            arr.push_back(stoi(inp));
        }
        else
        {
            arr.push_back(-1);
        }
    }

    Node *root = constructTree(arr);
    printSingleChildNodes(root, nullptr);
}