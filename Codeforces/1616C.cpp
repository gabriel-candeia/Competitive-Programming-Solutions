#include<bits/stdc++.h>
using namespace std;

double eps = 1e-6;
bool comp(double a, double b){
    if(b>a)
        return b-a > eps;
    return a-b > eps;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<double> arr;

        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        
        int answ = n-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int temp = 0;
                double delta = (j-i!=0) ? (arr[j]-arr[i])*1.0/(j-i) : 0;
                for(int k=0;k<n;k++){
                    temp += (comp(arr[k],(arr[i] + delta*(k-i))));
                }
                answ = min(answ,temp);
            }
        }
        cout << answ <<"\n";

    }



    return 0;
}