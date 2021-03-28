#include<bits/stdc++.h>
using namespace std;

int cnt(int x, int y){
    int answ = 0;
    while(y>2*x){
        x = 2*x;
        answ++;
    }
    return answ;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr;
        arr.assign(n,0);
        for(auto &x:arr){
            cin >> x;
        }

        int answ = 0;
        for(int i=0;i<n-1;i++){
            answ += cnt(min(arr[i],arr[i+1]),max(arr[i],arr[i+1]));
        }
        cout << answ <<'\n';
    }

    return 0;
}