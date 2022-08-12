#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int q;
    multiset<ll> st, stneg;

    cin >> q;
    while(q--){
        int op;
        cin >> op;
        if(op==1){
            ll x;
            cin >> x;
            st.insert(x);
            stneg.insert(-x);
        }
        else if(op==2){
            ll x, k;
            cin >> x >> k;
            auto it = st.upper_bound(x);
            bool bad = false;
            while(k--){
                if(it==st.begin()){
                    bad = true; break;
                }
                it--;
            }
            if(bad){
                cout << -1 <<"\n";
            }
            else{
                cout <<  (*it) <<"\n";
            }
        }
        else{
            ll x, k;
            cin >> x >> k;
            auto it = stneg.upper_bound(-x);
            bool bad = false;
            while(k--){
                if(it==stneg.begin()){
                    bad = true; break;
                }
                it--;
            }
            if(bad){
                cout << -1 <<"\n";
            }
            else{
                cout << -(*it) <<"\n";
            }
        }
    }

    return 0;
}