#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    vector<int> arr;

    cin >> t;
    while(t--){
        cin >> n;
        arr.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        sort(arr.rbegin(),arr.rend());

        for(int i=0;i<n;i++){
            cout << arr[i] << ' ';
        }
        cout << '\n';
    }


    return 0;
}