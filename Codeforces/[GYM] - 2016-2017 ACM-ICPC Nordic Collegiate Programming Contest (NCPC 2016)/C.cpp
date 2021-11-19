#include<bits/stdc++.h>
using namespace std;

int c1(char c){
    if(c<='9' && c>='2') return c-'0';
    if(c=='T') return 10;
    if(c=='J') return 11;
    if(c=='Q') return 12;
    return 13;
}

int c2(char c){
    if(c=='s') return 0;
    if(c=='h') return 1;
    if(c=='d') return 2;
    return 3;
}

int n;
vector<pair<int,int>> cartas;

int teste(const vector<int>& p, int msk){
    vector<array<int,3>> arr;

    for(int i=0;i<n;i++){
        int a = p[cartas[i].first];
        int b = ((1<<cartas[i].first)&(msk)) ? cartas[i].second : -cartas[i].second;
        arr.push_back({a,b,i});
    }

    int answ = 0;
    vector<int> dp(n,0);
    for(int i=0;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j])
                dp[i] = max(dp[i],dp[j]);
        }
        dp[i]++;
        answ = max(answ,dp[i]);
    }

    return answ;
}

int main(){


    cin >> n;
    for(int i=0;i<n;i++){
        char a, b;
        cin >> a >> b;
        cartas.push_back({c2(b),c1(a)});
    }

    vector<int> p = {0,1,2,3};

    int answ = 0;
    while(true){
        for(int msk=0;msk < (1<<4);msk++){
            answ = max(answ,teste(p,msk));
        }
        if(next_permutation(p.begin(),p.end())==false)
            break;
    }

    cout << n-answ <<"\n";

    return 0;
}