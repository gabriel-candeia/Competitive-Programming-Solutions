#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int isok(int msk){
    for(int i=0;i<n;i++)
        if(((msk&(1<<i))!=0 && (msk&arr[i])!=0) || ((msk&(1<<i))==0 && (msk&arr[i])==0))
            return 0;
    return 1;
}

int main(){

    cin >> n;
    arr.assign(n,0);

    for(int i=0, x, y;i<n;i++){
        cin >> x;
        for(int j=0;j<x;j++){
            cin >> y;
            arr[i] |= (1<<(y-1));
        }
    }

    int answ = 0;
    for(int msk=0;msk<(1<<n);msk++){
        answ += isok(msk);
    }
    cout << answ <<'\n';
    return 0;
}