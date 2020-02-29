#include<bits/stdc++.h>
#define N 1000
using namespace std;

int main(){
    int t, n, x, y, m;

    cin >> t;
    while(t--){
        map<pair<int,int>,bool> edges;
        int multiedges=0;

        cin >> n >> n >> m;
        for(int i=0;i<m;i++){
            cin >> x >> y;
            if(y<x){
                x = x^y;
                y = x^y;
                x = x^y;
            }
            multiedges+=(edges[make_pair(x,y)]);
            edges[make_pair(x,y)] = true;    
        }
        cout << 2*(m-multiedges) << '\n';
    }

    return 0;
}
