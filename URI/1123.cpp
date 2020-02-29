#include<bits/stdc++.h>
#define N 500
#define K 10000
using namespace std;

int dist(vector<pair<int,int>> adj[N], int n, int k, int c){
    vector<int> distance; distance.assign(n+1,INT_MAX);
    int q[K], tail=0, head=0, z;

    q[tail++] = k;
    distance[k] = 0;
    while(tail!=head){
        z = q[head++];
        if(z==c-1){ continue;}
        for(auto i:adj[z]){
            if((z<c && i.first==z+1 && distance[z]+i.second < distance[i.first]) || (z>=c && distance[z]+i.second < distance[i.first])){
                q[tail++] = i.first;
                distance[i.first] = distance[z]+i.second;
            }
        }
    }
    return distance[c-1];
}

int main(){
    int n, m, c, k;
    int x, y, z;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>n>>m>>c>>k && k){
        vector<pair<int,int>> adj[N];

        while(m--){
            cin >> x >> y >> z;
            adj[x].push_back(make_pair(y,z));
            adj[y].push_back(make_pair(x,z));
        }
        cout << dist(adj,n,k,c) << '\n';
    }


    return 0;
}

