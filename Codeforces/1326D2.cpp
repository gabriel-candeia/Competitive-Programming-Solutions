#include<bits/stdc++.h>
using namespace std;

vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n,0);
    for(int i=1, l=0, r=0;i<n;i++){
        if(i<=r){
            z[i] = min(z[i-l],r-i+1);
        }
        while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            r = i+z[i]-1;
            l = i;
        }
    }
    return z;
}

int main(){
    int t;
    string s, preff, suff;

    cin >> t;
    while(t--){
        string s, r, preff="", middle="", suff="";
        vector<int> z;
        int n, cnt=0;
        cin >> s;
        n = s.size();
        for(int i=0;i<n/2 && s[i]==s[n-i-1];i++){
            cnt++;
        }
        preff = s.substr(0,cnt);
        suff = string(preff.rbegin(),preff.rend());
        s = s.substr(preff.size(),s.size()-2*preff.size());
        n = s.size();
        r = string(s.rbegin(),s.rend());

        z = z_function(s+"#"+r);
        for(int i=0;i<n;i++){
            if(i+z[i+n+1]==n){
                middle = s.substr(0,z[i+n+1]);
                break;
            }
        }

        z = z_function(r+"#"+s);
        for(int i=0;i<n;i++){
            if(i+z[i+n+1]==n && z[i+n+1]>middle.size()){
                middle = r.substr(0,z[i+n+1]);
                break;
            }
        }

        cout << preff+middle+suff<<'\n';
    }


    return 0;
}
