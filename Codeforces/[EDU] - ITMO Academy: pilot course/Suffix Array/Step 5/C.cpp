#include<bits/stdc++.h>
#define LOG 25
using namespace std;

struct RMQ{
    int n;
    vector<int> lg; 
    vector<vector<int>> st;

    RMQ(vector<int> &arr){
        n = arr.size();

        lg.assign(n+1,0);
        for(int i=2;i<=n;i++)
            lg[i] = lg[i/2] + 1;

        st.assign(n,vector<int>(LOG,1e9));

        for(int i=0; i<n; i++)
            st[i][0] = arr[i];

        for(int k=1; (1<<k) <= n; k++)
            for(int i=0; (i+(1<<(k-1)))<n; i++)
                st[i][k] = min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
    }

    int get(int i, int j){
        int k = lg[j-i+1];
        return min(st[i][k],st[j-(1<<k)+1][k]);
    }

    int query(int j, int x){
        int l = 0, r = j-1, med, answ = j-1;
        while(l<=r){
            int med = l + (r-l)/2;
            if(get(med,j-1)>=x){
                answ = med-1;
                r = med-1;
            }
            else{
                l = med+1;
            }
        }

        return answ;
    }
};

struct SuffixArray{
    vector<int> p, wt, lcp;

    SuffixArray(string s){
        s += string(1,char(1));
        int n = s.size(), N = max(n,200);
        p.assign(n,0), wt.assign(n,0);

        for(int i=0; i<n; i++)
            p[i] = i, wt[i] = s[i];

        for(int k=0; k<n; k = (k ? 2*k : 1)){
            vector<int> np(p), nwt(n), cnt(N);

            for(int i=0;i<n;i++)
                np[i] = (np[i]-k+n)%n, cnt[wt[np[i]]]++;
            for(int i=1;i<N;i++)
                cnt[i] += cnt[i-1];
            for(int i=n-1;i>=0;i--)
                p[--cnt[wt[np[i]]]] = np[i];

            nwt[p[0]] = 0;
            for(int i=1;i<n;i++)
                nwt[p[i]] = nwt[p[i-1]] + (wt[p[i]]!=wt[p[i-1]] || wt[(p[i]+k)%n]!=wt[(p[i-1]+k)%n]);
            wt = nwt;
        }

        lcp.assign(n,0);
        for(int i=0, k=0; i<n-1; i++, k = max(k-1,0)){
            int j = p[wt[i]-1];
            while(max(i,j)+k < s.size() && s[i+k]==s[j+k]) k++;
            lcp[wt[j]] = k;
        }
    }
};

int main(){
    int m;
    string s;   
    cin >> s;

    SuffixArray sa(s);
    RMQ st(sa.lcp);
    vector<array<int,4>> answ;

   int x, y;
    cin >> m;
    for(int i=0;i<m;i++){
        cin >> x >> y; 
        x--, y--;
        answ.push_back({st.query(sa.wt[x],y-x+1),y-x+1,x,y});
    }

    
    sort(answ.begin(), answ.end());
    for(auto p:answ)
        cout <<  p[2]+1 << " " << p[3]+1 << '\n';

    return 0;
}