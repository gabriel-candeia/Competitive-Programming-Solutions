#include<bits/stdc++.h>
#define N int(1e5) + 3
using namespace std;

int main(){
    int t, n;
    string a, b;
    bool flag;
    char aux;

    cin >> t;
    while(t--){
        cin >> n;
        flag = false;
        a = ""; b = "";
        for(int i=0;i<n;i++){
            cin >> aux;
            if(aux=='2'){
                if(!flag){
                    a += '1';
                    b += '1';
                }
                else{
                    a += '0';
                    b += '2';
                }
            }
            else if(aux=='0'){
                a += '0';
                b += '0';
            }
            else if(!flag){
                a += '1';
                b += '0';
                flag = true;
            }
            else{
                a += '0';
                b += '1';
            }
        }
        cout << a << '\n';
        cout << b << '\n';
    }

    return 0;
}