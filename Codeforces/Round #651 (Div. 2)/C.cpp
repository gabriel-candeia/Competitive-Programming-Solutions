#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    ll n;

    cin >> t;
    while(t--){
        cin >> n;
    
        bool first = (n%2);
        int cnt=0, lim = sqrt(n)+1, l, acm;

        if(n==1){
            first = false;
        }
        else if(n==2){
            first = true;
        }
        else{
            int par = 1;
            while(n%2==0){
                n/=2;
                par*=2;
            }
 
            acm = n;
            for(int i=3;i<=lim;i+=2){
                while(acm%i==0){
                    acm/=i;
                    cnt++;
                }
            }        
            cnt+=(acm!=1);

            if(par==2){
                first = (cnt>1);
            }
            else{
                first = (cnt!=0);
            }
        }

        if(first){
            cout << "Ashishgup\n";
        }
        else{
            cout << "FastestFinger\n";  
        }
    }

    return 0;
}