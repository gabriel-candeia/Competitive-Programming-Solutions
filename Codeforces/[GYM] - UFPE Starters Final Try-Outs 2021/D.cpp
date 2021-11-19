#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;
    int l=1, r=n, med, answ = -1, cmp;
    while(l<=r){
        med = (l+r)/2;
        cout << l << " " << med << endl;
        cin >> cmp;
        if(cmp==1){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }

    cout << "! " << answ << endl;

    return 0;
}