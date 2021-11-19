#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<int> arr[2];

        cin >> n;


        for(int i=0;i<n;i++){ 
            int x;
            cin >> x;
            arr[x%2].push_back(x);
        }

        vector<int> answ;
        for(int i=0;i<2;i++)
            for(auto x:arr[i])
                answ.push_back(x);

        int acm = 0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                acm += (__gcd(answ[i],2*answ[j])>1);
        cout << acm <<"\n";
    }

    return 0;
}