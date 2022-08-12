#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;

        cin >> n;

        int best1 = -1, pos1 = -1;
        for(int i=3;i<=n;i++){
            int x;
            cout << "? " << 1 << " " << 2 << " " << i << endl;
            cin >> x;
            if(best1==-1 || x>best1){
                best1 = x, pos1 = i;
            }
        }


        vector<int> teste;
        int best2 = -1, pos2 = -1;
        for(int i=1;i<=n;i++){
            if(i==1 || i==pos1) continue;
            int x;
            cout << "? " << 1 << " " << pos1 << " " << i << endl;
            cin >> x;
            teste.push_back(x);
            if(best2==-1 || x>best2){
                best2= x, pos2 = i;
            }
        }
        bool ok = true;
        for(auto x:teste){
            ok = ok && (x==teste.back());
        }

        if(ok){
            cout << "! " << 1 << " " << pos1 << endl;
            continue;
        }

        //cout << "teste: " << pos2 <<"\n";
        int a = 1;
        while(a==1 || a==pos1 || a==pos2) a++;
        int cmp1, cmp2;
        cout << "? " << pos2 << " " << pos1 << " " << 1 <<endl;
        cin >> cmp1;
        
        cout << "? " << pos2 << " " << a << " " << 1 <<endl;
        cin >> cmp2;
        

        if(cmp1==cmp2){
            cout << "! " << 1 << " " << pos2 << endl;
        }
        else{
            cout << "! " << pos1 << " " << pos2 << endl;
        }
    }   

    return 0;
}