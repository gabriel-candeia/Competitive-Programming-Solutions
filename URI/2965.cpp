#include<bits/stdc++.h>
#define N int(1e5)+5
using namespace std;

int computeHeights(int parent[N], vector<int>& h, int i){
    if(h[i]==-1){
        return (h[i] = computeHeights(parent,h,parent[i])+1);
    }
    return h[i];
}

int kill(int parent[N], vector<int>& h, int i){
    if(h[i]==-1){
        return 0;
    }
    h[i] = -1;
    return (1+kill(parent,h,parent[i]));
}

int main(){
    int n, k, parent[N];
    vector<int> dg, h, dead;
    vector<pair<int,int>> leaves;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    parent[0] = 0; parent[1] = 0;
    dg.assign(n+1,0);
    h.assign(n+1,-1); h[1] = 1;

    for(int i=2;i<=n;i++){
        cin >> parent[i];
        dg[parent[i]]++;
    }

    for(int i=1;i<=n;i++){
        if(dg[i]==0){
            computeHeights(parent,h,i);
            leaves.push_back(make_pair(-h[i],i));
        }
    }

    sort(leaves.begin(),leaves.end());
    int answ = 0;
    for(int i=0;i<leaves.size();i++){
        dead.push_back(kill(parent,h,leaves[i].second));
    }
    sort(dead.rbegin(),dead.rend());
    for(int i = 0;i<k;i++){
        if(i<dead.size()){
            answ+=dead[i];
        }
    }
    cout << answ << '\n';

    return 0;
}
