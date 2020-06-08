#include<bits/stdc++.h>
using namespace std;

const int INF = int(1e8);

int main(){
    int n, m, l, r, dist=INF, a, b;


    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        if(b-a+1<dist){
            dist = b-a+1;
            l = a-1;
            r = b-1;
        }
    }

    int start = (-l)%dist;
    if(start<0){
        start+=dist;
    }

    cout << dist << '\n';
    for(int i=0;i<n;i++){
        cout << start << ' ';
        start = (start+1)%dist;
    }
    cout << '\n';

    return 0;
}