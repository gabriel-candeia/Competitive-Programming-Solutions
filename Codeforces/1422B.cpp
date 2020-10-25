#include<bits/stdc++.h>
#define maxn 105
#define ll long long
using namespace std;

ll mat[maxn][maxn], grid[maxn][maxn], n, m;

int main(){
    ll t;

    cin >> t;
    while(t--){
        cin >> n >> m;
        for(ll i=0;i<n;i++)
            for(ll j=0;j<m;j++){
                cin >> mat[i][j];
                grid[i][j] = mat[i][j];
            }

        for(ll i=0;i<n/2+n%2;i++){
            for(ll j=0;j<m/2+m%2;j++){
                ll arr[4] = {mat[i][j],mat[i][m-j-1],mat[n-i-1][j],mat[n-i-1][m-j-1]};
                sort(arr,arr+4);
                grid[i][j] = grid[i][m-j-1] = grid[n-i-1][j] = grid[n-i-1][m-j-1] = arr[1];
            }
        }

        ll answ=0;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                answ+=abs(grid[i][j]-mat[i][j]);
        //        cout << grid[i][j];
            }
          //  cout <<'\n';
        }
        cout << answ <<'\n';
        //cout<<'\n';
    }
    return 0;
}