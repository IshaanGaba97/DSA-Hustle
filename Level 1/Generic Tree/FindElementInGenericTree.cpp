#include<iostream>
#include<stack>
#include<queue>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*>children;
    Node(){
        
    }
    Node(int data){
        this->data = data;
    }
};

void display(Node* node){
    string str = to_string(node->data) + " -> ";
    
    for(Node* child : node->children){
        str += to_string(child->data)+", ";
    }
    str+= ".";
    cout<<str<<"\n";
    
    for(Node* child : node->children){
        display(child);
    }
}

//find
bool find(Node* node, int data){
    if(node->data == data){
        return true;
    }
    for(Node* child : node->children){
        bool fic = find(child, data);
        if(fic){
            return true;
        }
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    // int arr[n];
    int* arr = new int(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int data;
    cin >> data;
    
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
    bool flag = find(root, data);
    if (flag == true) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
}