#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    unordered_map<string, int> umap;
    
    umap["India"] = 30;
    umap["China"] = 40;
    umap["US"] = 20;
    umap["UK"] = 100;
    
    //printing hashmap
    for(auto x : umap){
        cout << x.first << " " << x.second << endl;
    }
    
    //adding new values
    umap["Nigeria"] = 60;
    umap["India"] = 50;
    umap["Germany"] = 46;
    
    
    for(auto x : umap){
        cout << x.first << " " << x.second << endl;
    }
    
    cout << endl;
    
    //method 1 to find
    string key = "Germany";
    if(umap.find(key) == umap.end()){
        cout << "Not Found" << endl;
    } else {
        cout << "Found" << endl;
    }
    
    //method 2 to find
    cout << "Finding Germany -> " << umap.count(key) << endl;
    
    //erase
    umap.erase(key);
    cout << endl;
    for(auto x : umap){
        cout << x.first << " " << x.second << endl;
    }
    
}