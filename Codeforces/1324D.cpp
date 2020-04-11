#include<bits/stdc++.h>
#define N int(2e5)+3
using namespace std;

int main(){
    int n, a[N], b;
    long long int answ=0, cntPos=0, cntZero=0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<n;i++){
        cin >> b;
        a[i]-=b;
        cntPos+=(a[i]>0);
        cntZero+=(a[i]==0);
    }

    sort(a,a+n);
    int i=0,j=n-1;
    bool flag = true;
    while(i<=j && a[i]<0){
        if(a[i]+a[j]>0){
            j--;
            flag = false;
        }
        else{
            answ+=n-1-j;
            i++;
            flag = true;
        }
    }
    answ += (flag==false)*(n-1-j);
    answ += cntZero*cntPos + (cntPos*(cntPos-1))/2;
    cout << answ <<'\n';
    return 0;
}