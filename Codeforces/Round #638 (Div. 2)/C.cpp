#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k;
    string s;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        sort(s.begin(),s.end());
        string answ = "";

        int l = 0, r = min(k-1,n-1);
        if(k==1){
            answ = s;
        }
        else if(s[l]!=s[r]){
            answ+=s[r];
        }
        else{
            answ+=s[r];

            for(l=r+1;l<n && s[l]==s[r+1];l++);
            
            if(l==n){
                answ += string(ceil((n-r-1)*1.0/k),s[r+1]);
            }
            else{
                for(int i=r+1;i<n;i++){
                    answ+=s[i];
                }

            }
        }

        cout << answ << '\n';
    }
    return 0;
}