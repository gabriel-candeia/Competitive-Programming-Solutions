#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll lim = 1e8;
int k, n;
vector<ll> arr;

struct noh{
    ll sum, qtd;
    noh *l, *r;

    noh(){
        sum = qtd = 0, l = r = 0;
    }
};

void update(noh *p, int l, int r, int i, ll v1, ll v2){
    if(l==r){   
        p->sum += v1, p->qtd+=v2;
        return;
    }
    ll med = l + (r-l)/2;
    if(i<=med){
        if(p->l==NULL) p->l = new noh();
        update(p->l,l,med,i,v1,v2);
    }
    else{
        if(p->r==NULL) p->r = new noh();
        update(p->r,med+1,r,i,v1,v2);
    }
    p->sum = ((p->l!=NULL) ? p->l->sum : 0) + ((p->r!=NULL) ? p->r->sum : 0);
    p->qtd = ((p->l!=NULL) ? p->l->qtd : 0) + ((p->r!=NULL) ? p->r->qtd : 0);
}

pair<ll,ll> combine(pair<ll,ll> a, pair<ll,ll> b){
    return {a.first+b.first,a.second+b.second};
}

pair<ll,ll> get(noh *p, int l, int r, int i, int j){
    if(j<l || r<i || p==NULL){
        return {0,0};
    }
    if(i<=l && r<=j){
        return {p->sum, p->qtd};
    }
    int med = l + (r-l)/2;
    return combine(get(p->l,l,med,i,j),get(p->r,med+1,r,i,j));
}

bool naocasa(int k, int i, int l, bool flag = false){
    if(l<i) swap(i,l);
    return ((l-i+1>k) || (k-(l-i+1))%2==1 || (k-(l-i+1))/2>(i) || (k-(l-i+1))/2>(n-1-l));
}

int main(){
    cin >> n >> k;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    noh *root = new noh();
    
    
    ll answ = 0;
    
    for(int start = 0;start<=1;start++){
        root = new noh();
        int i = start, l = k-1-start, r = k-1-start;
        if(l<n)
            update(root,-lim,+lim,arr[l],arr[l],1);

        for(;i<n;i+=2){
            while(r+2<n && !naocasa(k,i,r+2)){
                r+=2;
                update(root,-lim,lim,arr[r],arr[r],1);
            }
            while(l-2>=0 && !naocasa(k,i,l-2)){
                l-=2;
                update(root,-lim,lim,arr[l],arr[l],1);
            }
            while(l<r && naocasa(k,i,l)){
                update(root,-lim,lim,arr[l],-arr[l],-1);
                l+=2;
            }
            while(l<r && naocasa(k,i,r)){
                update(root,-lim,lim,arr[r],-arr[r],-1);
                r-=2;
            }
            //cout << i << " " << l << " " << r<<"\n";
            auto p = get(root,-lim,+lim,arr[i],lim);
            //cout << i << " " << p.first << " " << p.second <<"\n";
            answ += p.first - arr[i]*p.second;
            p = get(root,-lim,+lim,-lim,arr[i]);
            //cout << i << " " << p.first << " " << p.second <<"\n";
            answ += arr[i]*p.second-p.first;
            
            //cout << answ <<"\n";
            /*cout << l << " " << r<<"\n";
            cout <<"\n";*/
            //cout <<"\n";
            //add
            //cout <<"\n";

            //remove
        }
    }
    if(k==1) answ = 0;
    cout << answ/2 <<"\n";

    return 0;
}