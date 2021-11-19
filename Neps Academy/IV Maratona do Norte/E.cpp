#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct SuffixArray{
    vector<ll> p, wt, lcp;
    
    SuffixArray(string s){
        s+="$";
        int n = s.size(), N = max(n,200);
        p.assign(n,0), wt.assign(n,0);
 
        for(int i=0;i<n;i++)
            p[i] = i, wt[i] = s[i];
 
        for(int k=0;k<n;k = ((k) ? 2*k : 1)){
            vector<ll> np(p), nwt(n), cnt(N);
 
            for(int i=0;i<n;i++)
                np[i] = (np[i]-k+n)%n, cnt[wt[np[i]]]++;
            for(int i=1;i<N;i++)
                cnt[i] += cnt[i-1];
            for(int i=n-1;i>=0;i--)
                p[--cnt[wt[np[i]]]] = np[i];
 
            nwt[p[0]] = 0;
            for(int i=1;i<n;i++)
                nwt[p[i]] = nwt[p[i-1]] + (wt[p[i]] != wt[p[i-1]] || wt[(p[i]+k)%n] != wt[(p[i-1]+k)%n]);
            wt = nwt;
        }
 
        lcp.assign(n,0);
        for(int i=0,k=0;i<n-1;i++, k = max(k-1,0)){
            int j = p[wt[i]-1];
            while(max(i,j)+k < s.size() && s[i+k]==s[j+k]) k++;
            lcp[wt[j]] = k;
        }
    }
};

int main() {
    string s;

    cin >> s;
    
    SuffixArray sa(s);

    ll answ = -1;
    for(int i=0;i<sa.lcp.size();i++){
        ll lcp = 1e9;
        for(int j=i+1;j<sa.lcp.size();j++){
            lcp = min(lcp,sa.lcp[j-1]);
            if(lcp>0){
                answ = max(answ,max(sa.p[i],sa.p[j])-min(sa.p[i],sa.p[j])+lcp);
            }
            else{
                break;
            }
        }      
    }
    
    cout << answ <<'\n';
    return 0;
}

