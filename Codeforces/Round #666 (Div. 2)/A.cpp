#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    string s;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> cnt(30,0);
        for(int i=0;i<n;i++){
            cin >> s;
            for(auto i:s){
                cnt[i-'a']++;
            }
        }
        bool poss=true;
        for(int i=0;i<30;i++){
            if(cnt[i]%n!=0){
                poss = false;
            }
        }

        if(poss){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}