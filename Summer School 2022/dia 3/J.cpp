#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s, t, answ = "-1";

    cin >> s;

    n = s.size();
    t = s;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(t[j]<t[i] && (t[j]!='0'||i!=0) ){
                swap(t[j],t[i]);
                if(t>answ || answ=="-1")
                    answ = t;
                swap(t[j],t[i]);
            }
        }
    }

    cout << answ <<"\n";

    return 0;
}