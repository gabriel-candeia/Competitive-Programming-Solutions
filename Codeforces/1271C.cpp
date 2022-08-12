#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, y;
    int up=0, down=0, right=0, left=0;

    cin >> n >> x >> y;
    for(int i=0;i<n;i++){
        int a, b;
        cin >> a >> b;
        up += (a>x);
        down += (a<x);
        right += (b>y);
        left += (b<y);
    }

    int mx = max({up,down,right,left});
    int ax=x, ay=y;
    if(up==mx){
        ax = x+1;
    }
    else if(down==mx){
        ax = x-1;
    }
    else if(right==mx){
        ay = y+1;
    }
    else{
        ay = y-1;
    }

    cout <<mx << "\n"<< ax << " " << ay <<"\n";



}