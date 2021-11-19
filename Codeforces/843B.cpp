#include<bits/stdc++.h>
using namespace std;

int main(){
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n, start, x, answ = -1, ptr = start, v = -1;
    vector<int> visited;
    
    cin >> n >> start >> x;
    ptr = start;
    visited.assign(n+1,0);

    int a, b;
    cout << "?" << " " << start << endl;
    visited[start] = 1;
    cin >> a >> b;
    if(a<x && a>v) ptr = b, v = a;
    if(a>=x) answ = a;

    for(int i=0;i<min(999,n-1);i++){ 
        int k = (rng()%n+1);
        while(visited[k]) k = (rng()%n+1);
        visited[k] = 1;
        cout << "?" << " " << k << endl;
        cin >> a >> b;
        if(a<x && a>v) ptr = b, v = a;
    }

    for(int i=0;i<999;i++){
        if(ptr==-1)
            break;
        cout << "?" << " " << ptr << endl;
        cin >> a >> b;
        if(a>=x){ answ = a; break;}
        else ptr = b;
    }

    cout <<"! " <<  answ << endl;

    return 0;
}