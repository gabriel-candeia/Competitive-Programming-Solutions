#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int first = -1, last = -1, n = s.size();
        for(int i=0;i<n-1;i++){
            if(s[i]+s[i+1]-'0'-'0'<10){
                first = i;
                break;
            }
        }
        for(int i=n-1;i>0;i--){
            if(s[i]+s[i-1]-'0'-'0'>=10){
                last = i-1;
                break;
            }
        }
        string answ;
        int pivot = first;
        if(last!=-1){
            pivot = last;
        }
        answ = s.substr(0,pivot) +  to_string(s[pivot]+s[pivot+1]-'0'-'0') + s.substr(pivot+2);
        cout << answ <<"\n";
    }

    return 0;
}