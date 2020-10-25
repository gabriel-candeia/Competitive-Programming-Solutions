#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        vector<char> st;    
        cin >> s;
        st.push_back('X');
        for(auto c:s){
            if((st.back()=='B' || st.back()=='A') && c=='B')
                st.pop_back();
            else
                st.push_back(c);
        }
        cout << st.size()-1 <<'\n';
    }

    return 0;
}