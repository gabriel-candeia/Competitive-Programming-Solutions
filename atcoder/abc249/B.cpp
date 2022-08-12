#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    bool f1=false, f2=false;
    set<char> st;
    cin >> s;
    for(auto c:s){
        f1 = f1 || (c>='a');
        f2 = f2 || (c<'a');
        st.insert(c);
    }

    if(f1 && f2 && st.size()==s.size())
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}