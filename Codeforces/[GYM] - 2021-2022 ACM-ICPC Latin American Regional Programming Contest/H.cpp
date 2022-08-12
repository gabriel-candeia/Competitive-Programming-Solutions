#include <bits/stdc++.h>
#define ll long long
using namespace std;
//input: matrix n x m, n <= m
//return vector p of size n, where p[i] is the match for i
// and minimum cost
// time complexity: O(n^2 * m)
const ll ms = 310, INF = 0x3f3f3f3f;
ll u[ms], v[ms], p[ms], way[ms], minv[ms];
bool used[ms];
pair<vector<ll>, ll> solve(const vector<vector<ll>> &matrix){
  ll n = matrix.size();
  if (n == 0)
    return {vector<ll>(), 0};
  ll m = matrix[0].size();
  assert(n <= m);
  memset(u, 0, (n + 1) * sizeof(ll));
  memset(v, 0, (m + 1) * sizeof(ll));
  memset(p, 0, (m + 1) * sizeof(ll));
  for (ll i = 1; i <= n; i++){
    memset(minv, 0x3f, (m + 1) * sizeof(ll));
    memset(way, 0, (m + 1) * sizeof(ll));
    for (ll j = 0; j <= m; j++)
      used[j] = 0;
    p[0] = i;
    ll k0 = 0;
    do{
      used[k0] = 1;
      ll i0 = p[k0], delta = INF, k1 = 0;
      for (ll j = 1; j <= m; j++){
        if (!used[j]){
          ll cur = matrix[i0 - 1][j - 1] - u[i0] - v[j];
          if (cur < minv[j]){
            minv[j] = cur;
            way[j] = k0;
          }
          if (minv[j] < delta){
            delta = minv[j];
            k1 = j;
          }
        }
      }
      for (ll j = 0; j <= m; j++){
        if (used[j]){
          u[p[j]] += delta;
          v[j] -= delta;
        }else{
          minv[j] -= delta;
        }
      }
      k0 = k1;
    } while (p[k0]);
    do{
      ll k1 = way[k0];
      p[k0] = p[k1];
      k0 = k1;
    } while (k0);
  }
  vector<ll> ans(n, -1);
  for (ll j = 1; j <= m; j++){
    if (!p[j]) continue;
    ans[p[j] - 1] = j - 1;
  }
  return {ans, -v[0]};
}

int main(){
    ll n, oldn;
    vector<vector<ll>> mat, wt;

    cin >> n; oldn = n;
    if(n%2) n++;
    mat.assign(n/2,vector<ll>(n/2,0));
    wt.assign(n,vector<ll>(n,0));
    for(ll i=0;i<oldn;i++)
        for(ll j=0;j<oldn;j++)
            cin >> wt[i][j];

    for(ll i=0;i<n;i+=2){
        for(ll j=1;j<n;j+=2){
            ll a = i/2, b = (j-1)/2;
            mat[b][a] = wt[i][j] + ((j-2>=0) ? wt[j-2][i] : 0);
        }
    }

    auto aux = solve(mat);

    cout << aux.second <<"\n";
    
    return 0;
}

/*0 2 4
0 1 2

1 3
0 1*/
