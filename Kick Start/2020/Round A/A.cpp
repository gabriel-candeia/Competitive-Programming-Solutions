#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, caso=0;
    cin >> t;
    while(t--){
        int n, b;
        vector<int> arr;
        
        cin >> n >> b;
        arr.assign(n,0);
        for(auto &p:arr)
            cin >> p;
        
        sort(arr.begin(),arr.end());
        arr.push_back(0);
        int answ=0, acm=0;
        while(acm<=b && answ<=n)
            acm+=arr[answ++];
            
        cout << "Case #"<< ++caso<<": "<< answ-1 <<'\n';
    }
    return 0;
}