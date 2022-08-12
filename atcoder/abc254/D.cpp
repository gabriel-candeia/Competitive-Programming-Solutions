#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

int sieve[maxn];

int main(){
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        if(!sieve[i])
            for(int j=i;j<=n;j+=i)
                sieve[j] = i;
    }

    map<vector<int>,int> freq;
    for(int i=1;i<=n;i++){
        vector<int> temp;
        int y = i;
        while(y!=1){
            int x = sieve[y], cnt = 0;
            while(sieve[y]==x){
                y/=x;
                cnt = 1-cnt;
            }
            if(cnt==1){
                temp.push_back(x);
            }
        }
        freq[temp]++;
    }

    ll answ = 0;
    for(auto &p:freq){
        answ += p.second*p.second;
    }

    cout << answ <<"\n";

    return 0;
}