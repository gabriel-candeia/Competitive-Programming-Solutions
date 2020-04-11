#include<bits/stdc++.h>
#define N int(2e5)+3
using namespace std;

long long int max(long long int a, long long int b){
    return (a<b) ? b : a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long int n, arr[N], sum=0;
    long long int good=0, i=0, j=0, ni;
    map<long long int,int> last;

    cin >> n;
    for(i=0;i<n;i++){
        cin >> arr[i];
    }

    i=-1;
    last[0] = -1;
    for(int j=0;j<n;j++){
        sum+=arr[j];
        if(arr[j]==0){
            i = j;
        }
        else{
            if(last.count(sum)){
                i = max(i,last[sum]+1);
            }
            good += j-i;
        }
        last[sum] = j;
    }

    cout << good << '\n';

    return 0;
}
