#include<bits/stdc++.h>
#define maxin int(2e5+5)
#define ll long long
using namespace std;

struct node{
    node *l, *r;
    ll mx, mn;
    
    node(int mx=0, int mn=0){
        l = r = NULL;
        this->mx = mx, this->mn = mn;
    }

    node(node* l, node* r){
        this->l = l, this->r = r;
        mx = -1e18, mn = 1e18;
        if(l) mx = max(l->mx,mx), mn = min(l->mn,mn);
        if(l) mx = max(r->mx,mx), mn = min(r->mn,mn);
    }
};

node* build(int l, int r){
    if(l==r)
        return new node();
    int med = (l+r)/2;
    return new node(build(l,med),build(med+1,r));
}

node* update(node *last, int l, int r, int i, ll v){
    if(l==r)
        return new node(max(last->mx,v),min(last->mn,v));
    int med = (l+r)/2;
    if(i<=med)
        return new node(update(last->l,l,med,i,v), last->r);
    return new node(last->l, update(last->r,med+1,r,i,v));
}

int main(){
    int n;
    vector<pair<int,int>> arr;
    map<int,int> mp, indice;

    cin >> n;
    arr.assign(n,{0,0});
    for(auto &p:arr)
        cin >> p.first >> p.second, mp[p.first];

    int cnt = 0;
    for(auto &p:mp)
        p.second = cnt++;

    sort(arr.rbegin(),arr.rend());

    vector<node*> root;
    root.push_back(build(0,n));
    for(auto p:arr){
        root.push_back(update(root.back(),0,n,mp[p.first],p.second));
        indice[mp[p.first]] = root.size()-1;
    }

    ll answ = 0;
    for(auto p:arr){
        ll l=0,r=1e10, med, temp = -1;

        while(l<=r){
            med = (l+r)>>1;
            auto it = mp.lower_bound(p.first+med);
            ll maior = 0;
            if(it!=mp.end()){
                maior = max(abs(root[indice[(*it).second]]->mx-p.second),abs(root[indice[(*it).second]]->mn-p.second));
            }
            if(maior>=med){
                temp = med;
                l = med+1;
            }
            else{
                r = med-1;
            }
        }
        answ = max(answ,temp);
    }

    cout << answ << "\n";

    return 0;
}