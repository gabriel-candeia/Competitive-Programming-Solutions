#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> suffix_array(string s){
    s += "$";
    int n = s.size(), N = max(n,200);
    vector<int> p(n), pos(n);

    for(int i=0;i<n;i++)
        p[i] = i, pos[i] = max(s[i]-'a'+1,0);
    
    for(int k=0; k<n; k = ((k) ? 2*k : 1)){
        vector<int> np(p), npos(n), cnt(N);

        for(int i=0; i<n; i++)
            np[i] = (np[i]-k+n)%n, cnt[pos[np[i]]]++;
        for(int i=1; i<N; i++)
            cnt[i] += cnt[i-1];
        for(int i=n-1; i>=0; i--)
            p[--cnt[pos[np[i]]]] = np[i];

        npos[p[0]] = 0;
        for(int i=1; i<n; i++)
            npos[p[i]] = npos[p[i-1]] + (pos[p[i]]!=pos[p[i-1]] || pos[(p[i]+k)%n]!=pos[(p[i-1]+k)%n]);
        pos = npos;
    }

    return p;
}

vector<int> lcp(vector<int> &p, string s){
    int n = p.size();
    vector<int> pos(n), lcp(n);

    for(int i=0;i<n;i++)
        pos[p[i]] = i;

    for(int i=0, k=0; i<n; i++, k = max(k-1,0)){
        int j = p[pos[i]-1];
        while(max(i,j)+k < s.size() && s[i+k]==s[j+k]) k++;
        lcp[pos[i]] = k;
    }

    for(int i=0;i<n;i++)
        lcp[i] = lcp[i+1];
    lcp[n-1] = 0;

    return lcp;
}

int main(){
    string s;

    cin >> s;
    vector<int> sa = suffix_array(s), arr = lcp(sa,s);

    ll answ = 0;
    for(int i=0;i<sa.size();i++)
        answ += s.size()-sa[i]-arr[i];

    cout << answ <<'\n';

    return 0;
}