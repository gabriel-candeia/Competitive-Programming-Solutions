#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct Partition{
    ll valor;
    vector<ll> best, top;
    vector<bool> locked;

    Partition(){

    }

    Partition(ll pvalor, vector<ll> pbest, vector<ll> ptop, vector<bool> plocked){
        valor = pvalor, best = pbest, top = ptop, locked = plocked;
    }
};

bool operator<(const Partition& a, const Partition& b){
    return a.valor<b.valor;
}

int n;
vector<vector<ll>> arr;

Partition criar(vector<ll> top, vector<bool> locked){
    ll valor = 0;
    vector<ll> best(n,0);

    for(int i=0;i<n;i++){
        valor += arr[i][top[i]-1];
        best[i] = top[i];
    }

    return Partition(valor,best,top,locked);
}

int main(){
    cin >> n;
    arr.assign(n,vector<ll>());
    set<vector<ll>> blocked;

    for(int i=0;i<n;i++){
        int siz;
        cin >> siz, arr[i].assign(siz,0);
        for(auto &x:arr[i])
            cin >> x;
    }

    int m;
    cin >> m;
    for(int i=0;i<m;i++){
        vector<ll> build(n,0);
        for(auto &x:build)
            cin >> x;
        blocked.insert(build);
    }

    vector<ll> top(n,0);
    vector<bool> locked(n,0);
    
    for(int i=0;i<n;i++){
        top[i] = arr[i].size();
    }

    priority_queue<Partition> pq;
    pq.push(criar(top, locked));
    Partition u;
    while(pq.size()){
        u = pq.top(), pq.pop();
        if(blocked.find(u.best)==blocked.end())
            break;

        for(int i=0;i<n;i++){
            if(u.locked[i]==false){
                top = vector<ll>(u.top.begin(),u.top.end());
                locked = vector<bool>(u.locked.begin(),u.locked.end());
                for(int j=0;j<i;j++){
                    locked[j] = 1;
                }
                top[i]--;
                if(top[i]>0){
                    Partition nova = criar(top,locked);
                    pq.push(nova);
                }
            }
        }
    }

    for(auto x:u.best)
        cout << x << " ";
    cout<<"\n";

    return 0;
}