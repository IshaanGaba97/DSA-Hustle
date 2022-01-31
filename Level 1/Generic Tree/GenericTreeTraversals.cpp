#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>children;
};

void display(Node* node){
    string str = to_string(node->data) + " -> ";
    
    for(Node* child : node->children){
        str += to_string(child->data)+" , ";
    }
    str+= ".";
    cout<<str<<"\n";
    
    for(Node* child : node->children){
        display(child);
    }
}

int size(Node* node){
    int s = 0;
    
    for(Node* child : node->children){
        int cs = size(child);
        s = s + cs;
    }
    s = s + 1;
    return s;
}

//maximum = root, child 1, child 2, ...
int maximum(Node* node){
    int maxi = INT_MIN;
    for(Node* child : node->children){
        int cm = maximum(child);
        maxi = max(cm, maxi);
    }
    maxi = max(node->data, maxi);
    return maxi;
}

//height = max height of (child 1, child 2, ...) + 1(root)

int height(Node* node){
    int ht = -1;               //height = total no. of max edges - to handle base case of 0 edges in last child
    
    for(Node* child : node->children){
        int ch = height(child);
        ht = max(ht, ch);
    }
    ht = ht + 1;              //root node height add 1
    return ht;
}

void traversals(Node* node){
    // area1 - euler left - nodes pre area - while going up in the recursion
    cout << "Node Pre " << node->data << endl;
    for(Node* child : node->children){
        //edge pre
        cout << "Edge Pre " << node->data << "--"<< child->data<< endl;
        traversals(child);
        //edge post
        cout << "Edge Post " << node->data << "--"<< child->data << endl;
    }
    //area2 - euler right - nodes post area - while going down in the recursion
    cout << "Node Post " << node->data << endl;
}


int main(){
    // int arr[]={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,100,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    // int n = 24;
    int n;
    cin>>n;
    // int arr[n];
    int* arr = new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    Node* root = NULL;
    stack<Node*> st ;
    
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node* t= new Node();
            t->data = arr[i];
            
            if(st.size()>0){
                st.top()->children.push_back(t);
            }else{
                root = t;
            }
            st.push(t);
        }
    }
    traversals(root);
}