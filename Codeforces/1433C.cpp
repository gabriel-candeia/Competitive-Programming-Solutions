#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, mx = 0, answ = -1;
        cin >> n;
        vector<int> arr(n+2,0);
        for(int i=1;i<=n;i++){
            cin >> arr[i];
            mx = max(arr[i],mx);
        }
        arr[0] = mx;
        arr[n+1] = mx;

        for(int i=1;i<=n;i++){
            if(arr[i]==mx && (arr[i-1]!=mx || arr[i+1]!=mx)){
                answ = i;
                break;
            }
        }
        cout << answ <<'\n';
    }

    return 0;
}