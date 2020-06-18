#include<bits/stdc++.h>
using namespace std;

int win(int y,int x){
    if(((x-1)%5+5)%5==y || ((x-2)%5+5)%5==y){
        return 1;
    }
    return 0;
}

int main(){
    int n, d, x;
    int dario=0, xerxes=0;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> d >> x;
        if(win(d,x)){
            dario++;
        }
        else{
            xerxes++;
        }   
    }
    if(xerxes>dario){
        cout << "xerxes\n";
    }
    else{
        cout << "dario\n";
    }

    return 0;
}