#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

ll freq[maxn];

int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        freq[x]++;
    }

    ll answ = 0;
    for(ll i=1;i<maxn;i++){
        for(ll j=0;j<maxn;j+=i){
            answ += freq[i]*freq[j]*freq[j/i];
        }
    }

    cout << answ <<"\n";


    return 0;
}