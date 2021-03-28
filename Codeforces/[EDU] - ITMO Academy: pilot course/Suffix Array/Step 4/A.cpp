#include<bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string &s){
    s += "$";
    int n = s.size(), N = max(n,200);
    vector<int> p(n), wt(n), lcp(n);

    for(int i=0;i<n;i++)
        p[i] = i, wt[i] = max(s[i]-'a'+1,0);
    
    for(int k=0;k<n;k = ((k) ? 2*k : 1)){
        vector<int> np(p), nwt(n), cnt(N);

        for(int i=0;i<n;i++)    
            np[i] = (np[i]-k+n)%n, cnt[wt[np[i]]]++;
        for(int i=1;i<N;i++)
            cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--)
            p[--cnt[wt[np[i]]]] = np[i];

        nwt[p[0]] = 0;
        for(int i=1;i<n;i++)
            nwt[p[i]] = nwt[p[i-1]] + (wt[p[i]]!=wt[p[i-1]] || wt[(p[i]+k)%n] != wt[(p[i-1]+k)%n]);

        wt = nwt;
    }

    return p;
}

vector<int> lcp(string s, vector<int> &p){
    int n = p.size();
    vector<int> wt(n), lcp(n);

    for(int i=0;i<n;i++)
        wt[p[i]] = i;

    for(int i=0, k=0; i<n; i++, k = max(k-1,0)){
        int j = p[wt[i]-1];
        while(max(i,j)+k < s.size() && s[i+k]==s[j+k]) k++;
        lcp[wt[i]] = k;
    }

    for(int i=0;i<n-1;i++)
        lcp[i] = lcp[i+1];
    lcp.pop_back();

    return lcp;
}

int main(){
    string s;

    cin >> s;
    vector<int> sa = suffix_array(s), answ = lcp(s,sa);

    for(auto x:sa)
        cout << x << " ";
    cout<<'\n';

    for(auto x:answ)
        cout << x << " ";
    cout<<'\n';

    return 0;
}