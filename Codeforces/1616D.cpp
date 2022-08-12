#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, x;
        vector<int> arr;
        cin >> n;
        arr.assign(n,0);
        for(auto &y:arr)
            cin >> y;
        cin >> x;
        for(auto &y:arr)
            y = y-x;

        int bst = 0, taken = 0;
        bool flag = true;

        for(int i=0;i<n;i++){
            if(flag==true){
                bst += arr[i];
                flag = false;
            }
            else{
                if(bst+arr[i]<0){
                    taken++;
                    flag = true;
                    bst = 0;
                }
                else{
                    bst = min(bst+arr[i],arr[i]);
                }
            }
        }

        cout << n-taken <<"\n";
    }

    return 0;
}