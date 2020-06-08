#include<bits/stdc++.h>
#define N int(5e5)+3
using namespace std;

int main(){
    int n, m;
    int a, b;
    vector<vector<int>> adj;
    vector<int> colors;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    cin >> n >> m;
    
    adj.assign(n+1,vector<int>());
    colors.assign(n+1,0);
    for(int i=0;i<m;i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for(int i=1;i<=n;i++){
        cin >> colors[i];
    }

    int arr[N];
    int ptr=0;
    bool poss = true;
    for(int v=1;v<=n && poss;v++){
        ptr = 0;
        arr[ptr++] = colors[v];
        for(auto w:adj[v]){
            if(colors[w]<colors[v]){
                arr[ptr++] = colors[w];
            }
            else if(colors[w]==colors[v]){
                poss = false;
                break;
            }
        }
        sort(arr,arr+ptr);
        if(arr[0]!=1){
            poss = false;
            break;
        }
        for(int i=1;i<ptr;i++){
            if(arr[i]-arr[i-1]>1){
                poss = false;
                break;
            }
        }
    }

    if(poss){
        vector<pair<int,int>> answ;
        for(int i=1;i<=n;i++){
            answ.push_back(make_pair(colors[i],i));
        }  
        sort(answ.begin(),answ.end());
        for(auto p:answ){
            cout << p.second << ' ';
        }
        cout << '\n';
    }
    else{
        cout << -1 <<'\n';
    }

    return 0;
}