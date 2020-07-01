#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, temp, q, x, y, op;
    vector<int> funcionarios;

    cin >> n;
    funcionarios.assign(n+1,0);
    for(int i=1;i<=n;i++){
        funcionarios[i] = i;
    }

    cin >> q;
    while(q--){
        cin >> op >> x;
        if(op==1){
            cin >> y;
            temp = funcionarios[x];
            funcionarios[x] = funcionarios[y];
            funcionarios[y] = temp;
        }
        else{
            int cnt=0, atual = x;
            while(funcionarios[atual]!=x){
                atual = funcionarios[atual];
                cnt++;
            }
            cout << cnt <<'\n';
        }
    }

    return 0;
}