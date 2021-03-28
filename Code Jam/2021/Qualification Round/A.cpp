#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, caso=0;

    cin >> t;
    while(t--){
        int n, answ=0;
        vector<int> arr;
        
        cin >> n; arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;

        for(int i=0;i<n-1;i++){
            int pivot = i;
            for(int j=i;j<n;j++)
                if(arr[j]<arr[pivot])
                    pivot = j;
            answ += pivot-i+1;
            for(int j=0;j<(pivot-i+1)/2;j++){
                swap(arr[i+j],arr[pivot-j]);
            }
        }

        cout << "Case #" << ++caso << ": " << answ << "\n";
        
    }

    return 0;
}