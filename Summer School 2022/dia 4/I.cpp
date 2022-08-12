#include<bits/stdc++.h>
using namespace std;


int main(){
    int n;
    string s;
    vector<bool> arr;

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> s;
        arr.push_back((s=="TRUTH") ? 1 : 0);
    }

    reverse(arr.begin(),arr.end());
    for(int i=1;i<n;i++){
        if(arr[i-1]==0)
            arr[i] = !arr[i];
    }

    cout << ((arr[n-1]==1) ? "TRUTH" : "LIE") <<"\n";

    return 0;
}