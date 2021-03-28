#include<bits/stdc++.h>
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

    return lcp;
}

int main(){
    string s, t, sum;

    cin >> s >> t;
    sum = s+"#"+t;
    auto sa = suffix_array(sum), arr = lcp(sa,sum);

    int len=0, start=0;
    for(int i=0;i<arr.size()-1;i++)
        if((sa[i]<s.size() && sa[i+1]>s.size() || sa[i]>s.size() && sa[i+1]<s.size()) && arr[i]>len)
            len = arr[i], start = min(sa[i],sa[i+1]);
    
    cout << s.substr(start,len) << '\n';

    return 0;
}