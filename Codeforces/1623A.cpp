#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, m, cx, cy, lx, ly, dx=1, dy=1, answ=0;

        cin >> n >> m >> cx >> cy >> lx >> ly;
        int iter = 500;
        while(true){
            if(cx==lx || cy==ly){
                break;
            }   
            answ++;
            if(cx+dx>n || cx+dx<1) dx = -dx;
            if(cy+dy>m || cy+dy<1) dy = -dy;
            cx += dx;
            cy += dy;
        }

        cout << answ <<"\n";
    }

    return 0;
}