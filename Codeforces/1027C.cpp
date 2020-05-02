#include<bits/stdc++.h>
using namespace std;

double calc(double a, double b){
    return (2*a+2*b)*(2*a+2*b)/(a*b);
}

int main(){
    int t, n, x;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        vector<int> pares, arr;
        cin >> n;
        arr.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        sort(arr.begin(),arr.end());

        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1]){
                pares.push_back(arr[i]);
                i++;
            }
        }

        double ratio = calc(pares[0],pares[1]), cmp;
        int answ = 1;
        
        for(int i=1;i<pares.size();i++){
            
            cmp = calc(pares[i-1],pares[i]);
            if(cmp < ratio){
                answ = i;
                ratio = cmp;
            }
        }
        

        cout << pares[answ-1] <<' '<< pares[answ-1] <<' '<< pares[answ] <<' '<< pares[answ] <<'\n';

    }

    return 0;
}