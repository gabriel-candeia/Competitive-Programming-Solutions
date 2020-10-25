#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, sum, pivot=0, diff=0;
        vector<int> arr;

        cin >> n >> x;
        arr.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];   
            if(arr[i]==x)
                pivot = i;
            diff+=(arr[i]!=x);
        }

        swap(arr[pivot],arr[0]);
        if(diff==0){
            cout << 0 <<'\n';
        }
        else if(arr[0]==x){
            cout << 1 << '\n';
        }
        else{
            for(int i=1;i<n;i++){
                arr[0]-=(x-arr[i]);
            }
            cout << 1 + (arr[0]!=x) <<'\n';
        }
    }

    return 0;
}