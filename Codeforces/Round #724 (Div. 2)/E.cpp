#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, m;
        ll k = 0, answ=1;
        string s;

        cin >> n >> m;
        for(int i=0;i<n;i++){
            cin >> s;
            for(auto c:s)
                if(c!='0')
                    answ = (answ*2)%mod, k++;
        }

        if(k==n*m) answ = (answ-1+mod)%mod;
        cout <<answ <<"\n";
    }

    return 0;
}