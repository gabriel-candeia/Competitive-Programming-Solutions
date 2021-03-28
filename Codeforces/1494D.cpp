#include<bits/stdc++.h>
#define maxn 505
using namespace std;

int n, ptr;
vector<int> cost, parent;
vector<pair<int,int>> arr[maxn];

void alg(int u, int lim, int p){
    int current = u;
    for(int i=0;i<arr[u].size() && arr[u][i].first < lim; i++){  
        if(i==0 || arr[u][i].first != arr[u][i-1].first){
            parent[current] = ptr;
            current = ptr++;
            cost[current] = arr[u][i].first;
        }
        if(parent[arr[u][i].second]==-1){
            alg(arr[u][i].second,arr[u][i].first,current);
        }
    }
    parent[current] = p;
}

int main(){
    cin >> n;

    int w;
    cost.assign(max(n*n+1,2*n),0); parent.assign(max(n*n+1,2*n),-1); ptr = n+1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> w;
            if(i!=j)
                arr[i].push_back({w,j});
            else
                cost[i] = w;
        }
    }

    for(int i=1;i<=n;i++){
        sort(arr[i].begin(),arr[i].end());
    }

    alg(1,1e8,-1);

    int mx = 0;
    cout << ptr-1 << "\n";
    for(int i=1;i<ptr;i++){
        cout << cost[i] << " ";
        if(cost[i] > cost[mx])
            mx = i;
    }
    cout<<'\n';
    cout << mx << "\n";
    for(int i=1;i<ptr;i++)
        if(parent[i]!=-1)
            cout << i << " " << parent[i] << "\n";  

    return 0;
}