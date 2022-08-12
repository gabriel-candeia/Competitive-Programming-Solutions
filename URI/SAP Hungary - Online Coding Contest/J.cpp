#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;    
    while(cin >> n){
        if(n==0) break;
        vector<pair<int,string>> arr;
        string s;
        int a, b;

        for(int i=0;i<n;i++){   
            cin >> s >> a >> b; 
            arr.push_back({a-b,s});
        }
        sort(arr.begin(),arr.end());
        cout << arr[0].second <<"\n";

    }

    return 0;   
}