#include <bits/stdc++.h>
using namespace std;
#define maxn int(1e5+10)

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, d, m;
    cin >> t >> d >> m;
    int mmax = 0;
    vector<int> arr;

    arr.assign(m,0);
    for(auto &x:arr)
        cin >> x;
    arr.push_back(0);
    arr.push_back(d);
    sort(arr.begin(),arr.end());
    unique(arr.begin(),arr.end());
    bool answ = false;
    for(int i=1;i<arr.size();i++){
        if(arr[i]-arr[i-1] >= t)
            answ = true;
    }

    cout << (answ ? "Y" : "N") << "\n";
    return 0;
}
