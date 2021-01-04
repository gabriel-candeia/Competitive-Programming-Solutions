#include <bits/stdc++.h>
#define ld double
using namespace std; 

int cmp(ld a, ld b){
    const ld eps = 1e-7;
    return (b-a>eps) ? -1 : (b-a<-eps) ? 1 : 0;
}

int main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    vector<ld> arr(4);
    ld e;

    for(int i=0;i<4;i++)
        cin >> arr[i];
    cin >> e;
    sort(arr.begin(),arr.end());
    const ld tres = 3.0;
    ld resposta = tres*e-arr[1]-arr[2];
    if(cmp((arr[1]+arr[2]+arr[3]),tres*e)<=0)
        cout << "infinite" << endl;
    else if(cmp(arr[1]+arr[2],tres*e)==0 || cmp(resposta,arr[0])<0)
        cout << "impossible" << endl;
    else
        cout << fixed << setprecision(2) << resposta << "\n";
    return 0;
}
