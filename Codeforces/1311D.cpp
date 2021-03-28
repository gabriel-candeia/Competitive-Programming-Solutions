#include<bits/stdc++.h>
#define maxn int(1e5)
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, answ = 1e8, a1, b1, c1;
        
        cin >> a >> b >> c;
        for(int i=1;i<=maxn;i++){
            for(int j=i;j<=maxn;j+=i){
                int temp =  abs(a-i)+abs(b-j) + min(c%j,j-c%j);
                if(temp<answ){
                    answ = temp;
                    a1 = i; 
                    b1 = j;
                    c1 = (c%j<j-c%j) ? c-c%j : c+j-c%j;
                }
            }
        }
        cout << answ << '\n';
        cout << a1 << " " << b1 << " " << c1 << "\n";
    }
    return 0;
}