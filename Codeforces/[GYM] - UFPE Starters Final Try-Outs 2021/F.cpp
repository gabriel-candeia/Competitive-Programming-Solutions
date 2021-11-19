#include<bits/stdc++.h>
#define maxn int(2e5+1)
#define ll long long
using namespace std;

const ll base = 31, mod = 1e9+7;
ll st[2][4*maxn], pot[4*maxn];


ll build(const string &s, int k, int p, int l, int r){
    if(l==r)
        return st[k][p] = (s[l]-'a'+1);
    int med = l + (r-l)/2;
    return st[k][p] = ((build(s,k,2*p,l,med)*pot[r-med])%mod+build(s,k,2*p+1,med+1,r))%mod;
}

ll update(int k, int p, int l, int r, int pos, char v){
    if(l==r)
        return st[k][p] = (v-'a'+1);
    int med = l + (r-l)/2;
    if(pos<=med)
        return st[k][p] = ((update(k,2*p,l,med,pos,v)*pot[r-med])%mod+st[k][2*p+1])%mod;
    return st[k][p] = ((st[k][2*p]*pot[r-med])%mod+update(k,2*p+1,med+1,r,pos,v))%mod;
}

ll get(int k, int p, int l, int r, int i, int j){
    if(j<l || r<i)
        return 0;
    if(i<=l && r<=j)
        return st[k][p];
    int med = l + (r-l)/2;
    return st[k][p] = ((get(k,2*p,l,med,i,j)*pot[max(min(j-med,r-med),0)])%mod+get(k,2*p+1,med+1,r,i,j))%mod;
}

void precomp(){
    pot[0] = 1;
    for(int i=1;i<4*maxn;i++)
        pot[i] = (pot[i-1]*base)%mod;
}


int main(){
    int n, q;
    vector<string> arr;

    return 0;
}