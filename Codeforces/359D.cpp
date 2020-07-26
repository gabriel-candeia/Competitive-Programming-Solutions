#include<bits/stdc++.h>
#define N int(1e6)+5
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int n;
vector<int> st, A;
vector<int> mp;

int gcd(int a, int b){ return (b==0 ? a : gcd(b,a%b));}
int left(int x){ return (x<<1);}
int right(int x){ return (x<<1)+1;}

void build(int p, int l, int r){
    if(l==r){
        st[p] = A[l];
        return;
    }
    build(left(p),l,(l+r)/2);
    build(right(p),(l+r)/2+1,r);
    st[p] = gcd(st[left(p)],st[right(p)]);
}

int query(int p, int l, int r, int i, int j){
    if(j<l || r<i){
        return -1;
    }
    else if(i<=l && r<=j){
        return st[p];
    }
    int p1, p2;
    p1 = query(left(p),l,(l+r)/2,i,j);
    p2 = query(right(p),(l+r)/2+1,r,i,j);

    if(p1==-1) return p2;
    if(p2==-1) return p1;
    return gcd(p1,p2);
}

int query(int l, int r){
    return query(1,0,n-1,l,r);
}

vector<int> p;

bool isOk(int x){
    mp.assign(N,0);
    vector<int> val;
    int cnt=0;

    for(int i=0;i<=x;i++){
        mp[A[i]] = true;
    }

    if(mp[query(0,x)]){
        cnt++;
        val.push_back(0);
    }

    for(int i=1;i+x<n;i++){   
        mp[A[i-1]]--;
        mp[A[i+x]]++;
        if(mp[query(i,i+x)]){
            cnt++;
            val.push_back(i);
        }
    }

    if(cnt!=0){
        p.clear();
        for(auto x:val){
            p.push_back(x);
        }
    }

    return cnt!=0;
}

void init(){
    st.assign(4*n+4,0);
    build(1,0,n-1);
}


int main(){
    fastIO();

    cin >> n;   
    A.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> A[i];
    }

    init();
    
    int l=0, r=n-1, med, answ=-1;
    while(l<=r){
        med = l+(r-l)/2;
        if(isOk(med)){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }

    cout << p.size() << " " << answ << '\n';
    for(auto x:p){
        cout << x+1 << " ";
    }cout << '\n';

    return 0;
}