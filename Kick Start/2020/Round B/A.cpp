#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t, caso=0;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> arr(n,0);
        for(auto &x:arr)
            cin >> x;
        
        int cnt = 0;
        for(int i=1;i<n-1;i++)
            cnt+= (arr[i]>arr[i-1])&&(arr[i]>arr[i+1]);

        cout <<"Case #" <<++caso << ": "<< cnt <<'\n';
    }


    return 0;
}