#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> st;
    int n, q;

    cin >> n >> q;
    st.insert(0), st.insert(n);

    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        if(a==1){
            st.insert(b);
        }
        else{
            auto it = st.lower_bound(b); it--;
            int answ = *(st.upper_bound(b))-*(it);
            cout << answ <<'\n';
        }
    }

    return 0;
}