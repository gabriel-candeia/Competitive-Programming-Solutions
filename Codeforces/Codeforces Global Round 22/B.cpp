#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    
    while(t--){
        ll n, k;

        cin >> n >> k;

        vector<ll> prefs;
        prefs.assign(k,0);

        for(auto &x:prefs)
            cin >> x;

        if(k==1){
            cout << "Yes\n";
            continue;
        }

        reverse(prefs.begin(),prefs.end());

        vector<ll> answ;
        for(int i=0;i<prefs.size()-1;i++){
            answ.push_back(prefs[i]-prefs[i+1]);
        }
 

        if(answ.size())
            reverse(answ.begin(),answ.end());

        bool ok = true;
        if(answ.size()){
            ok = ((answ.back()*(n-(k-1))) >= prefs.back());
        }

        for(int i=0;i<answ.size()-1;i++){
            ok = ok && (answ[i] <= answ[i+1]);
        }


        cout << ((ok) ? "Yes" : "No") <<"\n";

    }

    return 0;
}