#include<bits/stdc++.h>
using namespace std;

void reverse(string& s,int n){
    char temp;
    for(int i=0;i<n/2;i++){
        temp = s[i];
        s[i] = s[n-i-1];
        s[n-i-1] = temp;
    }
}

int main(){
    string s;
    int n ;

    cin >> s;
    n = s.size();
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]){
            reverse(s,i+1);
            cout << 1 << ' ';
        }
        else{
            cout << 0 << ' ';
        }
    }

    if(s[0]=='b'){
        reverse(s,n);
        cout << 1;
    }
    else{
        cout << 0;
    }
    cout << '\n';

    return 0;
}