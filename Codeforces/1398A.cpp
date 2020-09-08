#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    vector<int> a;

    cin >> t;
    while(t--){
        cin >> n;
        a.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        if(a[n-1]>=a[0]+a[1]){
            cout << 1 << " " << 2 << " " << n << '\n';
        }
        else{
            cout << -1 <<"\n";
        }
    }

    return 0;
}
