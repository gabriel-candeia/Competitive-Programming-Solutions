#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> arr, answ;

    cin >> n;
    arr.assign(n+1,0);
    answ.assign(n+1,0);
    for(int i=1;i<=n;i++) cin >> arr[i];

    for(int i=1;i<=n;i++){
        answ[i] = arr[i];
        for(int k=0;k<22;k++){
            if((i&(1<<k))!=0 && (i^(1<<k))!=0){
                answ[i] = __gcd(answ[i],answ[(i^(1<<k))]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout << answ[i] << "\n";
    }


    return 0;
}