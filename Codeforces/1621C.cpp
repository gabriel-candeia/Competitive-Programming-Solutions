#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> visited(n+1,0), answ(n+1,0);

        for(int i=1;i<=n;i++){
            int last, curr;            
            cout << "? " << i << endl;
            cin >> last;
            if(visited[last]) continue;
            visited[last] = 1;
            while(true){
                cout << "? " << i << endl;
                cin >> curr;
                answ[last] = curr;
                if(visited[curr]) break;
                visited[curr] = 1;
                last = curr;
            }
        }

        cout << "! ";
        for(int i=1;i<=n;i++){
            cout << answ[i] << " ";
        }cout<< endl;

    }

    return 0;
}