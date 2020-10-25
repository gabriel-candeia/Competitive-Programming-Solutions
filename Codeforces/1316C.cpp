#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int n, m, p;
    vector<int> a, b;

    cin >> n >> m >> p;
    a.assign(n,0);
    b.assign(m,0);


    int ans=0;
    for(auto &x:a){
        cin >> x;
    }

    for(auto &x:b){
        cin >> x;
    }

    for(int i=0;i<n;i++){
        if(a[i]%p){
            ans+=i;
            break;
        }
    }

    for(int i=0;i<m;i++){
        if(b[i]%p){
            ans+=i;
            break;
        }
    }

    cout << ans <<'\n';
    return 0;   
}