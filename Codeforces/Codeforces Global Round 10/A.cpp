#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, mx;
    vector<int> p;
    cin >> t;
    while(t--){
        cin >> n;
        p.assign(n,0);
        mx = 0;
        for(int i=0;i<n;i++){
            cin >> p[i];
            mx = max(mx,p[i]);
        }
        int answ=n;
        for(int i=0;i<n;i++){
            if(p[i]!=mx){
                answ = 1;
            }
        }
        
        cout << answ <<'\n';
    }
}