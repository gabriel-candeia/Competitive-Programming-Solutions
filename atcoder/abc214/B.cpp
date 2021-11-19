#include<bits/stdc++.h>
using namespace std;

int main(){
    int answ = 0, s, t;

    cin >> s >> t;
    for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
            for(int k=0;k<=100;k++)
                if(i+j+k<=s && i*j*k<=t)
                    answ++;

    cout << answ << "\n";
    
    return 0;
}