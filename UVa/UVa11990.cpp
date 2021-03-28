#include<bits/stdc++.h>
#define ll long long 
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
#define maxn int(2e5+5)
using namespace std;

const int inf = 1e9;
ll cnt(vector<pair<int,int>> &arr, int x){
    int l = 0, r = arr.size()-1, answ=-1, med;
    while(l<=r){
        med = l + (r-l)/2;
        if(arr[med].first<=x){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ+1;
}

ll inversions(vector<vector<pair<int,int>>>& arr, pair<int,int> x, const int block){
    ll bx = x.second/block, answ = 0;
    for(int i=0;i<=bx-1;i++)
        answ += arr[i].size()-cnt(arr[i],x.first);
    for(int i=bx+1;i<arr.size();i++)
        answ += cnt(arr[i],x.first);
    for(auto p:arr[bx])
        answ += ((p.first>x.first && p.second<x.second) || (p.first<x.first && p.second>x.second));
    return answ;
}

int main(){
    int n, m;
    fastio();
    while(cin >> n >> m){
        vector<int> pos;
        vector<vector<pair<int,int>>> arr;
        ll inv = 0;

        const int block = 1000; //?
        pos.assign(n+1,0);
        for(int i=0, x;i<n;i++){
            if(i%block==0)
                arr.push_back(vector<pair<int,int>>());
            cin >> x, pos[x] = i, arr[i/block].push_back({x,i});
        }

        for(auto &x:arr)
            sort(x.begin(),x.end());

        for(int i=1;i<=n;i++)
            inv += inversions(arr,{i,pos[i]},block);
        
        inv/=2;
        for(int i=0, x;i<m;i++){
            cin >> x;
            cout << inv << '\n';
            inv -= inversions(arr,{x,pos[x]},block);
            int bx = pos[x]/block;
            for(int i=0;i<arr[bx].size()-1;i++)
                if(arr[bx][i].first==x)
                    swap(arr[bx][i],arr[bx][i+1]);
            arr[bx].pop_back();
        }
    }
    return 0;
}
