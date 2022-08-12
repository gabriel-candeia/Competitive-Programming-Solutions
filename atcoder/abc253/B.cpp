#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    vector<pair<int,int>> arr;

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            if(c=='o'){
                arr.push_back({i,j});
            }
        }
    }

    cout << abs(arr[0].first-arr[1].first) + abs(arr[0].second-arr[1].second) <<"\n";

    return 0;
}