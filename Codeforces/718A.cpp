#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, t;
    ll dot=0, top=0, carry=0;
    bool dec = true;
    string s;
    
    cin >> n >> t;
    cin >> s;
    while(dot < n && s[dot]!='.'){
        dot++;
    }

    top = dot+1;
    while(top < n && s[top]<'5'){
        top++;
    }

    if(top<n){
        carry = 1;
        t--;
    }
    cout << s[dot]  <<'\n';
    while(top>dot && carry){
        if(carry){
            s[top]++;
            carry = 0;
        }
        if(s[top]>'9'){
            carry = 1;
        }
        else if(s[top]>='5' && t){
            t--;
            carry = 1;
        }else{
            carry = 0;
            break;
        }
        top--;
    };

    if(s[dot+1]>'9' || (s[dot+1]>='5' && t)){
        carry = 1;
        for(int i=dot-1;i>=0;i--){
            if(s[i]=='9' && carry){
                s[i] = '0';
            }
            else{
                s[i]++;
                carry = 0;
                break;
            }
        }
        if(s[0]=='0' && carry){
            cout << 1;
        }

        for(int i=0;i<dot;i++){
            cout << s[i];
        }
        cout << '\n';
    
    }
    else{
        for(int i=0;i<=top;i++){
            cout << (char)s[i];
        }
        cout << '\n';
    }



    return 0;
}