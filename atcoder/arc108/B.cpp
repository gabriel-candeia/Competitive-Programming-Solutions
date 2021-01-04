#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    vector<char> st;

    cin >> n >> s;
    for(auto c:s){
        st.push_back(c);
        while(st.size()>=3 && st[st.size()-3]=='f' && st[st.size()-2]=='o' && st[st.size()-1]=='x'){
            st.pop_back();
            st.pop_back();
            st.pop_back();
        }
    }
    cout << st.size() <<'\n';
    return 0;
}