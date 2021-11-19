#include <bits/stdc++.h>
using namespace std;

int k, n;
string s;

struct rmq{
    vector<vector<int>> st;
    vector<int> lg;
    
    rmq(){
        int n = s.size();
        lg.assign(n+1,0);
        for(int i=2;i<=n;i++) lg[i] = lg[i/2]+1;

        st.assign(n,vector<int>(lg[n]+1,0));
        for(int i=0;i<n;i++) st[i][0] = i;

        for(int k=1;k<=lg[n];k++){
            for(int i=0;i+(1<<k)<=n;i++){
                if(s[st[i][k-1]]<=s[st[i+(1<<(k-1))][k-1]])
                    st[i][k] = st[i][k-1];
                else
                    st[i][k] = st[i+(1<<(k-1))][k-1];
            }
        }
        
    }

    int get(int l, int r){
        if(r<l) return -1;
        int k = lg[r-l+1];
        
        if(s[st[l][k]]<=s[st[r-(1<<k)+1][k]])
            return st[l][k];
        return st[r-(1<<k)+1][k];
    }
};

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    cin >> s >> k;
    n = s.size();
    
    rmq alg = rmq();
    int last = -1;
    string answ;
    for(int i=0;n-k+i<n && last+1<n;i++){
        last = alg.get(last+1,n-k+i);
        answ += s[last];
    }
    cout << answ <<"\n";
    return 0;

}