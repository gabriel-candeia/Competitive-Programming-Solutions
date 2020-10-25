#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, pivot=-1;
        cin >> n;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
            if(arr[i]!=arr[0])
                pivot = i;
        }

        if(pivot==-1){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
            for(int i=1;i<n;i++){
                if(arr[i]!=arr[0]){
                    cout << 1 << " " << i+1 <<"\n";
                }
                else{
                    cout << pivot+1 << " " << i+1 <<"\n";
                }
            }
        }
    }

    return 0;
}