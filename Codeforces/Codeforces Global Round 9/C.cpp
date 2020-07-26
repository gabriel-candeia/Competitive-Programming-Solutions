#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    vector<int> a;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n;
        a.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        stack<int> st;
        int last;
        st.push(a[0]);
        for(int i=1;i<n;i++){
            last = a[i];
            while(st.size() && a[i]>st.top()){
                last  = st.top();
                st.pop();
            }
            st.push(last);
        }
        if(st.size()==1){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}