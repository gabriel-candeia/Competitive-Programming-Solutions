#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    int x, y, maiorx=0, maiory=0, temp;
    char op;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    while(n--){
        cin >> op >> x >> y;
        if(x>y){
            temp = x;
            x = y;
            y = temp;
        }
        if(op=='+'){
            maiorx = max(maiorx,x);
            maiory = max(maiory,y);
        }
        else{
            if(maiory<=y && maiorx<=x){
                cout << "YES\n";
            }
            else{
                cout << "NO\n";
            }
        }
    }


    return 0;
}