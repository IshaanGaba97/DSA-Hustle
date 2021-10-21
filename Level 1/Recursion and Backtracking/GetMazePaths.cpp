#include<iostream>
#include<vector>
#include<string>
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    vector<string> hpaths = getMazePaths(sr, sc+1, dr, dc);
    vector<string> vpaths = getMazePaths(sr+1, sc, dr, dc);
    
    vector<string> paths;
    for(string path : hpaths)
    { 
        paths.push_back("h" + path);
    }
    for(string path : vpaths)
    {
        paths.push_back("v" + path);
    }
    return paths;
}

void display(vector<string>& arr){
    cout << "[";
    for(int i = 0;i < arr.size();i++){
        cout << arr[i];
        if(i < arr.size() -1) cout << ", ";
    }
    
    cout << "]"<<endl;
}


int main() {
    int n,m; cin >> n >> m;
    vector<string> ans = getMazePaths(0,0,n-1,m-1);
    display(ans);

    return 0;
}