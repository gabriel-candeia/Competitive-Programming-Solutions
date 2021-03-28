#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<int> arr, mx;

        cin >> n;
        arr.assign(n,0), mx.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
            mx[i] = (i) ? max(arr[i],mx[i-1]) : arr[i];
        }

        vector<int> answ;
        for(int i=n-1;i>=0;i--){
            for(int j=i;arr[i]==mx[i] && mx[j]==arr[i] && j<n;j++){
                answ.push_back(arr[j]);
            }
        }

        for(auto x:answ)
            cout << x << " ";
        cout<<'\n';
        

    }
    return 0;
}