#include<bits/stdc++.h>
using namespace std;

bool isPermutation(vector<int>& arr, int l, int n, int mx){
    vector<int> visited(mx+1,0);
    bool ret = true;
    for(int i=l;i<l+n;i++){
        visited[arr[i]]++;
    }

    for(int i=1;i<=n && ret;i++){
        ret = ret && (visited[i]==1);
    }

    return ret;
}

int main(){
    int t, n, mx;
    bool f1, f2;
    vector<int> arr;

    cin >> t;
    while(t--){
        cin >> n;
        
        arr.assign(n+1,0);
        mx = 0;

        for(int i=0;i<n;i++){
            cin >> arr[i];
            mx = max(mx,arr[i]);
        }
        f1 = (isPermutation(arr,0,mx,mx) && isPermutation(arr,mx,n-mx,mx));
        f2 = (isPermutation(arr,0,n-mx,mx) && isPermutation(arr,n-mx,mx,mx));
        cout << f1+f2*(mx!=n-mx) <<"\n";
        if(f1){
            cout << mx <<" "<< n-mx << '\n';
        }
        if(f2 && mx!=n-mx){
            cout << n-mx <<" "<< mx << '\n';
        }
    }
    return 0;
}