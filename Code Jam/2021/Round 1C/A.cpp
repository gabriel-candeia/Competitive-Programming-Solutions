#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

int main(){
    int t, caso=0;

    cin >> t;
    while(t--){
        ll n, k;
        vector<ll> arr, arr1;
        cin >> n >> k;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        arr.push_back(0);
        arr.push_back(k+1);
        sort(arr.begin(),arr.end());
        

        ld answ = 0, temp;
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]-1-(arr[i]+1)+1<2) continue;
            temp = (arr[i+1]-1-(arr[i]+1)+1)*(1.0)/k;
            answ = max(answ,temp);
        }

        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size()-1;j++){
                temp = 0;
                if(i==0){
                    temp += (arr[i+1]-1)*(1.0)/k;
                }
                else{
                    ll x = arr[i]+1;
                    temp += ((arr[i+1]-x+1)/2)*(1.0)/k;
                }

                if(arr[j+1]==k+1){
                    temp += (k-(arr[j]+1)+1)*(1.0)/k;
                }
                else{
                    ll x = arr[j]+1;
                    temp += ((arr[j+1]-x+1)/2)*(1.0)/k;
                }

                answ = max(answ,temp);
            }
        }

        cout <<fixed << setprecision(10)<< "Case #" << ++caso << ": " << answ <<'\n';
    }

    return 0;
}