#include<bits/stdc++.h>
#define ll int
using namespace std;

int n, I, t;
ll answ, k, K;
vector<ll> cnt, arr;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> I;

    arr.assign(n,0);
    cnt.assign(n,0);

    for(auto& k:arr){
        cin >> k;
    }
    sort(arr.begin(),arr.end());

    cnt[0] = 1; t = 1;
    for(int i=1;i<n;i++){
        if(arr[i]!=arr[i-1]){
            arr[t++] = arr[i];
            cnt[t-1]++;
        }
        else{
            cnt[t-1]++;
        }
    }

    for(int i=1;i<t;i++){
        cnt[i]+=cnt[i-1];
    }

    K = pow(2,min(30,8*I/n));
    if(K>=t){
        answ = 0;
    }
    else{
        answ = n;
        for(int i=0;i+K<t;i++){
            if(i==0){
                answ = min(answ,n-(cnt[i+K-1]));
            }
            else{
                answ = min(answ,n-(cnt[i+K-1]-cnt[i-1]));
            }
        }
    }
    

    cout << answ << '\n';

    return 0;
}