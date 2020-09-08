#include<bits/stdc++.h>
#define ld long double
using namespace std;

int main(){
    int n, s, x, y, cnt;
    vector<int> d;

    cin >> n >> s;
    d.assign(n+1,0);
    for(int i=1;i<n;i++){
        cin >> x >> y;
        d[x]++; d[y]++;
    }

    cnt = 0;
    for(int i=1;i<=n;i++){
        cnt += (d[i]==1);
    }
    
    ld answ = (2*s*1.0/cnt);
    printf("%.12Lf\n",answ);
    return 0;
}