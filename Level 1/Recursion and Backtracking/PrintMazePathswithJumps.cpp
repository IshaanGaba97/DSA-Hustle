#include<iostream>
#include<string>
using namespace std;


    void printMazePaths(int sr, int sc, int dr, int dc, string psf) {
        // write your code here
        if(sr == dr && sc == dc)
        {
            cout << psf << endl;
            return;
        }
        for(int ms = 1; ms <= dr - sr; ms++)
        {
            std::string s = std::to_string(ms);
            printMazePaths(sr, sc + ms, dr, dc, psf + "h" + s);
        }
        for(int ms = 1; ms <= dc - sc; ms++)
        {
            std::string s = std::to_string(ms);
            printMazePaths(sr + ms, sc, dr, dc, psf + "v" + s);
        }
        for(int ms = 1; ms <= dr - sr && ms <= dc - sc; ms++)
        {
            std::string s = std::to_string(ms);
            printMazePaths(sr + ms, sc + ms, dr, dc, psf + "d" + s);
        }
    }

int main() {
        int n;
        int m;
        cin>>n>>m;
        printMazePaths(1, 1, n, m, "");
    }