#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<int> arr;
        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        vector<int> answ;
        int t1 = 0, t2 = n-1;
        while(answ.size()<n){
            if(answ.size()%2){
                answ.push_back(arr[t2--]);
            }
            else{
                answ.push_back(arr[t1++]);
            }
        }
        for(auto &x:answ)
            cout << x << " ";
        cout<<'\n';
    }
    return 0;
}