#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;

    cin >> t;
    while(t--){
        int min, max, i;
        char answ;
        cin >> n;

        if(n%2==1){
            min = max = 1;
            i = 2;
        }
        else{
            cout << "? " << 1 << " " << 2 << endl;
            cin >> answ;
            if(answ=='<'){
                min = 1;
                max = 2;
            }
            else{
                max = 1;
                min = 2;
            }
            i = 3;
        }
        int tmin, tmax;
        for(;i<n;i+=2){
            tmin = i;
            tmax = i+1;
            cout << "? " << i << " " << i+1 << endl;
            cin >> answ;
            if(answ=='>'){
                tmin = i+1;
                tmax = i;
            }
            cout << "? " << min << " " << tmin << endl;
            cin >> answ;
            if(answ=='>'){
                min = tmin;
            }
            cout << "? " << tmax << " " << max << endl;
            cin >> answ;
            if(answ=='>'){
                max = tmax;
            }
        }
        cout << "! " << min << " " << max << endl;
    }

    return 0;
}