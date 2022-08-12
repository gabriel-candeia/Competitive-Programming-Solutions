#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll a, b, sinalA=1, sinalB=1;
    cin >> a >> b;
    if(a<0) a = -a, sinalA = -1;
    if(b<0) b = -b, sinalB = -1;
    vector<pair<int,ll>> answ;
    while(a!=0 && b!=0){
        if(a>b){
            if(a%b < b-a%b){
                answ.push_back({1,-a/b*sinalA*sinalB});
                 a = a%b;
            }
            else{
                answ.push_back({1,-a/b*sinalA*sinalB - sinalA*sinalB});
                a = b-a%b;
                sinalA = -sinalA;
            }
        }
        else{
            if(b%a < a-b%a){
                answ.push_back({2,-b/a*sinalA*sinalB});
                 b = b%a;
            }
            else{
                answ.push_back({2,-b/a*sinalA*sinalB - sinalA*sinalB});
                b = a-b%a;
                sinalB = -sinalB;
            }
        }
    }

    cout << answ.size() <<"\n";
    for(auto p:answ)
        cout << p.first << " " << p.second<<"\n";

    return 0;
}