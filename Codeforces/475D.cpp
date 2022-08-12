#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e5+5)
#define LOG 21
using namespace std;

int n, st[maxn][LOG], lg[maxn];
vector<int> arr;

void precomp(){
    for(int i=2;i<maxn;i++){
        lg[i] = lg[i/2] + 1;
    }

    for(int i=0;i<n;i++){
        st[i][0] = arr[i];
    }

    for(int k=1;k<LOG;k++){
        for(int i=0;i+(1<<k)<=n;i++){
            st[i][k] = __gcd(st[i][k-1],st[i+(1<<(k-1))][k-1]);
        }
    }
}

int get(int l, int r){
    if(l>r) return -1;
    int k = lg[r-l+1];
    return __gcd(st[l][k],st[r-(1<<k)+1][k]);
}

int bb(int a, int x){
    int l=a, r=n-1, med, answ=a;
    while(l<=r){
        med = l + (r-l)/2;
        if(get(a,med)>=x){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

int main(){
    map<int,ll> mp;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    precomp();

    for(int i=0;i<n;i++){
        vector<ll> id, val;
        int j = i, curr = arr[i];
        do{
            curr = get(i,j);
            val.push_back(curr); 
            j = bb(i,curr);
            id.push_back(j);
            j = j+1;
        }while(j!=n);
        
/*        cout << i << ":\n";
        for(auto x:id){
            cout << x << " ";
        }cout<<"\n";
        for(auto x:val){
            cout << x << " ";
        }cout<<"\n";*/

        id.push_back(n);
        ll last = i;
        for(int i=0;i<val.size();i++){
            mp[val[i]] += (id[i]-last+1);
            last = id[i]+1;
        }
    }

    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << mp[x] <<"\n";
    }

    return 0;
}