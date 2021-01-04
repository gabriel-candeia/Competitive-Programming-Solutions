#include<bits/stdc++.h>
#define maxn 105
using namespace std;

int n, arr[maxn];
int cnt(int k){
    int answ = 0;
    for(int i=0;i<n;i++)
        answ += ((arr[i]%k)==0);
    return answ;
}  

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int mx=0, answ=0, temp=0;
    for(int i=2;i<=1000;i++){
        temp = cnt(i);
        if(temp>mx){
            mx = temp;
            answ = i;
        }
    }
    cout << answ <<'\n';
    return 0;
}