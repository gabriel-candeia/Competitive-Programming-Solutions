#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, cnt=0, answer=0;
    string s;
    stack<char> st;

    cin >> n;
    cin >> s;

    for(int i=0;i<n;i++){
        cnt += 1*(s[i]=='(') -1*(s[i]==')');
        if(s[i]=='(' || st.size()==0){
            st.push(s[i]);
        }
        else if(s[i]==')' && st.top()=='('){
            st.pop();
        }
        else{
            st.push(s[i]);
        }
        if(cnt==0){
            answer+=st.size();    
            while(st.size()){
                st.pop();
            }
        }
    }
        
    if(cnt!=0){
        cout << -1 << '\n';
    }
    else{
        cout << answer << '\n';
    }

    return 0;
}