#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        vector<int> cnt, answ;
        vector<vector<int>> arr;

        cin >> n >> m; cnt.assign(n+1,0), answ.assign(m,-1);
        for(int i=0, j;i<m;i++){
            cin >> j;
            vector<int> c(j+2,0);
            for(int i=2;i<c.size();i++)
                cin >> c[i];
            c[0] = j, c[1] = i;
            arr.push_back(c);
        }

        sort(arr.begin(),arr.end());

        bool poss = true;
        for(int i=0;i<m;i++){
            for(int j=2;j<arr[i].size();j++){
                if(cnt[arr[i][j]]!=m/2+m%2){
                    answ[arr[i][1]] = arr[i][j];
                    cnt[arr[i][j]]++;
                    break;
                }
            }
        }

        for(int i=0;i<m;i++)
            if(answ[i]==-1) poss = false;

        if(poss){
            cout << "YES\n";
            for(auto x:answ)
                cout << x << " ";
            cout<<'\n';
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}