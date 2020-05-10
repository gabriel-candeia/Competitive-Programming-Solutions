#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    vector<int> arr;

    cin >> t;
    while(t--){

        cin >> n;
        arr.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        int a=0,b=0,t=0,sumA=0,sumB=0;
        int l=0,r=n-1;
        while(l<=r && l<n){
            sumA=0;
            t++;
            while(l<=r && l<n && sumA<=sumB){
                sumA+=arr[l++];
            }
            a+=sumA;
            sumB=0;
            t+=(r>=l);
            while(l<=r && r>=0 && sumB<=sumA){
                sumB+=arr[r--];
            }
            b+=sumB;
        }

        cout << t << ' ' << a << ' ' << b << ' ' << '\n';
        
    }

    return 0;
}