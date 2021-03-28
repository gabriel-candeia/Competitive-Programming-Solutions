#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool mat[100][100];

int main(){
    int n;

    cin >> n;
    for(int x=0;x<=min(8,n);x++)
        for(int y=0;x+y<=min(50,n);y++)
            for(int a=0;a<=min(8,n);a++)
                for(int b=0;a+b<=min(50,n);b++)
                    if((4*a+9*b-4*x-9*y)<=0 && (abs(4*a+9*b-4*x-9*y))%49==0 && x!=a && y!=b)
                        mat[x][y] = 1;
    
    ll answ = 0;
    for(int x=0;x<=min(8,n);x++)
        for(int y=0;x+y<=min(50,n);y++)
            if(mat[x][y]==0)
                answ += max((n+1-x-y),0);
    cout << answ << '\n';
    return 0;
}