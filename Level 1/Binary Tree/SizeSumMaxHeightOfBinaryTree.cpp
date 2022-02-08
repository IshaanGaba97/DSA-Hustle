#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<algorithm>
#include<ctype.h>
#include<vector>
#include<limits>

using namespace std;

// structure of node
class Node
{
public:
    int data;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int data)
    {
        this->data = data;
    }
};

class Pair {
    public:
    Node * node = nullptr;
    int state=0;

    Pair(Node *node, int state) {
      this->node = node;
      this->state = state;
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
    Node *node = new Node(arr[idx++]);
    node->left = constructTree(arr);
    node->right = constructTree(arr);
    return node;
}

void display(Node *node)
{
    if (node == nullptr)
        return;
    string str = "";
    str += node->left != nullptr ? to_string(node->left->data) : ".";
    str += " <- " + to_string(node->data) + " -> ";
    str += node->right != nullptr ? to_string(node->right->data) : ".";
    cout << str << endl;

    display(node->left);
    display(node->right);
}


int size(Node *node)
{
   if(node == NULL){
       return 0;
   }
   int ls = size(node->left);
   int rs = size(node->right);
   int ts = ls + rs + 1;
   return ts;
}

int height(Node *node)
{
    if(node == NULL){
        return -1;   //-1 for edges, 0 for nodes
    }
    int lh = height(node->left);
    int rh = height(node->right);
    int maxh = max(lh, rh) + 1;
    return maxh;
}

int maximum(Node *node)
{
    if(node == NULL){
        return INT_MIN;        //identity to initialize
    }
    //write your code here
    int lmax = maximum(node->left);
    int rmax = maximum(node->right);
    int maxi = max(node->data, max(lmax,rmax));
    return maxi;
}

int sum(Node *root)
{
    if(root == NULL){
       return 0;
    }
    int lsum = sum(root->left);
    int rsum = sum(root->right);
    int tsum = lsum + rsum + root->data;
    return tsum;
}

int main()
{
 
  int n;
  cin>>n;
  
  vector<int> arr(n,0);
  for(int i = 0; i < n; i++){
      string temp;
      cin>>temp;
      
      if(temp=="n")
      {
        arr[i] = -1;  
      }
      else
      {
        arr[i] = stoi(temp); 
      }
  }
  
   Node *root = constructTree(arr);

    int sz = size(root);
    int sm = sum(root);
    int max = maximum(root);
    int ht = height(root);
    cout<<sz<<endl;
    cout<<sm<<endl;
    cout<<max<<endl;
    cout<<ht<<endl;
  }
