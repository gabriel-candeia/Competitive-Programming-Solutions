#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, tam=0, k, start, walk, curr;
    vector<string> arr;

    cin >> n;
    arr.assign(n,"");
    for(int i=0;i<n;i++){
        cin >> arr[i];
        tam+=arr[i].size();
    }

    cin >> k;
    start = k/tam;
    walk = k%tam;

    for(curr=start;walk>arr[curr].size();curr=(curr+1)%n){
        walk-=arr[curr].size();
    }

    cout << arr[curr][walk-1] <<'\n';

    return 0;
}
