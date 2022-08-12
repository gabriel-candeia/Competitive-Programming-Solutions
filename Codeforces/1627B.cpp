#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, m;
        vector<int> answ;
        cin >> n >> m;
        vector<int> x = {1,n}, y = {1,m};

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int dist = 0;
                for(auto a:x){
                    for(auto b:y){
                        dist = max(dist,abs(a-i)+abs(b-j));
                    }
                }
                answ.push_back(dist);
            }
        }

        sort(answ.begin(),answ.end());
        for(auto x:answ)
            cout << x << " ";
        cout<<"\n";
    }

    return 0;
}