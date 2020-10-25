#include<bits/stdc++.h>
#define maxn 205
#define maxm 1000
using namespace std;

int mat[maxn][maxm], c[maxn], qtd[maxn];

int main(){
    int n, m;
    string s;
    map<string,int> mp;
    map<int,int> val;
    int cnt=0;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> s;
            if(mp.find(s)==mp.end()){
                mp[s] = cnt++;
            }
            mat[i][mp[s]]++;
            qtd[i] += (mat[i][mp[s]]==1);

            mat[n+j][mp[s]]++;
            qtd[n+j] += (mat[n+j][mp[s]]==1);
        }
        cin >> c[i];
    }

    for(int i=0;i<m;i++){
        cin >> c[n+i];
    }

    for(int x=0;x<n+m;x++){
        int i=0;
        for(i=0;i<n+m && qtd[i]!=1;i++);
        if(qtd[i]==0) break;

        int next = 0;
        for(next=0;next<mp.size() && mat[i][next]==0;next++);
    
        val[next] = c[i]/mat[i][next];
        for(int j=0;j<n+m;j++){
            qtd[j] -= (mat[j][next]!=0);
            c[j] -= mat[j][next]*val[next];
            mat[j][next] = 0;
        }
    }

    for(auto p:mp){
        cout << p.first << " " << val[p.second] <<'\n';
    }
    return 0;
}