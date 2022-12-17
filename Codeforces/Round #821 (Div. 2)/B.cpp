#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, x, y;
        cin >> n >> x >> y;

        n--;

        if(max(x,y)==0 || min(x,y)!=0 || n%max(x,y)!=0){
            cout << -1 <<"\n";
        }
        else{
            if(x==0) x = y;
            int val = 1;
            for(int i=1;i<=n;i++){
                cout << val << " ";
                if(i%x == 0){
                    val = i+2;
                }
            }
            cout <<"\n";
        }
    }


    return 0;
}