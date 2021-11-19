#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, caso=0;

    cin >> t;
    while(t--){
        int n, a, b, soma=0;
        cin >> n >> a >> b;
        vector<int> arr(200,0);

        for(int i=0;i<n;i++){
            cin >> arr[i];
            soma+=arr[i];
        }

        int i =0;
        for(i=0;soma!=1;i++){
            if(arr[i]>arr[i+1]){
                int x = (arr[i+1]+arr[i]);
                arr[i] = x/2;
                arr[i+1] = x/2 + (x)%2;
            }
            soma -= arr[i];
            arr[i+1]-=arr[i];
            arr[i+2] += arr[i];
            arr[i]-=arr[i];
        }
        for(i=0;arr[i]==0;i++);
        cout << "Case #" << ++caso << ": "<< i+1 << "\n";
    }

    return 0;
}