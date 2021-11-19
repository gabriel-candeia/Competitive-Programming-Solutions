#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> dg;

    cin >> n;
    dg.assign(n+1,0);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        dg[a]++;
        dg[b]++;
    }

    bool ok = false;
    for(int i=1;i<=n;i++){
        if(dg[i]==n-1)
            ok = true;
    }

    if(ok)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}