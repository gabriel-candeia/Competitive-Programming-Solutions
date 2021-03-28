#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, k;
        vector<int> arr;

        cin >> n >> k; arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        sort(arr.begin(),arr.end());
        unique(arr.begin(),arr.end());

        int answ = arr.size();

        if(k!=0){
            int mex = 0, mx = arr[arr.size()-1], novo;
            for(mex=0;mex<arr.size() && mex==arr[mex];mex++);
            novo = (mex+mx)/2 + (mex+mx)%2;
            
            if(mex<mx){
                answ++;
                for(auto x:arr)
                    if(x==novo)
                        answ--;
            }
            else{
                answ+=k;
            }
        }

        cout << answ << '\n';
    }

    return 0;
}