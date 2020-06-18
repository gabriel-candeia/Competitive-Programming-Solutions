#include<bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d, n;
    char sym='a';
    vector<int> x;
    int ptr=0, inc=1, i=0, j=0;
    char mat[200][200];

    cin >> a >> b >> c >> d;
    cin >> n;
    x.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    cout << "YES\n";
    if((min(b,d)%2==0 && b<d)||(min(b,d)%2==1 && b>d)){
        inc = -1;
        j = a+c-1;
    }
    

    for(int i=0;i<b+d;i++){
        for(int j=0;j<a+c;j++){
            mat[i][j] = '.';
        }
    }
    int l=0, r = a+c-1;
    bool flag = true;
    while(ptr<n){
        while(x[ptr]){
            x[ptr]--;
            mat[i][j] = sym;
            j+=inc;
            if(j>r || j<l){
                inc*=-1;
                j+=inc;
                i++;
            }
            if(i>=min(b,d) && flag){
                flag = false;
                if(inc==1){
                    r = a-1;
                }
                else{
                    l = a;
                }
            }
        }
        ptr++;
        sym++;
    }

    for(int i=0;i<max(b,d);i++){
        for(int j=0;j<a+c;j++){
            cout << mat[i][j];
        }
        cout << '\n';
    }

    return 0;
}