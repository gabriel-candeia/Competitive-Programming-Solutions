#include <bits/stdc++.h>

using namespace std;

int main(){
    int v[100005];
    int h, w;
    cin >> h >> w;
    for(int  i = 0; i < h; i++){
        cin >> v[i];
    }
    int ans = 0, num;
    for(int i = 0; i < h; i++){
        cin >> num;
        ans = max(ans, num+v[i]);
    }
    double answ = (w-ans*1.0)/2.0;
    cout << answ << "\n"; 
    return 0;
}