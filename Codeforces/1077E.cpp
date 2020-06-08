#include<bits/stdc++.h>
#define ll long long
#define N int(2e5)+3
using namespace std;

ll max(ll a, ll b){
    return (a<b) ? b : a;
}

int main(){
    int n, a;
    map<int,ll> cnt;
    ll s[N];
    ll answ = 0, curr=0, acm, next;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        cnt[a]++;
    }

    n = 0;
    for(auto p:cnt){
        s[n++] = p.second;
    }
    sort(s,s+n);

    for(int i=1;i<=s[n-1];i++){
        acm = 0; curr = i; next = n-1;
        /*
        cout << i << ' ' << s[i] << ": ";
        while(next<n){
            acm+=curr;
            curr *= 2;
            next = lower_bound(s+next+1,s+n,curr)-s;
            cout << next << ' ' << s[next] << ", ";
        }
        cout << '\n';
        cout << acm << '\n';
        */
        acm = curr;
        //cout << i << ' ' << s[i] << ": ";
        while(curr%2==0 && next>0){
            curr/=2;
            next--;
            if(s[next]<curr){
                break;
            }
            //cout << next << ' ' << s[next] << ", ";
            acm+=curr;
        }   
        //cout << '\n';       

        answ = max(answ,acm);
    }

    cout << answ << '\n';

    return 0;
}