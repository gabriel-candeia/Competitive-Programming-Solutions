#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;

int teste(int x){
    int total = 0;
    for(int i=0;i<n;i++){
        total += ((arr[i]+x==7) ? 2 : (arr[i]!=x));
    }
    return total;
}

int main(){
    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr){
        cin >> x;
    }

    int answ = 2*n+2;
    for(int i=1;i<=6;i++){
        answ = min(answ,teste(i));
    }

    cout << answ <<'\n';
    return 0;
}