#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, m;
    
    cin >> n >> m;
    vector<ll> a, b, c;

    a.assign(n+1,0);
    b.assign(m+1,0);
    c.assign(n+m+1,0);

    for(auto &x:a)
        cin >> x;

    for(auto &x:c)
        cin >> x;
    
    b[m] = c[n+m]/a[n];
    for(int i=m-1;i>=0;i--){
        b[i] = c[n+i];
        for(int j=i+1;j<=m && n+i-j>=0;j++){
            b[i] -= b[j]*a[n+i-j];
        }
        b[i] /= a[n];
    }

    for(int i=0;i<=m;i++){
        cout << b[i] << " ";
    }cout <<"\n";



    return 0;
}