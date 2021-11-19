#include<bits/stdc++.h>
using namespace std;

pair<int,int> normaliza(int a, int b){
    if(a==0)
        return {a,1};
    if(b==0)
        return {1,b};
    int d = __gcd(a,b);
    return {a/d,b/d};
}

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        int cnt1=0,cnt2=0;
        string s;
        map<pair<int,int>,int> mp;

        cin >> n >> s;
        for(int i=0;i<n;i++){
            if(s[i]=='D') cnt1++;
            else cnt2++;
            cout << (++mp[normaliza(cnt1,cnt2)]) << " ";
        }cout<<"\n";
    }


    return 0;
}