#include<bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s){
    s += "$";
    int n = s.size(), N = max(n,200);
    vector<int> p(n), right(n);

    for(int i=0;i<n;i++)
        p[i] = i, right[i] = max(s[i]-'a'+1,0);
    
    for(int k=0; k < n; (k = (k) ? 2*k : k+1)){
        vector<int> np(p), left(n), cnt(N);
        for(int i=0;i<n;i++)
           np[i] = (np[i]-k+n)%n, cnt[right[i]]++;
        for(int i=1;i<N;i++)
            cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--)
            p[--cnt[right[np[i]]]] = np[i];

        for(int i=1, r=0; i<n; i++)
            left[p[i]] = r += (right[p[i]] !=right[p[i-1]] || right[(p[i]+k)%n] != right[(p[i-1]+k)%n]);

        right = left;
    }

    return p;
}

int main(){
    string s;
    cin >> s;
    auto answ = suffix_array(s);
    for(auto x:answ)
        cout << x <<" ";
    cout<<'\n';
    return 0;


}
