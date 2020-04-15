#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, t, n;
    vector<int> even, odd;

    cin >> t;
    while(t--){
        cin >> n;
        even.clear();
        odd.clear();
        for(int i=1;i<=n;i++){
           cin >> x;
           if(x%2) {
               odd.push_back(i);
           }
           else{
               even.push_back(i);
           }
        }
        if(even.size()>=1){
            cout << 1 << '\n';
            cout << even.back() << '\n';
        }
        else if(odd.size()>=2){
            cout << 2 << '\n';
            cout << odd[0] << ' ' << odd[1] <<'\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}