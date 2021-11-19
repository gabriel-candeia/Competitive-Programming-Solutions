#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;

int main(){
    fastio();
    int q;
    priority_queue<int> a;
    queue<int> b;

    cin >> q;
    while(q--){
        int c;
        cin >> c;
        if(c==1){
            int x;
            cin >> x;
            b.push(x);
        }
        else if(c==2){
            if(a.size()){
                cout << -a.top() <<"\n";
                a.pop();
            }
            else if(b.size()){
                cout << b.front() << "\n";
                b.pop();
            }
        }
        else{
            while(b.size()){
                a.push(-b.front());
                b.pop();
            }           
        }
    }

    return 0;
}