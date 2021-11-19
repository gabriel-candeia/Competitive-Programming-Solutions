#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<int> arr(n+1,0);
        for(int i=0;i<m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            arr[b]++;
        }

        int centro = -1;
        for(int i=1;i<=n;i++){
            if(arr[i]==0){
                centro = i;
                break;
            }
        }

        for(int i=1;i<=n;i++){
            if(i!=centro){
                cout << centro << " " << i <<"\n";
            }
        }
    }


    return 0;
}