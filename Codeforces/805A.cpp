#include<bits/stdc++.h>
using namespace std;

int main(){
    int l, r, answ = 1;
    cin >> l >> r;
    if(l==r){
        answ = l;
    }
    else{
        int dois = r/2 - (l-1)/2, tres = r/3-(l-1)/3;
        if(dois>=tres)
            answ = 2;
        else    
            answ = 3;
    }

    cout << answ <<"\n";


    return 0;
}
