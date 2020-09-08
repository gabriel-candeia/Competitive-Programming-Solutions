//lesei demais

#include<bits/stdc++.h>
#define maxn 20
using namespace std;

int arr[20];
int main(){
    int t, n;
    cin >> t;
    while(t--){

        cin >> n;
        int base = 0;
        cout << 1 << " "  << 1 <<endl;
        cin >> base;

        for(int i=1;i<maxn;i++){
            cout << 1 << " "  << (1<<i)+1 <<endl;
            cin >> arr[i];
        }

        int pot = 1;
        for(int i=0;i<maxn;i++){
            arr[i] = (base-arr[i])/pot;
            //cout << arr[i] << ' ';
            pot*=2;
        }// cout <<'\n';

        int answ= ((n%2 - base%2)+2)%2;
        for(int i=1;i<maxn;i++){
            if(((n-arr[i])/2)%2!=n%2){
                answ += (1<<i);
            }
        }

        cout << 2 << " " << answ <<endl;
        cin >> answ;
        if(answ!=1)
            break;
    }

    return 0;
}