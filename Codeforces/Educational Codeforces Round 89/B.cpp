#include<bits/stdc++.h>
using namespace std;


int main(){
    int t;
    cin >> t;

    while(t--){
        int n, x, m, l, r, answl, answr;
        cin >> n >> x >> m;
        answl = x;
        answr = x;

        for(int i=0;i<m;i++){
            cin >> l >> r;
            if(answr < l || answl > r){
                continue;
            }
            else{
                answr = max(answr,r);
                answl = min(answl,l);
            }
        }

        cout << answr-answl+1 << '\n';
    }
    return 0;
}