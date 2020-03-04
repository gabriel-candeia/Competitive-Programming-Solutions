#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, x, y;

    while(cin >> n >> m){
        map<pair<int,int>,int> answ;
        map<int,int> cont;

        for(int i=1;i<=n;i++){
            cin >> x;
            answ[make_pair(x,++cont[x])] = i;
        }
        while(m--){
            cin >> x >> y;
            cout << answ[make_pair(y,x)] << '\n';
        }
    }

    return 0;
}