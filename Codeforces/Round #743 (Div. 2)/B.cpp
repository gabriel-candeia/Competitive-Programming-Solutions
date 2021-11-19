#include<bits/stdc++.h>
using namespace std;



int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<int> arr;

        cin >> n;

        arr.assign(2*n+1,0);

        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            arr[x] = i;
        }
        
        for(int i=2;i<=2*n;i++){
            if(i%2==0)
                arr[i] = arr[i-1];
            else
                arr[i] = min(arr[i-1],arr[i]);
        }

        int answ = 3*n;
        for(int i=0;i<n;i++){
            int x;
            cin >> x;
            answ = min(answ,i+arr[x]);
        }

        cout << answ <<"\n";

    }

    return 0;
}