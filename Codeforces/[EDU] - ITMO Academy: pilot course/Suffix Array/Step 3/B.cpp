#include<bits/stdc++.h>
using namespace std;

vector<int> suffix_array(string s){
    s += "$";
    int n = s.size(), N = max(n,200);
    vector<int> p(n), right(n);

    for(int i=0;i<n;i++)
        p[i] = i, right[i] = max(s[i]-'a'+1,0);
    
    for(int k=0;k<n;k = ((k) ? 2*k : 1)){
        vector<int> np(p), left(n), cnt(N);
        for(int i=0;i<n;i++)
            np[i] = (np[i]-k+n)%n, cnt[right[i]]++;
        for(int i=1;i<N;i++)
            cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--)
            p[--cnt[right[np[i]]]] = np[i];

        for(int i=1, r=0; i<n;i++)
            left[p[i]] = (r += (right[p[i]]!=right[p[i-1]] || right[(p[i]+k)%n] != right[(p[i-1]+k)%n]));

        right = left;
    }

    return p;
}

bool cmp(string &t, string &s, int i){
    int j;
    for(j=0;i<s.size() && j<t.size();i++,j++){
        if(t[j]<s[i])
            return 1;
        if(t[j]>s[i])
            return 0;
    }
    return (j==t.size());
}

int bb(vector<int> &arr, string &s, string t){
    int l = 0, r = arr.size()-1, med, answ=arr.size();
    
    while(l<=r){
        med = l + (r-l)/2;
        if(cmp(t,s,arr[med])){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }

    return answ;
}


int main(){
    int n;
    string s, t;

    cin >> s;
    vector<int> arr = suffix_array(s);
    
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> t;   
        cout << max(bb(arr,s,t+string(1,'z'+1))-bb(arr,s,t),0) << '\n';
    }

    return 0;
}