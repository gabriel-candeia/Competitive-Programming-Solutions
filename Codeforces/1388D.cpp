#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<ll> a, b, visited, ord;
void dfs(int u){
    visited[u] = 1;
    if(b[u]!=-1 && !visited[b[u]])
        dfs(b[u]);  
    ord.push_back(u);
}


int main(){
    int n;

    cin >> n;
    a.assign(n+1,0), b.assign(n+1,0);

    for(int i=1;i<=n;i++)
        cin >> a[i];

    for(int i=1;i<=n;i++)
        cin >> b[i];

    visited.assign(n+1,false);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }

    ll answ = 0;
    vector<int> first, lst;
    for(int i=n-1;i>=0;i--){
        answ += a[ord[i]];
        if(a[ord[i]]>=0 && b[ord[i]]!=-1){
            a[b[ord[i]]]+=a[ord[i]];
            first.push_back(ord[i]);
        }
        else{
            lst.push_back(ord[i]);
        }
    } 

    cout << answ <<'\n';
    for(auto x:first)
        cout << x << " ";
    for(int i =lst.size()-1;i>=0;i--)
        cout << lst[i] << " ";
    cout <<'\n';
    return 0;
}