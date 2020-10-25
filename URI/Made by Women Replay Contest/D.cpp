#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    return ((!b) ? a : gcd(b,a%b));
}



int main(){
    int n;


    while(cin >> n){
        if(!n) break;
        int cnt=0;
        vector<int> a(n,0), b(n,0);
        vector<pair<int,int>> pares_retardados;
        for(auto &x:a)
            cin >> x;
        for(auto &x:b)
            cin >> x;
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        
        for(auto x:a)
            for(auto y:b)
                if(gcd(x,y)==1)
                    pares_retardados.push_back({x,y});
        for(auto x:b)
            for(auto y:a)
                if(gcd(x,y)==1)
                    pares_retardados.push_back({x,y});
        sort(pares_retardados.begin(), pares_retardados.end());
        pares_retardados.erase(unique(pares_retardados.begin(), pares_retardados.end()), pares_retardados.end());                
        cout << pares_retardados.size() <<'\n';
    }

    return 0;
}