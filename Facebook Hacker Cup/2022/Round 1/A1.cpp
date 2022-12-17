#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

vector<int> kmp(vector<int> s){
    int n = s.size();
    vector<int> answ(n,0);
    for(int i=1;i<n;i++){
        int j = answ[i-1];
        for(;j>0 && s[i]!=s[j];j = answ[j-1]);
        if(s[i]==s[j]) j++;
        answ[i] = j;
    }
    return answ;
}

int main(){
    fastio();
    int t, caso=0;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> s(n), t(n), acm;
        for(auto &x:s) cin >> x;
        for(auto &x:t) cin >> x;
        
        
        acm.insert(acm.end(),s.begin(),s.end());
        acm.push_back(-1);
        acm.insert(acm.end(),t.begin(),t.end());
        acm.insert(acm.end(),t.begin(),t.end());
        
        auto aux = kmp(acm);
        int mx = 0;

        for(int i=n;i<aux.size();i++)
            mx = max(mx,aux[i]);
        
        bool answ;

        if(mx>=n){
            if(n==2){
                answ = (aux.back()%2) == k%2;
            }
            else{
                if(s==t){
                    answ = (k!=1);
                }
                else{
                    answ = (k!=0);
                }
            }
        }
        else{
            answ = false;
        }

        cout <<"Case #" << ++caso << ": " << ((answ) ? "YES" : "NO") <<"\n";
    }

    return 0;
}