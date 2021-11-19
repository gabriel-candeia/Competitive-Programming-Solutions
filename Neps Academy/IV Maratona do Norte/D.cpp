#include<bits/stdc++.h>
#define maxn 16
using namespace std;

map<string,vector<int>> mp;

bool teste(int a, int b){
    vector<int> a1, a2;

    for(int i=0;a;i++,a/=2)
        if(a%2) a1.push_back(i);

    for(int i=0;b;i++,b/=2)
        if(b%2) a2.push_back(i);

    return a1<a2;
}

int main(){
    int n;
    string s;

    cin >> n >> s;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            if(mp.find(s.substr(i,j-i+1))==mp.end())
                mp[s.substr(i,j-i+1)] = vector<int>();
            int acm = 0;
            for(int k=i;k<=j;k++)
                acm |= (1<<k);
            mp[s.substr(i,j-i+1)].push_back(acm);
        }
    }
    
    
    int answ = (1<<n)-1;
    for(int msk=0;msk < (1<<n);msk++){
        bool poss = true;

        for(auto p:mp){
            bool ok = false;
            for(auto x:p.second)
                if((msk & x)!=0)
                    ok = true;
            if(ok==false){
                poss = false;
                break;
            }
        }


        if(poss && (__builtin_popcount(msk) < __builtin_popcount(answ) || (__builtin_popcount(msk) == __builtin_popcount(answ) && teste(msk,answ))))
            answ = msk;
    }

    cout << __builtin_popcount(answ) << '\n'; 
    for(int i=0;answ;i++, answ/=2)
        if(answ%2)
            cout << i+1 << " ";
    cout << '\n';

    return 0;
}