#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr, precomp(n+2,-1), sufcomp(n+2,-1); arr.assign(n+2,0);
        for(int i=1;i<=n;i++)
            cin >> arr[i];

        precomp[0] = 0;
        sufcomp[n+1] = 0;
        for(int i=1;i<=n && arr[i]>=precomp[i-1];i++)
            precomp[i] = arr[i]-precomp[i-1];
        
        for(int i=n;i>=0 && arr[i]>=sufcomp[i+1];i--)
            sufcomp[i] = arr[i]-sufcomp[i+1];

        bool poss = (sufcomp[0]==0);        
        for(int i=1;i<n && poss==false;i++){
            //cout << precomp[i-1] << "  " << sufcomp[i+2] << " " << arr[i] << " " << arr[i+1] <<'\n';
            if(precomp[i-1]!=-1 && sufcomp[i+2]!=-1 && arr[i+1]>=precomp[i-1] && arr[i]>=sufcomp[i+2] && arr[i]-sufcomp[i+2]==arr[i+1]-precomp[i-1]){
                poss = true;
            }
        }

        cout << ((poss) ? "YES" : "NO") <<'\n';
        
    }

    return 0;
}