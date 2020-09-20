#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;
    vector<int> color;
    vector<pair<char,int>> arr;

    cin >> n >> s;
    color.assign(n,-1);
    for(int i=0;i<n;i++)
        arr.push_back({s[i],i});
    
    for(int i=n-1;i>=0;i--){
        if(color[arr[i].second]==-1){
            int mx = i;
            for(int j=i;j>=0;j--){
                if(arr[j].first > arr[mx].first)
                    mx = j;
            }
            color[arr[mx].second] = 1;
            for(int j=mx;j<n-1;j++){
                if(color[arr[j+1].second]==-1)
                    color[arr[j+1].second] = 0;
                if(color[arr[j].second]!=color[arr[j+1].second] && arr[j].first>arr[j+1].first)
                    swap(arr[j],arr[j+1]);
            }
        }
    }

    bool ok=true;
    for(int i=0;i<n-1;i++)
        if(arr[i].first>arr[i+1].first)
            ok  = false;

    if(ok){
        cout << "YES\n";
        for(auto x:color)
            cout << x;
        cout <<'\n';
    }
    else{
        cout << "NO\n";
    }

    return 0;
}