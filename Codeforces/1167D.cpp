#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    vector<bool> answ;
    stack<bool> st;
    int bal = 0;
    
    cin >> n;
    cin >> s;

    answ.assign(s.size(),0);
    for(int i=0;i<n;i++){
        if(s[i]==')'){
            bal--;
        }
        answ[i] = (bal%2);
        if(s[i]=='('){
            bal++;
        }
    }

    for(int i=0;i<n;i++){
        cout << answ[i];
    }
    cout << '\n';

    return 0;
}
