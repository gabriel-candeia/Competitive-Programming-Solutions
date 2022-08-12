#include<bits/stdc++.h>
#define ld long double 
using namespace std;
    
int main(){
    ld d, v0, v1, v2, t;
    cin >> d >> v0 >> v1 >> v2 >> t;
    
    ld tempo = t, answ=0, x=0, y=1, dd = d, total = 0;
    
    for(int iter=0;;iter++){
        if(y-x<1e-7 && dd-x<1e-7){
            answ = dd; break;}
        //cout <<fixed << setprecision(10) << x<< " " << y << " "<< dd << "\n";
        ld full;
        if(iter%2==1) full = (y-x)*1.0/(v2+v0);
        else{ 
            full = (y-x)*1.0/(v2-v1);
            ld aux = (d-y)*1.0/v1;
            if(aux<=full){
                full = (d-x)*1.0/v2;
            }
        }
        
        if(full>=tempo){
            if(iter%2==0) answ = x+tempo*v2;
            else answ = y-tempo*v2;
            answ = min(answ,dd);
            break;
        }
        else{
            total += full;
            tempo -= full;
            y = 1+v1*total;
            y = min(y,dd);
            x = v0*total;
            x = min(x,dd);
        }
    }
    
    cout << fixed << setprecision(16) << answ <<"\n";
    
    return 0;
}