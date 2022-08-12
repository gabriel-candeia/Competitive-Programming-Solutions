#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, on;
        vector<int> arr, freq;

        cin >> n;
        on = n;
        arr.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        freq.push_back(1);

        for(int i=1;i<n;i++){
            if(arr[i]==arr[i-1]){
                freq[freq.size()-1]++;
            }
            else{
                freq.push_back(1);
            }
        }

        int answ = 1e8;
        n = freq.size();
        for(int i=1;i<=2*on;i = 2*i){
            for(int j=1;j<=2*on;j = 2*j){
                int x=0, y=0, z=0, ptr = 0;
                for(;ptr<n && x+freq[ptr]<=i;ptr++){
                    x+=freq[ptr];
                }
                for(;ptr<n && y+freq[ptr]<=j;ptr++){
                    y+=freq[ptr];
                }
                for(;ptr<n;ptr++){
                    z+=freq[ptr];
                }
                int pot = 1;
                while(pot<z)
                    pot = 2*pot;
                
                answ = min(answ,(i-x) + (j-y) + (pot-z));
            }
        }

        cout << answ << "\n";
    }

    return 0;
}