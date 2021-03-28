#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int parent[maxn], rnk[maxn], sz[maxn], cnt[maxn];

void build(int n){
    for(int i=0;i<=n;i++)
        parent[i] = i;
}

int find(int x){
    return (parent[x]==x) ? x : parent[x] = find(parent[x]);
}

void _union(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y){
        if(rnk[x] > rnk[y])
            parent[y] = x;
        else{
            parent[x] = y;
            rnk[y] += (rnk[x]==rnk[y]);
        }
    }
}

int main(){
    int n, q;
    set<int> st;
    cin >> n >> q;

    build(maxn-1);
    vector<int> arr(n,0);
    for(auto &x:arr){
        cin >> x;
        sz[x]++;
        cnt[x]++;
    }

    for(int i=0;i<n-1;i++){
        cnt[arr[i]]--;
        if(cnt[arr[i]]){
            st.insert(arr[i]);
        }else{
            st.erase(arr[i]);
        }

        if(st.size()){
            _union(arr[i],arr[i+1]);
        }
    }

    int answ = n;
    for(int i=0;i<maxn;i++){
        sz[find(i)] = max(sz[find(i)],sz[i]);
    }

    for(int i=0;i<maxn;i++){
        if(i==parent[i] && sz[i]){
            answ -= sz[i];
        }
    }

    cout << answ <<'\n';

    return 0;
}