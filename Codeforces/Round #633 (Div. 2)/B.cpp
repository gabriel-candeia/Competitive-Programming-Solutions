#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, n, x;
    deque<int> arr;
    vector<int> answ;
    cin >> t;

    while(t--){
        cin >> n;
        arr.clear();
        for(int i=0;i<n;i++){
            cin >> x;
            arr.push_back(x);
        }
        sort(arr.begin(),arr.end());
        answ.clear();
        while(arr.size()>=2){
            answ.push_back(arr.back());
            answ.push_back(arr.front());
            arr.pop_back();
            arr.pop_front();
        }

        if(arr.size()){
            answ.push_back(arr.back());
        }

        for(int i=n-1;i>=0;i--){
            cout << answ[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}