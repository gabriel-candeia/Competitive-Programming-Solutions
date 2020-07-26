#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    vector<int> A(n,0), mxL(n,0), mxR(n,0);

    for(int i=0;i<n;i++){
        cin >> A[i];
    }
    mxL[0] = A[0];
    mxR[n-1] = A[n-1];
    for(int i=1;i<n;i++){
        mxL[i] = max(mxL[i-1],A[i]);
        mxR[n-i-1] = max(mxR[n-i],A[n-i-1]);
    }

    int cnt=0;
    for(int i=0;i<n;i++){
        cnt += (mxL[i]>A[i] && mxR[i]>A[i]);
    }

    cout << cnt << '\n';

    return 0;
}