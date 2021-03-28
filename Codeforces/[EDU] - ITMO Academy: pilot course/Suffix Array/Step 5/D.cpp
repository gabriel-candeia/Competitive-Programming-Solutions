#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct SuffixArray{
    vector<ll> p, pos, lcp;

    SuffixArray(string s){
        s += "$";
        int n = s.size(), N = max(n,200);
        p.assign(n,0), pos.assign(n,0);

        for(int i=0;i<n;i++)
            p[i] = i, pos[i] = s[i];

        for(int k=0;k<n;k = ((k) ? 2*k : 1)){
            vector<ll> np(p), npos(n), cnt(N);

            for(int i=0;i<n;i++)
                np[i] = (np[i]-k+n)%n, cnt[pos[np[i]]]++;
            for(int i=1;i<N;i++)
                cnt[i]+=cnt[i-1];
            for(int i=n-1;i>=0;i--)
                p[--cnt[pos[np[i]]]] = np[i];

            npos[p[0]] = 0;
            for(int i=1;i<n;i++)
                npos[p[i]] = npos[p[i-1]] + (pos[p[i]] != pos[p[i-1]] || pos[(p[i]+k)%n] != pos[(p[i-1]+k)%n]);
            pos = npos;
        }

        lcp.assign(n,0);
        for(int i=0,k=0;i<n-1;i++,k = max(k-1,0)){
            int j = p[pos[i]-1];
            while(max(i,j)+k<s.size() && s[i+k]==s[j+k]) k++;
            lcp[pos[j]] = k;
        }
    }

};

int main(){
    string s;
    cin >> s;

    SuffixArray sa(s);
    vector<ll> st, left(s.size()+1,0);

    st.push_back(-1);
    for(int i=0;i<sa.lcp.size();i++){
        if(st.size()>1)
            left[i] = sa.lcp[st[st.size()-1]]*(st[st.size()-1]-st[st.size()-2]) + left[st[st.size()-2]+1];
        while(st.size()>1 && sa.lcp[st.back()] > sa.lcp[i]) st.pop_back();
        st.push_back(i);
    }

    ll n = s.size(), answ = (n*(n-1))/2 + n;
    for(auto x:left) answ += x;
    cout << answ << '\n';

    return 0;
}