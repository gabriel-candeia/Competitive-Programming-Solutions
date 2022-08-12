#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e3+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int mat[maxn][maxn], nxt[maxn][maxn], down[maxn][maxn];

int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> mat[i][j];
                nxt[i][j] = down[i][j] = 0;
            }
        }   

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                nxt[i][j] = ((j+1<m && (mat[i][j]==mat[i][j+1])) ? (1 + nxt[i][j+1]) : 1);
                down[i][j] = ((i+1<n && (mat[i][j]==mat[i+1][j])) ? (1 + down[i+1][j]) : 1);
            }
        }

        ll answ = 0;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i+=down[i][j]){
                stack<pair<ll,ll>> st;
                ll sum = 0;
                for(int k=i+down[i][j]-1;k>=i;k--){
                    pair<ll,ll> novo = {nxt[k][j],1};
                    while(st.size() && novo.first<st.top().first){
                        sum -= st.top().first*st.top().second;
                        novo.second += st.top().second;
                        st.pop();
                    }
                    sum += novo.first*novo.second;
                    st.push(novo);
                    answ += sum;
                    //cout << k << " " << j << " " << sum <<"\n";
                }
                //cout << i << " " << j << " " << sum <<"\n";
                //answ += sum;
            }
        }

        cout << answ <<"\n";

    }
    return 0;
}