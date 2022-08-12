#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct DSU{
    int cc = 0;
    vector<int> parent, rnk;

    DSU(int n){
        parent.assign(n+1,0);
        for(int i=1;i<=n;i++)
            parent[i] = i;
        rnk.assign(n,0);
        cc = n;
    }

    int find(int x){
        return (x==parent[x]) ? x : parent[x] = find(parent[x]);
    }

    bool _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            cc--;
            if(rnk[x]<rnk[y]){
                parent[x] = y;
            }
            else{
                parent[y] = x;
                rnk[x] += (rnk[y]==rnk[x]);
            }
            return true;
        }
        return false;
    }
};

int main(){
    int n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    map<ll,vector<int>> mp;
    for(int i=0;i<n;i++){
        if(arr[i])
            mp[-arr[i]].push_back(i);
    }


    DSU st(n);
    int answ = 0, agua = n;
    for(auto p:mp){
        for(auto x:p.second){
            if(x-1>=0 && arr[x-1]>=arr[x]){
                st._union(x,x-1);
            }
            if(x+1<n && arr[x+1]>=arr[x]){
                st._union(x,x+1);
            }
            agua--;
        }
        answ = max(answ,st.cc-agua);
    }

    cout << answ <<"\n";

    return 0;   
}