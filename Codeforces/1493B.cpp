#include<bits/stdc++.h>
using namespace std;
int h, m;

string convert(int x){
    int t1 = (x/m)%h, t2 = x%m;
    int a = t1/10, b = t1%10, c = t2/10, d = t2%10;
    return to_string(a)+to_string(b)+":"+to_string(c)+to_string(d);
}

int f(int x){
    if(x==1 || x==0 || x==8)
        return x;
    if(x==2)
        return 5;
    if(x==5)
        return 2;
    return -1;
}

bool isok(int x){
    int t1 = (x/m)%h, t2 = x%m;
    int a = f(t1/10), b = f(t1%10), c = f(t2/10), d = f(t2%10);
    bool answ = false;
    if(a>=0 && b>=0 && c>=0 && d>=0 && d*10+c<h && b*10+a<m)
        return true;
    return false;
}


int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> h >> m;
        int x, y, total, answ=0;
        char op;

        cin >> x >> op >> y;
        
        total = x*m+y;

        for(int i=0;i<h*m;i++){
            if(isok(total+i)){
                answ = total+i;
                break;
            }
        }

        cout << convert(answ) << '\n';
    }

}