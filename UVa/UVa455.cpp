#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s){
    int n =s.size();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r){
            z[i] = min(z[i-l],r-i+1);
        }
        while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

int main(){ 
    int t, n;
    vector<int> z;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        n = s.size();
        z = z_function(s);
        vector<bool> poss(n,true);
        for(int i=1;i<n;i++){
            for(int j=i;j<n;j+=i){
                poss[i] = poss[i]*(z[j]>=i);
            }
        }

        int answ=1;
        while(answ<n && poss[answ]==false){
            answ++;
        }

        cout << answ << '\n';
        if(t!=0){
            cout << '\n';
        }
    }

    return 0;
}