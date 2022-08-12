#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        cin >> n;
        multiset<ll> st;
        ll sum = 0;

        for(int i=0;i<n;i++){
            ll x;
            cin >> x;
            sum += x;
            st.insert(x);
        }

        vector<ll> valores;
        valores.push_back(sum);
        while(n && valores.size()){
            ll x = valores.back();
            valores.pop_back();
            if(st.find(x)==st.end()){
                valores.push_back(x/2);
                valores.push_back(x/2+x%2);
                n--;
            }
            else{
                st.erase(st.find(x));
            }
        }

        cout << ((valores.size()==0) ? "YES" : "NO") <<"\n";

    }

    return 0;
}