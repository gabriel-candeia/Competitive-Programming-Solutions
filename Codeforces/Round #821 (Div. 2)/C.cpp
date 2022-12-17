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

        vector<pair<int,int>> answ;

        if(arr[0]%2!=arr.back()%2){
            arr[n-1] = arr[0];
            answ.push_back({1,n});
        }
        
        for(int i=n-1;i>=0;i--){
            if(arr[i]%2==arr.back()%2 && arr[i]!=arr.back()){
                arr[i] = arr.back();
                answ.push_back({i+1,n});
            }
        }

        for(int i=0;i<n;i++){
            if(arr[i]%2!=arr.back()%2){
                arr[i] = arr.back();
                answ.push_back({1,i+1});
            }
        }

        cout << answ.size() <<"\n";
        for(auto p:answ)    {
            cout << p.first << " " << p.second <<"\n";
        }

    }

    return 0;
}