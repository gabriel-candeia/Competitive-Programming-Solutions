#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    vector<pair<int,int>> arr;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        arr.push_back({b,a});
    }

    sort(arr.begin(),arr.end());

    int last = -1, cnt=0;
    for(auto p : arr){
        if(p.second>=last){
            last = p.first;
            cnt++;
        }
    }

    cout << cnt <<'\n';

    return 0;
}