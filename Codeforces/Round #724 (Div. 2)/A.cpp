#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<int> arr;

        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr) cin >> x;
        sort(arr.begin(),arr.end());
        if(arr[0]<0){
            cout << "no\n";
            continue;
        }
        int d = arr[0];
        for(int i=0;i<n;i++){
            if(arr[i]){
                d = __gcd(abs(arr[i]),d);
            }
        }

        int qtd = arr[n-1]/d + (arr[0]==0);
        if(qtd<=300){
            cout <<"yEs\n";
            cout << qtd <<"\n";
            for(;arr[n-1]>=d;arr[n-1]-=d){
                cout << arr[n-1] <<" ";
            }
            if(arr[0]==0)
                cout << 0 <<" ";
            cout<<"\n";
        }
        else{
            cout << "no\n";
        }


    }
    return 0;
}