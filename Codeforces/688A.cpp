#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, d, answ=0, acm=0;
    bool flag;
    string s;

    cin >> n >> d;

    for(int i=0;i<d;i++){
        cin >> s;
        flag = true;
        for(auto i:s){
            if(i=='0'){
                acm++;
                flag = false;
                break;
            }
        }
        if(flag){
            acm = 0;
        }
        answ = max(answ,acm);
    }
    answ = max(answ,acm);

    cout << answ << '\n';

    return 0;
}