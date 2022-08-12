#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int n;
    cin >> n;
    vector<int> dg(n+1,0);
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        dg[a]++, dg[b]++;
    }

    bool poss = true;
    int cnt = 0;
    for(int i=1;i<=n;i++){
        cnt+=(dg[i]<=2);
        poss = (poss && (dg[i]<=3));
    }
    if(poss==false)
        cnt = 0;
    cout << cnt <<"\n";

    return 0;
}