#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y, sgn = 1, answ;
    

    cin >> n;

    
    cout << "? " << 1 << " " << n << endl;
    cin >> x;
    answ = x;

    if(x!=1){
        cout << "? " << 1 << " " << x << endl;
        cin >> y;
        if(y==x) sgn = -1;
    }

    for(int k=20;k>=0;k--){
        int next = answ+sgn*((1<<k));
        if(next <= n && next>=1){
            cout << "? " << min(x,next) << " " << max(x,next) << endl;
            cin >> y;
            if(y!=x){
                answ = next;
            }
        }
    }   

    cout <<"! " <<  answ+sgn << endl;

    return 0;
}