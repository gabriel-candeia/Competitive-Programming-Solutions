#include<bits/stdc++.h>
#define N 5001
using namespace std;

int main(){
    int n, f[N];

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> f[i];
    }

    for(int i=1;i<=n;i++){
        if(f[f[f[i]]]==i){
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}