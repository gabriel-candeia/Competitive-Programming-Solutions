#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> arr;

int isok(int x){
    int qtd = 0;
    for(int i=0;i<n;i++){
        if(arr[i]<=qtd){
            qtd++;
        }
        else if(x){
            x--;
            qtd++;
        }
    }
    return qtd>=m;
}

int main(){
    cin >> n >> m;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    int l = 0, r = n, med=-1, answ=-1;
    while(l<=r){
        med = l + (r-l)/2;

        if(isok(med)){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }

    cout << answ << "\n";

    return 0;
}

//dp[x+1] = min(dp[x],dp[x])

//dp[i][x] = numero minimo para conseguir x reviews nos i primeiros caras
//dp[i][x] = (arr[i]>(x-1)) + dp[i-1][x-1], 