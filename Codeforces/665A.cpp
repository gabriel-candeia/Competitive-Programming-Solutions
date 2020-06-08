#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, ta, b, tb;
    int h,m, start, lim = 23*(60)+59 - 5*60, end;

    cin >> a >> ta;
    cin >> b >> tb;

    scanf("%d:%d",&h,&m);

    start = h*60+m - 5*60;
    end = min(start+(ta-1),lim);
    start = max(start-(tb-1),0);
    
    cout << end/b-start/b + (start%b==0) << '\n';
    //cout << start << " " << end << '\n';
    return 0;
}