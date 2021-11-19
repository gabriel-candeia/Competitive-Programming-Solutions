#include<bits/stdc++.h>
using namespace std;

int main(){
    string p, inv;
    int n;
    vector<string> arr;

    cin >> p;
    inv = string(26,' ');
    for(int i=0;i<26;i++)
        inv[p[i]-'a'] = char(i+'a');

    cin >> n;
    arr.assign(n,"");
    for(int i=0;i<n;i++){
        cin >> arr[i];
        for(auto &c:arr[i])
            c = inv[c-'a'];
        
    }

    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        for(auto &c:arr[i])
            c = p[c-'a'];
        cout << arr[i] << "\n";
    }

    return 0;
}