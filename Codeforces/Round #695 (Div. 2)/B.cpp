#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, answ=0, acm=0;
        vector<int> arr, c;

        cin >> n; 
        arr.assign(n,0); c.assign(n,0);
        for(auto &x:arr)
            cin >> x;

        for(int i =1;i<n-1;i++){
            if(arr[i]>max(arr[i+1],arr[i-1]))
                c[i] = 1;
            if(arr[i]<min(arr[i+1],arr[i-1]))
                c[i] = -1;
            acm += abs(c[i]);
        }
        answ = acm;

        for(int i=1;i<n-1;i++){
            int val[3] = {min(arr[i-1],arr[i+1]),min(arr[i-1],arr[i+1]),max(arr[i-1],arr[i+1])}, x = n+200, old = arr[i];
            for(int j=0;j<3;j++){
                int temp = acm - abs(c[i-1]) - abs(c[i+1]) - abs(c[i]);
                arr[i] = val[j];
                for(int k=max(i-1,1);k<=min(i+1,n-2);k++){
                    if(arr[k]>max(arr[k+1],arr[k-1]))
                        temp++;
                    if(arr[k]<min(arr[k+1],arr[k-1]))
                        temp++;
                }
                x = min(temp,x);
            }
            arr[i] = old;
            answ = min(answ,x);
        }

        cout << answ <<'\n';
    }
    return 0;
}