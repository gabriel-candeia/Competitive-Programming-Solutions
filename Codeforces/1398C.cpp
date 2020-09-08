#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, n;
    string s;

    cin >> t;
    while(t--){
        cin >> n >> s;
        ll acm = 0, answ=0;
        map<int,int> cnt;
        cnt[0] = 1;
        for(int i=0;i<n;i++){
            acm += s[i]-'0'-1;
            answ+=cnt[acm];
            cnt[acm]++;
        }
        cout << answ <<'\n';
    }

    return 0;
}