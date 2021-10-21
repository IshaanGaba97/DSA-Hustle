#include<iostream>
#include<vector>
#include<string>
using namespace std;

// sr - source row
// sc - source column
// dr - destination row
// dc - destination column
// ms - move size
//paths - total paths
vector <string> getMazePaths(int sr, int sc, int dr, int dc) {
    if(sr == dr && sc == dc)
    {
        vector<string> base_case;
        base_case.push_back("");
        return base_case;
    }
    
    vector<string> paths;
    //horizontal moves
    for(int ms = 1; ms <= dc - sc; ms++)
    {
        vector<string> hpaths = getMazePaths(sr, sc+ms, dr, dc);
        for(string hpath : hpaths)
        {
            std::string s = std::to_string(ms);
            paths.push_back("h" + s + hpath);
        }
    }
    //vertical moves
    for(int ms = 1; ms <= dr - sr; ms++)
    {
        vector<string> vpaths = getMazePaths(sr+ms, sc, dr, dc);
        for(string vpath : vpaths)
        {
            std::string s = std::to_string(ms);
            paths.push_back("v" + s + vpath);
        }
    }
    
    //diagnol moves
    for(int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++)
    {
        vector<string> dpaths = getMazePaths(sr+ms, sc+ms, dr, dc);
        for(string dpath : dpaths)
        {
            std::string s = std::to_string(ms);
            paths.push_back("d" + s + dpath);
        }
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
    vector<string> ans = getMazePaths(0,0,n-1,m=1);
    display(ans);
    return 0;
}