#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll n, cnt=0, answ=0;
        cin >> n;
        for(int i=1;i<=n;i+=2, cnt++){
            answ += 4ll*(i-1)*cnt;
        }
        cout << answ << '\n';
    }

    return 0;
}
