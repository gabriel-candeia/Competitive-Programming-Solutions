#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n, acm=0, x, m;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> x;
        if(x<=0) acm++;
    }
    if(acm>=m)
        cout << "YES\n";
    else
        cout << "NO\n";
    
    return 0;
}