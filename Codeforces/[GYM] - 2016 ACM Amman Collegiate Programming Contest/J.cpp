#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define maxn int(1e5+5)
#define maxm 1025
using namespace std;

int pref[maxn], answ[maxn], arr[maxn], n;
vector<tuple<int,int,int>> queries[maxm];

int canonical(int x){
    int answ = 0;
    for(int i=1;i<=10;i++)
        if(x%i==0)
            answ+= (1<<(i-1));
    return answ;
}

void construct(int x){
    pref[0] = 0;
    for(int i=1;i<=n;i++){
        pref[i] = ((arr[i] & x)!=0);
        pref[i] += pref[i-1];
    }
}

int main(){
    fastio();
    int t, q;
    cin >> t;
    while(t--){
        cin >> n >> q;
        for(int i=1;i<=n;i++){
            cin >> arr[i];
            arr[i] = canonical(arr[i]);
        }
        
        int l, r, x, id;
        for(int i=0;i<q;i++){
            cin >> l >> r >> x;
            queries[x].push_back({l,r,i});
        }

        for(int i=1;i<1024;i++){
            construct(i);
            for(auto e:queries[i]){
                tie(l,r,id) = e;
                answ[id] = pref[r]-pref[l-1];
            }
            queries[i].clear();
        }

        for(int i=0;i<q;i++){
            cout << answ[i] << '\n';
        }

    }

    return 0;
}