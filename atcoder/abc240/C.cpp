#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n, x;
    vector<bool> pos;
    vector<int> a, b;

    cin >> n >> x;
    a.assign(n,0), b.assign(n,0), pos.assign(x+1,0);

    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    pos[0] = 1;
    for(int i=0;i<n;i++){
        for(int j=x;j>=0;j--){
            if(j+a[i]<=x){
                pos[j+a[i]] = pos[j+a[i]]||pos[j];
            }
            if(j+b[i]<=x){
                pos[j+b[i]] = pos[j+b[i]]||pos[j];
            }
            pos[j] = 0;
        }
    }

    cout << ((pos[x]) ? "Yes" : "No") <<"\n";

    return 0;
}