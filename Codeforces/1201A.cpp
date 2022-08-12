#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    vector<string> arr;
    vector<int> pt;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        arr.push_back(s);
    }
    pt.assign(m,0);
    for(auto &x:pt){
        cin >> x;
    }

    int answ = 0;
    for(int i=0;i<m;i++){
        vector<int> freq(10,0);
        for(int j=0;j<n;j++){
            freq[arr[j][i]-'A']++;
        }
        answ += (*max_element(freq.begin(),freq.end()))*pt[i];
    }

    cout << answ <<"\n";

    return 0;
}