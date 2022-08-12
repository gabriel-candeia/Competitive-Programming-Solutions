#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<ll> arr;

        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        reverse(arr.begin(),arr.end());

        int answ = 1;
        vector<ll> lastBest(arr.begin(),arr.end());
        /*for(int i=0;i<n;i++){
            cout << lastBest[i] << " ";
        }cout<<"\n";*/
        for(int j=2;(1+j)*j<=2*n;j++){
            //cout << j << "\n";
            ll acm = 0;
            vector<ll> currBest(n,0);
            for(int i=1;i<n;i++)
                lastBest[i] = max(lastBest[i],lastBest[i-1]);
            bool flag = true;
            for(int i=0;i<j;i++)
                acm += arr[i];
            for(int i=0;i+j-1<n;i++){
                if(i-j+1>=0 && lastBest[i-j+1]>acm)
                    currBest[i] = acm, flag = false;
                if(i+j<n)
                    acm += arr[i+j]-arr[i];
            }
            /*for(int i=0;i<n;i++){
                cout << currBest[i] << " ";
            }cout <<"\n";*/
            if(flag==true) break;
            answ = j;
            lastBest = currBest;
        }

        cout << answ <<"\n";

    }

    return 0;
}