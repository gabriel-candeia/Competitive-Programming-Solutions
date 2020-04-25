#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

int main(){
    ll n, x, cnt=0, answer=0;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        cnt = max(cnt+x,x);
        if(i==0){
            answer = cnt;
        }
        answer = max(answer,cnt);
    }

    cout << answer << "\n";

    return 0;
}