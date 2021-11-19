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
        dg[a]++, dg[b]++;
    }

    int answ = 0;
    for(int i=1;i<=n;i++){
        answ += (dg[i]==1);
    }

    cout << answ/2 + answ%2 <<"\n";


    return 0;
}