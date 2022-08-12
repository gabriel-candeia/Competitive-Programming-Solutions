#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        vector<int> answ;
        while(b!=1){
            answ.push_back(a/b);
            a = a%b;
            swap(a,b);
        }
        answ.push_back(a);

        cout << answ.size()-1 <<" ";
        for(auto x:answ)
            cout << x << " ";
        cout<<"\n";

    }

    return 0;
}