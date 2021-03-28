#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define maxn int(2e5+5)
#define LOG 30
using namespace std;
int k, n, st[maxn][LOG];
string s;
vector<int> answ;
vector<vector<int>> freq;

int cnt(int l, int r){
    int answ = 0;
    for(int i=0;i<26;i++)
        answ += (freq[r][i]-freq[l-1][i]!=0);
    return answ;
}

int bb1(int i){
    int l=1, r = i, med, x=-1, cmp;
    while(l<=r){
        med = l + (r-l)/2;
        cmp = cnt(med,i);
        if(cmp<=k){
            if(cmp==k) x = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    return x;
}

int bb2(int i){
    int l=1, r = i, med, x=-1, cmp;
    while(l<=r){
        med = l + (r-l)/2;
        cmp = cnt(med,i);
        if(cmp>=k){
            if(cmp==k) x = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return x;
}


int get(int l, int r){
    int x = st[r][0];
    for(int k=LOG-1;k>=0;k--){
        if(r-(1<<k)>=l){
            x = min(x,st[r][k]);
            r-=(1<<k);
        }
    }
    return min(x,st[r][0]);
}

int main(){
    fastio();
    cin >> k >> s;
    n = s.size();

    freq.push_back(vector<int>(30,0));
    answ.assign(n+1,1e9); 

    for(int i=0;i<n;i++){
        freq.push_back(vector<int>(freq.back()));
        freq[i+1][s[i]-'a']++;
    }

    answ[0] = 0;

    for(int i=1;i<=n;i++){
        int l = bb1(i), r = bb2(i);
        if(l!=-1) answ[i] = get(l-1,r-1) + 1;
        st[i][0] = answ[i];
        for(int k=1;k<LOG && i-(1<<(k))+1>=0;k++)
            st[i][k] = min(st[i][k-1],st[i-(1<<(k-1))][k-1]);
    }

    for(int i=1;i<=n;i++){
        cout << (answ[i]<=n ? answ[i] : -1) << " ";
    }cout<<'\n';

    return 0;
}