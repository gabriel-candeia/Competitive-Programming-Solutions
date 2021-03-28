#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> ans;
        for(int i=k-1;i>=k/2+k%2;i--){
            ans.push_back(i);
        }

        for(int i=k+1;i<=n;i++){
            ans.push_back(i);
        }

        cout << ans.size() << '\n';
        for(auto x:ans)
            cout << x << " ";
        cout<<'\n';
    }

    return 0;
}