#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n;
    vector<int> bits(30,0);
    string answ = "";
    cin >> n;
    int ptr = 0;
    while(n){
        bits[ptr++]=n%2;
        n/=2;
    }
    for(int i=ptr-1;i>=0;i--){
        if(i!=ptr-1)
            answ.push_back('B');
        if(bits[i])
            answ.push_back('A');
    }
    
    cout << answ <<"\n";
    return 0;
}