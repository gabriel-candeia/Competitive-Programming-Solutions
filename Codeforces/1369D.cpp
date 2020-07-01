#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll m = 1000000007;

int main(){
    int t, n;
    vector<int> arr(2e6,0);
    for(int i=3;i<=2e6;i++){
        arr[i] = (2*(arr[i-2]))%m+arr[i-1] + ((i%3==0) ? 4 : 0);
        arr[i] = arr[i]%m;
    }
    cin >> t;
    while(t--){
        cin >> n;
        cout << arr[n] << '\n';
    }

    return 0;
}