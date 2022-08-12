#include<bits/stdc++.h>
#define ll long long
using namespace std;

const double PI = 3.14159265358979323846;

int main(){
    int n;

    cin >> n;
    vector<array<ll,3>> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i][1] >> arr[i][2] >> arr[i][0];
    }

    sort(arr.rbegin(),arr.rend());

    vector<int> parent(n,-1), sinal(n,0);

    ll answ = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            ll d = (arr[j][1]-arr[i][1])*(arr[j][1]-arr[i][1])+(arr[j][2]-arr[i][2])*(arr[j][2]-arr[i][2]);
            if(d<arr[j][0]*arr[j][0]){
                parent[i] = j;
            }
        }
        if(parent[i]==-1 || parent[parent[i]]==-1){
            sinal[i] = 1;
        }
        else{
            sinal[i] = ((sinal[parent[i]] == 1) ? -1 : 1);
        }
        answ += sinal[i]*arr[i][0]*arr[i][0];
    }

    cout << fixed << setprecision(10) <<  answ*PI <<"\n";

    return 0;
}