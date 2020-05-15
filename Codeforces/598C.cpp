#include<bits/stdc++.h>
#define ld long double
using namespace std;

int main(){
    vector<pair<ld,int>> arr;
    int n, a, b;

    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a >> b;
        arr.push_back({(a!=0) ? b/a : M_PI/2,i});
    }

    sort(arr.begin(),arr.end());
    ld mn = 100;
    int bi, bj;
    for(int i=0;i<n;i++){
        cout << arr[i].first << ' ';
        if(arr[(i+1)%n].first-arr[i].first<mn){
            mn = arr[(i+1)%n].first-arr[i].first;
            bi = arr[(i+1)%n].second;
            bj = arr[i].second;
        }
    }
    cout << endl;

    cout << bi << " " << bj << '\n';

    return 0;
}