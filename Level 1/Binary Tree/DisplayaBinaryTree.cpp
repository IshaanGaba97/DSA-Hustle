#include<iostream>
#include<string>
#include<sstream>
#include<stack>
#include<algorithm>
#include<ctype.h>
#include<vector>
#include<limits>
using namespace std;

class Node{
    public:
    int data;
    Node* left = NULL;
    Node* right = NULL;
    Node(int data, Node* left,Node* right){
        this->data = data;
        this->left = left;
        this->right = right;
    }
};

class Pair{
    public:
    Node* node;
    int state;
    
    Pair(Node* node, int state){
        this->node = node;
        this->state = state;
    }
};

void display(Node * node) {
    if (node == NULL) {
        return;
    }
    
    //node self work
    string str = "";
    str += node -> left == NULL ? "." : to_string(node -> left -> data) + "";
    str += " <- " + to_string(node -> data) + " -> ";
    str += node -> right == NULL ? "." : to_string(node -> right -> data) + "";
    cout << str << endl;

    display(node -> left);
    display(node -> right);
}

//preodrer - data leftchild  rightchild
//state 1-right 2-right 3-pop of an element
int main(){
    int num;
    cin >> num;
    // string a[num];
    vector<string> a(num);
    // int arr[num];
    int* arr = new int(num);
    string str;
    for(int i=0;i<num;i++){
        cin>>str;
        a[i]=str;
    }

   for(int i=0;i<num;i++){
      if (a[i]=="n") {
            arr[i] = INT_MAX;
        } else {
            istringstream sv(a[i]);
            int val;
            sv>>val;
            arr[i] = val;
        }  
   }
    stack<Pair*> st;
    Node* root = new Node(arr[0], NULL, NULL);
    Pair* rtp = new Pair(root, 1);
    st.push(rtp);
    
    int idx = 0;
    while(st.size() > 0){
        Pair* top = st.top();
        if(top->state == 1){
            idx++;
            if(arr[idx] != INT_MAX){
                top->node->left = new Node(arr[idx], NULL, NULL);
                Pair* lp = new Pair(top->node->left, 1);
                st.push(lp);
            } else{
                top->node->left = NULL;
            }
            top->state++;
        } else if(top->state == 2){
            idx++;
            if(arr[idx] != INT_MAX){
                top->node->right = new Node(arr[idx], NULL, NULL);
                Pair* rp = new Pair(top->node->right, 1);
                st.push(rp);
            } else{
                top->node->right = NULL;
            }
            top->state++;
        } else if(top->state == 3){
            st.pop();
        }
        // return root;
    }
    display(root);
}