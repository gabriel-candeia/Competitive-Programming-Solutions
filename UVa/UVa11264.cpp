#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll inf = 1e18;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll n;
        
        cin >> n;
        vector<ll> arr(n,0);

        for(auto &x:arr)
            cin >> x;

        arr.push_back(inf);
        ll soma = 0, answ = 0;
        for(int i=0;i<n;i++){
            if(soma+arr[i] < arr[i+1]){
                soma+=arr[i];
                answ++;
            }
        }

        cout << answ <<'\n';    

    }

    return 0;
}
