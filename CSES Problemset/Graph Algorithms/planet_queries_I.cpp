#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define LOG 32
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int n, q, p[maxn][LOG], x, d;

int main(){
    fastio();
    cin >> n >> q;  
    
    for(int i=1;i<=n;i++)
        cin >> p[i][0];

    for(int k=1;k<LOG;k++)
        for(int i=1;i<=n;i++)
            p[i][k] = p[p[i][k-1]][k-1];

    for(int i=0;i<q;i++){
        cin >> x >> d;
        for(int k=LOG-1;k>=0;k--)
            if(d>=(1ll<<k))
                d-=(1<<k), x = p[x][k];
        cout << x << "\n";
    }

    return 0;
}
