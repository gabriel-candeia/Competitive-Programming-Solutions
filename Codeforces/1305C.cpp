#include<bits/stdc++.h>
#define N int(2e5)+3

using namespace std;

int calc(int arr[N], int n, int m){
    int answ = 1;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            answ = ((answ%m) * (abs(arr[i]-arr[j])%m))%m;
        }
    }
    return answ;
}

int main(){
    int n, m, arr[N];

    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cout << ((n<=m) ? calc(arr, n, m) : 0) << '\n';
    return 0;
}