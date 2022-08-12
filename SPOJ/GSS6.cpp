#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define lsone(x) (x&(-x))
#define maxn int(2e5+5)
using namespace std;

ll ft[maxn];

void update(int r, ll val){
    for(;r<maxn;r+=lsone(r)){
        ft[r] += val;
    }
}

ll get(int r){
    if(r==0) return 0;
    ll answ = 0;
    for(;r;r-=lsone(r))
        answ += ft[r];
    return answ;
}

/*int bb(int pos){
    int l = pos, r = maxn-1, answ = -1, med = 0;
    while(l<=r){
        med = l + (r-l)/2;
        if(get(med)<=med-pos){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    return answ;
}*/

int _bb(int x){
    if(x==0 && ft[0]==0) return 0;
    int answ = 0, acm = 0;
    for(int k=22;k>=0;k--){
        int pos = answ + (1<<k);
        if(pos<maxn && (ft[pos]+acm > pos-x)){
            acm += ft[pos];
            answ = pos;
        }
    }
    return answ+1;
}

struct noh{
    int suff = 0, preff = 0, mx = 0, sz = 0, sum = 0;
};

void combine(const noh& a,const noh& b, noh& c){
    if(a.sz==0){
        c = b;
        return;
    }
    if(b.sz==0){
        c = a;
        return;
    }
    c.sz = a.sz + b.sz;
    c.sum = a.sum + b.sum;
    c.suff = max(b.suff,b.sum+a.suff);
    c.preff = max(a.preff,a.sum+b.preff);
    c.mx = max({a.mx,b.mx,a.suff+b.preff});
}

noh st[4*maxn+5];
void update(int p, int l, int r, int i, int v, int f){
    if(l==r){
        st[p].suff = st[p].preff = st[p].sum = st[p].mx = v;
        st[p].sz = f;
        return;
    }
    int med = l + (r-l)/2;
    if(i<=med){
        update(2*p,l,med,i,v,f);
        combine(st[2*p],st[2*p+1],st[p]);
        return;
    }
    update(2*p+1,med+1,r,i,v,f);
    combine(st[2*p],st[2*p+1],st[p]);
    return;
}

noh nulo, resp;
noh get(int p, int l, int r, int i, int j){
    if(j<l || r<i)
        return nulo;
    if(i<=l && r<=j)
        return st[p];
    int med = l + (r-l)/2;
    combine(get(2*p,l,med,i,j),get(2*p+1,med+1,r,i,j),resp);
    return resp;
}

int kth(int p, int l, int r, int k){
    if(l==r)
        return l;
    int med = l + (r-l)/2;
    if(st[2*p].sz>=k)
        return kth(2*p,l,med,k);
    return kth(2*p+1,med+1,r,k-st[2*p].sz);
}

int main(){
    fastio();
    int n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    int q;
    vector<ll> answ;
    vector<array<ll,3>> queries;

    cin >> q;
    answ.assign(q,0);
    for(int i=0;i<q;i++){
        char op;
        int a, b;
        cin >> op;
        if(op=='I'){
            cin >> a >> b; a--;
            queries.push_back({op,a,b});
        }
        else if(op=='Q'){
            cin >> a >> b; 
            queries.push_back({op,a,b});
        }
        else if(op=='D'){
            cin >> a; 
            queries.push_back({op,a,0});
        }
        else if(op=='R'){
            cin >> a >> b;
            queries.push_back({op,a,b});
        }
    }
    
    for(int i=q-1;i>=0;i--){
        //cout << (queries[i][0]=='I') << " " << queries[i][1] << " " << queries[i][2] <<"\n";
        if(queries[i][0]=='I'){
            int nxt = _bb(queries[i][1]);
            update(nxt,1);
            queries[i][1] = nxt;
            //cout << nxt << " ";
        }
    }
    //cout <<"\n";

    //cout << get(4) << "\n";
    for(int i=0;i<n;i++){
        int start = _bb(i);
        //cout << i << " " << start <<", ";
        update(1,0,maxn-1,start,arr[i],1);
    }//cout<<"\n";

    for(int i=0;i<q;i++){
        char op = (char)queries[i][0];
        if(op=='I'){
            update(1,0,maxn-1,queries[i][1],queries[i][2],1);
        }
        else if(op=='Q'){
            int posL = kth(1,0,maxn-1,queries[i][1]), posR = kth(1,0,maxn-1,queries[i][2]);
            //cout << posL << " " << posR <<" ";
            cout << get(1,0,maxn-1,posL,posR).mx <<"\n";   
        }
        else if(op=='D'){
            int pos = kth(1,0,maxn-1,queries[i][1]);
            update(1,0,maxn-1,pos,0,0);
        }
        else if(op=='R'){
            int pos = kth(1,0,maxn-1,queries[i][1]);
            update(1,0,maxn-1,pos,queries[i][2],1);
            //cout <<"teste: "<< queries[i][2] << "\n";
        }
    }

    return 0;   
}