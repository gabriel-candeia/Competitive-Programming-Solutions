#include<bits/stdc++.h>
using namespace std;

int main(){
    map<int,int> freq;
    int q;

    cin >> q;
    while(q--){
        int op, x, c;
        cin >> op;
        if(op==1){
            cin >> x;
            freq[x]++;
        }
        else if(op==2){
            cin >> x >> c;
            freq[x] -= min(freq[x],c);
            if(freq[x]==0){
                freq.erase(freq.find(x));
            }
        }
        else{
            cout << freq.rbegin()->first-freq.begin()->first <<"\n";
        }
    }

    return 0;
}