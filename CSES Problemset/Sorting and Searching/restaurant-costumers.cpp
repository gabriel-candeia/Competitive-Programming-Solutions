#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    vector<pair<int,int>> arr;

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        arr.push_back({a,1});
        arr.push_back({b,-1});
    }

    sort(arr.begin(),arr.end());

    int cnt=0, answ=0;
    for(auto p:arr){ 
        cnt+=p.second;
        answ = max(answ,cnt);
    }

    cout << answ <<'\n';
    return 0;
}