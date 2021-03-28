#include<bits/stdc++.h>
#define maxn 24
using namespace std;

string s;
int f[(1<<maxn)];

int main(){
    int n;
    cin >> n;

    vector<int> arr;
    for(int i=0;i<n;i++){
        cin >> s;
        int x = 0;
        for(auto c:s)
            x |= (1<<(c-'a'));
        f[x]++;
    }

    for(int i=0;i<maxn;i++){
        for(int mask=0;mask<(1<<maxn);mask++){
            if(mask&(1<<i))
                f[mask] = f[mask] + f[mask^(1<<i)];
        }
    }

    int answ = 0;
    for(int mask=0;mask<(1<<maxn);mask++){
        answ ^= (n-f[mask])*(n-f[mask]);
    }

    cout << answ <<"\n";

    return 0;
}