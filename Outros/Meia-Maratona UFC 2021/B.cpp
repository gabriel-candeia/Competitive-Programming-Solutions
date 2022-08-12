#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 0, b = 0, c = 0, n;
    string op, s;
    cin >> n;

    for(int i=0;i<n;i++){
        cin >> op >> s;
        if(op=="section"){
            b = 0, c= 0;
            ++a;
            cout << a << " " << s <<"\n";
        }
        else if(op=="subsection"){
            c = 0;
            ++b;
            cout << a << "." << b << " " << s <<"\n";
        }
        else{
            ++c;
            cout << a << "." << b << "." << c << " " << s <<"\n";
        }
    }


    return 0;
}