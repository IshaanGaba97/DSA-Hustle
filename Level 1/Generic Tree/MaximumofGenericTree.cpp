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

//maximum
int maximum(Node* node){
    int maxi = INT_MIN;
    for(Node* child : node->children){
        int cm = maximum(child);
        maxi = max(cm, maxi);
    }
    maxi = max(node->data, maxi);
    return maxi;
}


int main(){
    // int arr[]={10,20,50,-1,60,-1,-1,30,70,-1,80,110,-1,100,-1,-1,90,-1,-1,40,100,-1,-1,-1};
    // int n = 24;
    int n;
    cin>>n;
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
    cout << maximum(root);
}