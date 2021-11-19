#include<bits/stdc++.h>
using namespace std;

struct suffixArray{
    vector<int> p, wt, lcp;

    suffixArray(string s){
        s+="#";
        int n = s.size(), N = max(200,n);
        p.assign(n,0), wt.assign(n,0);

        for(int i=0;i<n;i++)
            p[i] = i, wt[i] = s[i];

        for(int k=0;k<n;k = ((k) ? 2*k : 1)){
            vector<int> np(n), nwt(n), bucket(N);
            for(int i=0;i<n;i++)
                np[i] = (p[i]-k+n)%n, bucket[wt[np[i]]]++;
            for(int i=1;i<N;i++)
                bucket[i] += bucket[i-1];
            for(int i=n-1;i>=0;i--)
                p[--bucket[wt[np[i]]]] = np[i];

            nwt[p[0]] = 0;
            for(int i=1;i<n;i++)
                nwt[p[i]] = nwt[p[i-1]] + ((wt[p[i]] != wt[p[i-1]]) || (wt[(p[i]+k)%n] != wt[(p[i-1]+k)%n]));
            wt = nwt;
        }

        lcp.assign(n,0);
        for(int i=0, k=0;i<n-1;i++, k=max(k-1,0)){
            int j = p[wt[i]-1];
            while(max(i,j)+k<s.size() && s[i+k]==s[j+k] ) k++;
            lcp[wt[j]] = k;
        }
    }
};

struct rmq{
    vector<int> lg;
    vector<vector<int>> st;

    rmq(vector<int> arr){
        int n = arr.size();
        lg.assign(n+1,0);
        for(int i=2;i<=n;i++) lg[i] = lg[i/2]+1;
        st.assign(n,vector<int>(lg[n]+1,0));
        
        for(int i=0;i<n;i++)
            st[i][0] = arr[i];
        
        for(int k=1;k<=lg[n];k++)
            for(int i=0;i+(1<<k)<=n;i++)
                st[i][k] = min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
    }

    int get(int l, int r){
        if(l<0 || r<0) return 0;
        int k = lg[r-l+1];
        return min(st[l][k],st[r-(1<<k)+1][k]);
    }
};

int main(){
    string s;
    string a, b, ra;

    cin >> a >> b;
    s = b;
    s += "$"+a; 
    ra = a, reverse(ra.begin(),ra.end());
    s += "$"+ra;
    
    suffixArray sa(s);
    rmq st(sa.lcp);
    
    
    vector<int> best(b.size(),-1), ibest(b.size(),-1);
    for(int i=1, last=-1;i<sa.lcp.size();i++){
        if(sa.p[i]<b.size()){
            int x = st.get(last,i-1);
            if(x>best[sa.p[i]])
                best[sa.p[i]] = x, ibest[sa.p[i]] = sa.p[last];
        }
        else if(s[sa.p[i]]!='$'){
            last = i;
        }
    }

    
    for(int i=sa.lcp.size()-1, last=-1;i;i--){
        if(sa.p[i]<b.size()){
            int x = st.get(i,last-1);
            if(x>best[sa.p[i]])
                best[sa.p[i]] = x, ibest[sa.p[i]] = sa.p[last];
        }
        else if(s[sa.p[i]]!='$'){
            last = i;
        }
    }
    bool poss = true;
    
    vector<pair<int,int>> answ;
    for(int i=0;poss && i<b.size();i+=best[i]){
        if(best[i]<=0) poss = false;
        answ.push_back({ibest[i],min(best[i],(int)b.size()-i)});
    }
    
    if(poss){// 0 -- b.size()-1 -- 1 -- b.size()+1 -- b.size()+a.size()
        cout << answ.size() << "\n";
        int n = a.size(), m = b.size();
        for(auto p:answ){
            if(n+m+1<p.first)
                cout << n+1-(p.first-n-m-1) << " " << n+1-(p.first-n-m-1)-p.second+1 << '\n';
            else 
                cout << p.first-m << " " << p.first-m+p.second-1 << "\n";
        }
    }
    else{
        cout << -1 <<'\n';
    }

    return 0;
}