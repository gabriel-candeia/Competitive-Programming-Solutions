#include<bits/stdc++.h>
using namespace std;

int main(){
    int h, s, m, d;
    int oh, om, os;

    cin >> h >> m >> s;
    oh = h, om = m, os = s;
    d = __gcd(__gcd(h,m),s);

    h/=d, m/=d, s/=d;

    vector<vector<int>> answ;
    for(int i=0;true;i++){
        if(i*h <oh && i*m<om && i*s<os){
            answ.push_back({i*h,i*m,i*s});
        }
        else{
            break;
        }
    }

    cout << answ.size() <<"\n";
    for(auto x:answ){
        cout << x[0] << " " << x[1] << " " << x[2] <<"\n";
    }

    return 0;
}