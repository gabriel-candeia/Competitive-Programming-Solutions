#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set<int> st;

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        st.insert(x);
    }

    cout << st.size() <<"\n";

    return 0;
}