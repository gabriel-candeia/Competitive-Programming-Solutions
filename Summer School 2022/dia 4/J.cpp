#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> arr;
vector<vector<string>> subseq;

string get(const string& s, int msk){
    string answ = "";
    for(int i=0;i<s.size();i++){
        if(msk & (1<<i)){
            answ.push_back(s[i]);
        }
    }
    return answ;
}

vector<string> geraSubseq(string s){
    int n = s.size();
    vector<string> answ;
    for(int i=0;i<(1<<n);i++){
        answ.push_back(get(s,i));
    }
    sort(answ.begin(),answ.end());
    return answ;
}

int main(){
    cin >> n;
    arr.assign(n,"");
    for(auto &x:arr)
        cin >> x;
    
    for(int i=0;i<n;i++){
        subseq.push_back(geraSubseq(arr[i]));
    }

    vector<vector<int>> dp(n,vector<int>());

    dp[0].assign(subseq[0].size(),0), dp[0][0] = -1;
    for(int j=1;j<subseq[0].size();j++){
        dp[0][j] = max((int)subseq[0][j].size(),dp[0][j-1]);
    }

    for(int i=1;i<n;i++){
        int m = subseq[i].size(), k = 0;
        dp[i].assign(m,0);
        dp[i][0] = -1;
        for(int j=1;j<m;j++){
            while(k+1<subseq[i-1].size() && subseq[i][j]>subseq[i-1][k+1]) k++;
            dp[i][j] = dp[i][j-1];
            if(dp[i-1][k]!=-1)
                dp[i][j] = max(dp[i][j],dp[i-1][k]+((int)subseq[i][j].size()));
        }
    }
    
    cout << dp[n-1][((int)subseq[n-1].size())-1] <<"\n";

    return 0;
}