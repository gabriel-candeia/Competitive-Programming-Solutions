#include<bits/stdc++.h>
#define ll long long
#define N 3005
using namespace std;

ll mat[N][N];

int main(){
    ll t, n;
    vector<ll> a, cnt;

    cin >> t;
    while(t--){
        cin >> n;
        a.assign(n,0);
        cnt.assign(n+1,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                mat[i][j] = 0;
            }   
        }
        ll answ = 0;
        for(int j=n-1;j>=0;j--){
            for(int i=j-1;i>=0;i--){
                answ += mat[a[i]][a[j]];
            }  
            for(int i=0;i<=n;i++){
                mat[a[j]][i] += cnt[i];
            }
            cnt[a[j]]++;
        }
        cout << answ << '\n';
    }

    return 0;
}