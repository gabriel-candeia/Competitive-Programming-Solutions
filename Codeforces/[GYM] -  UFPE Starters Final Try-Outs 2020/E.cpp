#include<bits/stdc++.h>
#define maxn int(2e6+5)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int perfect(int x){
    int acm=0, root=sqrt(x);
    for(int i=1;i<=root;i++){
        if(x%i==0){
            acm+=i+x/i;
        }
    }
    return(2*x==acm);
}

int main(){
    fastio();
    int p[] = {-1,6,28,496,8128,maxn};
    
    int n, x;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x;
        for(int j=0;j<5;j++){
            if(p[j+1]>x){
                cout << p[j] << '\n';
                break;
            }
        }
    }

    return 0;
}