#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, answer=0, acm=1;
    string s; 
    cin >> s;

    n = s.size();
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            acm++;
        }
        else{
            answer = max(answer,acm);
            acm=1;
        }
    }
    answer = max(answer,acm);

    cout << answer <<'\n';
    return 0;
}