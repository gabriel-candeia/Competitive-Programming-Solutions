#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, a;
    int distinct, answ, maxrep;
    map<int,int> rep;

    cin >> t;
    while(t--){
        cin >> n;
        rep.clear();
        maxrep = 0; distinct=0;
        for(int i=0;i<n;i++){
            cin >> a;
            if(rep.count(a)==0){
                distinct++;
            }
            rep[a]++;
            maxrep = max(maxrep,rep[a]);
        }
        if(distinct>maxrep){
            cout << maxrep << '\n';
        }
        else if(distinct==maxrep){ 
            cout << maxrep-1 << '\n';
        }
        else{
            cout << distinct << '\n';
        }
    }

}