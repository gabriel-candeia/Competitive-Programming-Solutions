#include<bits/stdc++.h>
#define maxn int(100)
using namespace std;

int answ[maxn];

int main(){
    int n;
    cin >> n;

    answ[0] = 1;
    cout << answ[0] <<"\n";
    for(int i=1;i<=n-1;i++){
        for(int j=i;j>=0;j--){
            answ[j] += answ[j-1];
            if(j==i) answ[j] = 1;
        }
        for(int j=0;j<=i;j++){
            cout << answ[j] <<" ";
        }
        cout <<"\n";
    }

    return 0;
}