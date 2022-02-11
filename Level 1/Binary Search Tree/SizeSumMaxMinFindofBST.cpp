#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

struct Node {
  int data;
  Node* left;
  Node* right;
  Node(int val) {
    data = val;
    left = nullptr;
    right = nullptr;
  }
};

Node* construct(vector<int>& arr) {
  Node* root = new Node(arr[0]);
  pair<Node*, int> p = {root, 1};

  stack<pair<Node*, int>> st;
  st.push(p);

  int idx = 1;
  while (!st.empty()) {

    if (st.top().second == 1) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->left = new Node(arr[idx]);
        pair<Node*, int> lp = {st.top().first->left, 1};
        st.push(lp);
      }
      else {
        st.top().first->left = nullptr;
      }
      idx++;
    }
    else if (st.top().second == 2) {
      st.top().second++;
      if (arr[idx] != -1) {
        st.top().first->right = new Node(arr[idx]);
        pair<Node*, int> rp = {st.top().first->right, 1};
        st.push(rp);
      } else {
        st.top().first->right = nullptr;
      }
      idx++;
    }
    else {
      st.pop();
    }

  }
  return root;
}

int size(Node * node) {
    if (node == NULL) {
        return 0;
    }
    int ls = size(node -> left);
    int rs = size(node -> right);
    int ts = ls + rs + 1;
    return ts;
}
int sum(Node * node) {
    if (node == NULL) {
        return 0;
    }
    int lsm = sum(node -> left);
    int rsm = sum(node -> right);
    int tsm = lsm + rsm + node -> data;
    return tsm;
}
int max(Node * node) {
    if(node->right!=NULL){
       return max(node->right);
    }else{
        return node->data;
    }
}
int min(Node * node) {
    if(node->left!=NULL){
       return min(node->left);
    }else{
        return node->data;
    }
}

bool find(Node* node,int data){
    if(node==NULL){
        return false;
    }
    if(data>node->data){
        return find(node->right,data);
    }else if(data<node->data){
        return find(node->left,data);
    }else{
        return true;
    }
}

int main() {
  int n;
  cin >> n;
  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++) {
    string x;
    cin >> x;
    if (x == "n") {
      arr[i] = -1;

    }
    else {
      arr[i] = stoi(x);
    }
  }
  int data;
  cin >> data;
  Node* root = construct(arr);
  cout << size(root) << "\n" << sum (root) << "\n" << max(root) << "\n" << min(root) <<  "\n";
  if (find(root, data)) {
    cout << "true" << endl;
  }
  else {
    cout << "false" << endl;
  }
}