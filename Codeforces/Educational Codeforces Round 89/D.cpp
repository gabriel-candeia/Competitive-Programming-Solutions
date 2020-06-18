#include<bits/stdc++.h>
#define N 4000
using namespace std;

int main(){
    int n;
    vector<int> sieve(int(1e4),1), arr, x, primes;

    sieve[0] = sieve[1] = 0;
    
    for(int i=0;i<=N;i++){
        if(sieve[i]==1){
            for(int j=2*i;j<=N;j+=i ){
                sieve[j] = false;
            }
            for(int j=i;j<=N;j*=i){
                sieve[j] = 2;
            }
            primes.push_back(i);
        }
    }

    sieve[1] = 1;
    
    cin >> n;
    arr.assign(n,0);
    x.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        x[i] = -1;
        for(int j=0;j<primes.size();j++){
            if(arr[i]%primes[j]==0){
                int temp = arr[i];
                while(temp%primes[j]==0){
                    temp/=primes[j];
                }
                if(temp!=1){
                    x[i] = temp;
                }
                break;
            }
        }
    }

    for(int i=0;i<n;i++){
        cout << x[i] << ' ';;
    }
    cout << '\n';

    for(int i=0;i<n;i++){
        if(x[i]==-1){
            cout << x[i] << ' ';;
        }
        else{
            while(arr[i]%x[i]==0){
                arr[i]/=x[i];
            }
            cout << arr[i] << ' ';
        }
    }
    cout << '\n';


    return 0;
}