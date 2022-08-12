#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9+1;
int main(){
    int n;
    vector<array<int,4>> arr;

    cin >> n;
    arr.assign(n,{0,0,0,0});
    for(int i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
        arr[i][3] = i;
    }

    vector<int> safe(n,0);
    for(int k=0;k<2;k++){
        int mn1 = inf, mn2 = inf, last = 0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(mn1<arr[i][1] || mn2<arr[i][2])
                safe[arr[i][3]] = 1;
            if(i+1<n && arr[i][0]!=arr[i+1][0]){
                for(last;last<=i;last++){
                    mn1 = min(mn1,arr[last][1]);
                    mn2 = min(mn2,arr[last][2]);
                }
            }
            swap(arr[i][0],arr[i][1]);
        }
    }

    vector<int> answ;
    for(int i=0;i<n;i++)
        if(safe[i]==0)
            answ.push_back(i+1);
    
    cout << answ.size() <<"\n";
    for(auto x:answ)
        cout << x << " ";
    cout<<"\n";

    return 0;
}