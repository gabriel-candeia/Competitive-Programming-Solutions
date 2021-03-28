#include<bits/stdc++.h>
#define maxn int(1e6+5)
#define block 500
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

ll freq[maxn];

struct query{
    int l, r, id;

    query(int l, int r ,int id){
        this->l = l, this->r = r, this->id = id;
    }

    bool operator<(query x){
        return pair<int,int>{l/block,r} < pair<int,int>{x.l/block,x.r};
    }
};

int main(){
    fastio();
    int n, t;
    vector<ll> arr, answ;
    vector<query> queries;

    cin >> n >> t;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    for(int i=0;i<t;i++){
        int l, r;
        cin >> l >> r;
        queries.push_back(query(l-1,r-1,i));
    }

    answ.assign(t,0);
    sort(queries.begin(),queries.end());

    ll cnt = 0;
    int l=0, r = -1;
    for(auto q:queries){
        while(l<q.l){
            cnt += arr[l]*(-2*freq[arr[l]]+1);
            freq[arr[l]]--;
            l++;
        }
        while(l>q.l){
            l--;
            cnt += arr[l]*(2*freq[arr[l]]+1);
            freq[arr[l]]++;
        }
        while(r>q.r){
            cnt += arr[r]*(-2*freq[arr[r]]+1);
            freq[arr[r]]--;
            r--;
        }
        while(r<q.r){
            r++;
            cnt += arr[r]*(2*freq[arr[r]]+1);
            freq[arr[r]]++;
        }
        answ[q.id] = cnt;
    }

    for(auto x:answ)
        cout << x << "\n";
    return 0;
}