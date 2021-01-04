#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, q;

    cin >> q;
    while(q--){
        cin >> n;
        vector<int> arr(n+1,0);
        for(int i=0;i<n;i++)
            cin >> arr[i];
        arr[n] = -1;
        
        int answ=0, level = 0, seg = 1;
        for(int i=1;i<n;i++){
            level++;
            if(arr[i]>arr[i+1]){
                seg--;
            }
            if(seg==0){
                answ++;
                seg = level;
                level = 0;
            }
        }
        cout << answ+(level!=0) <<'\n';
    }

    return 0;
}