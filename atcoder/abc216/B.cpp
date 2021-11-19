#include<bits/stdc++.h>
using namespace std;

int main(){
    set<string> st;
    int n;

    cin >> n;
    bool answ = false;
    for(int i=0;i<n;i++){
        string s1, s2;
        cin >> s1 >> s2;
        s1 += " " + s2;
        if(st.find(s1)!=st.end()){
            answ = true;
        }
        st.insert(s1);
    }

    if(answ){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}