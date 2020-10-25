#include<bits/stdc++.h>
#define maxn 300
using namespace std;

char grid[maxn][maxn];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin >> grid[i][j];
        
        vector<pair<int,int>> answ;
        if(grid[0][1]==grid[1][0]){
            if(grid[n-1][n-2]==grid[0][1])
                answ.push_back({n-1,n-2});
            if(grid[n-2][n-1]==grid[0][1])
                answ.push_back({n-2,n-1});
        }
        else if(grid[n-1][n-2]==grid[n-2][n-1]){
            if(grid[n-1][n-2]==grid[0][1])
                answ.push_back({0,1});
            if(grid[n-1][n-2]==grid[1][0])
                answ.push_back({1,0});
        }
        else{
            answ.push_back({1,0});
            if(grid[n-1][n-2]==grid[0][1])
                answ.push_back({n-1,n-2});
            if(grid[n-2][n-1]==grid[0][1])
                answ.push_back({n-2,n-1});
        }
        cout << answ.size() << "\n";
        for(auto p:answ){
            cout << p.first+1 << " " << p.second+1 <<'\n';
        }
    }

    return 0;
}