#include<bits/stdc++.h>
#define ll long long
using namespace std;

struct SuffixArray{
    vector<ll> p, wt, lcp;

    SuffixArray(vector<ll> arr){
        arr.push_back(0);
        int n = arr.size(), N = max(n,20);
        p.assign(n,0), wt.assign(n,0);

        for(int i=0;i<n;i++)
            p[i] = i, wt[i] = arr[i];

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
            while(max(i,j)+k < arr.size() && arr[i+k]==arr[j+k]) k++;
            lcp[wt[j]] = k;
        }
    }
};

int main(){
    ll n, m;
    vector<ll> arr, nxt, lst;

    cin >> n >> m;
    arr.assign(n,0);

    for(auto &x:arr)
        cin >> x;
    SuffixArray sa(arr);

    nxt.assign(sa.lcp.size(),sa.lcp.size()), lst.assign(sa.lcp.size(),sa.lcp.size());

    vector<ll> st;
    for(int i=0;i<sa.lcp.size();i++){
        while(st.size() && sa.lcp[st.back()]>sa.lcp[i]){
            nxt[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }

    st.clear();
    reverse(sa.lcp.begin(),sa.lcp.end());
    for(int i=0;i<sa.lcp.size();i++){
        while(st.size() && sa.lcp[st.back()]>sa.lcp[i]){
            lst[st.back()] = i;
            st.pop_back();
        }
        st.push_back(i);
    }
    reverse(lst.begin(),lst.end());
    reverse(sa.lcp.begin(),sa.lcp.end());

    ll answ=arr.size(), start=0, siz=arr.size();
    for(int i=0;i<sa.lcp.size();i++){
        if(sa.lcp[i]*(nxt[i]-n+lst[i])>answ){
            answ = sa.lcp[i]*(nxt[i]-n+lst[i]);
            start = sa.p[i];
            siz = sa.lcp[i];
        }
    }

    cout << answ << "\n";
    cout << siz << "\n";
    for(int i=start;i<start+siz;i++)
        cout << arr[i] << " ";
    cout << '\n';

    return 0;
}