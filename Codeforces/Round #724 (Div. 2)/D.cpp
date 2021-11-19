#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        bool ok = true;
        int n, med;
        set<int> st;
        cin >> n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            st.insert(x);
            if(i==0){
                med = x;
            }
            else if(med>x){
                auto it = st.find(med);
                med = *(--it);
                ok = ok && (med==x);
            }
            else if(med<x){
                auto it = st.find(med);
                med = *(++it);
                ok = ok && (med==x);
            }
        }

        cout << ((ok) ? "YES" : "NO") << "\n";
    }

    return 0;
}