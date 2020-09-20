#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;
//using set
int dp[maxn], arr[maxn], n;
set<pair<int,int>> s;

int main(){
    fastIO();
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    s.insert({-1,0});
    for(int i=0;i<n;i++){
        auto it = s.lower_bound({arr[i],-1});
        if(it!=s.end()){
            dp[i] = (*it).second    ;
            s.erase(it);
        }
        else
            dp[i] = s.size();
        s.insert({arr[i],dp[i]});
    }

    int answ=0;
    for(int i=0;i<n;i++)
        answ = max(answ,dp[i]);
     
    cout << answ <<'\n';

    return 0;
}