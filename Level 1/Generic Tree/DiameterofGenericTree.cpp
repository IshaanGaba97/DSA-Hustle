//under testing
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int c = INT_MAX;
int flloor = INT_MIN;

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

//dia = deepest child + second deepest child + 2
static int dia = 0;
int calculateDiareturnHeight(Node* node){
    int dch = -1;
    int sdch = -1;
    
    for(Node* child : node->children){
        int ch = calculateDiareturnHeight(child);
        if(ch > dch){
            sdch = dch;
            dch = ch;
        } else if (ch > sdch){
            sdch = ch;
        }
    }
    if(dch + sdch + 2 > dia){
        dia = dch + sdch + 2;
    }
    dch += 1;                       //nodeheight = ch + 1
    return dch;                       //return node height
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
    int k;
    cin >> k;
    Node *root = construct(arr, n);
    int diameter = calculateDiareturnHeight(root);
    cout << diameter << endl;
}