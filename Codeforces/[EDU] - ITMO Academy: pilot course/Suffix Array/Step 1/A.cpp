#include<bits/stdc++.h>
using namespace std;

vector<int> suffixArray(string s){
    s += "$";
    int n = s.size();
    vector<int> wt(n,0);
    vector<array<int,3>> arr(n);

    for(int i=0;i<n;i++)
        wt[i] = max(s[i]-'a'+1,0);
        
    for(int k=0;(1<<k)<n;k++){
        for(int i=0;i<n;i++)
            arr[i] = {wt[i],wt[(i+(1<<k))%n],i};
        sort(arr.begin(),arr.end());
        wt[arr[0][2]] = 0;
        for(int i=1;i<n;i++)
            wt[arr[i][2]] = wt[arr[i-1][2]] + (arr[i-1][0] != arr[i][0] || arr[i-1][1] != arr[i][1]);
    }

    vector<int> answ(n,0);
    for(int i=0;i<n;i++)
        answ[i] = arr[i][2];

    return answ;
}

int main(){
    string s;
    cin >> s;
    
    vector<int> answ = suffixArray(s);
    for(auto x: answ){
        cout << x <<' ';
    }cout<<'\n';


    return 0;
}