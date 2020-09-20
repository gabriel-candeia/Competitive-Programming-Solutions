#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n; vector<int> a;

        cin >> n; 
        a.assign(n,0);
        int ones=0;
        for(int i=0;i<n;i++){
            cin >> a[i];
            ones+=a[i];
        }

        int target = 0;
        if(ones-ones%2>=n/2){
            target = 1;
            n+=2*(n/2%2);
        }

        cout << n/2 << '\n';
        for(int i=0;i<n/2;i++){
            cout << target << ' ';
        }cout <<'\n';
    }
    return 0;
}