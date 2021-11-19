#include<bits/stdc++.h>
#define maxm 30
#define ll long long
using namespace std;

ll l, r;
int n;
vector<int> arr, lg;
vector<vector<int>> st;

int gcd(int a, int b){
    return (b==0) ? a : gcd(b,a%b);
}

void build(){
    lg.assign(n+1,0);
    st.assign(n,vector<int>(maxm,0));

    lg[1] = 0;
    for(int i=2;i<=n;i++) 
        lg[i] = lg[i>>1]+1;

    for(int i=0;i<n;i++){
        st[i][0] = arr[i];
    }

    for(int k=1;k<maxm;k++){
        for(int i=0;(i+(1<<k))<=n;i++){
            st[i][k] = gcd(st[i][k-1],st[i+(1<<(k-1))][k-1]);
        }
    }
}

int query(int i, int j){
    int k = lg[j-i+1];
    return gcd(st[i][k],st[j-(1<<k)+1][k]);
}

ll bb(int i, int x){
    ll l = i, r = n-1, med, answ=i-1;
    while(l<=r){
        med = (l+r)>>1;
        if(query(i,med)>=x){
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
    cin >> n >> l >> r;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;
    build();
    
    ll answ = 0;
    for(int i=0;i<n;i++){
        ll ub = r, j, last = i;

        j = bb(i,ub+1);
        last = j+1; 
        ub = query(i,j+1);
        
        while(true){
            j = bb(i,ub);
            answ += (j-last+1)*(r-max(ub,l)+1);
            if(j+1==n) break;
            last = j+1;
            ub = query(i,j+1);
        }
    }

    cout << answ <<"\n";
    return 0;
}
