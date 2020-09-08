#include<bits/stdc++.h>
#define maxn int(1e6+5)
using namespace std;

int sieve[maxn];
map<int,int> cnt;

int main(){
    int n, v=-1;
    vector<int> a;

    for(int i=2;i<maxn;i++)
        if(!sieve[i])
            for(int j=i;j<maxn;j+=i)
                sieve[j] = i;

    cin >> n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        int x = a[i];
        while(x!=1){
            int f = sieve[x];
            cnt[f]++;
            while(sieve[x]==f)
                x/=f;
        }
    }

    bool pairwise = true, setwise=true;
    for(auto p:cnt){
        if(p.second!=1)
            pairwise = false;
            if(p.second==n)
                setwise=false;
    }

    if(pairwise)
        cout << "pairwise coprime" <<'\n';
    else if(setwise)
        cout << "setwise coprime" <<'\n';
    else
        cout << "not coprime" <<'\n';
    
    return 0;
}

