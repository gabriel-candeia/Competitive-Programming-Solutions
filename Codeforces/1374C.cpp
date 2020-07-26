#include<bits/stdc++.h>
using namespace std;

int func(string s, int n){
    vector<char> st;
    for(auto x:s){
        if((x=='(' || st.size()==0)||(st.back()==')' && x==')')){
            st.push_back(x);
        }
        else{
            st.pop_back();
        }
    }
    int cnt=0;
    for(auto x:st){
        cnt+=(x==')');
    }
    return cnt;
}

int main(){
    int t, n;
    string s;

    cin >> t;
    while(t--){
        cin >> n >> s;
        cout << func(s,n) << '\n';
    }

    return 0;
}