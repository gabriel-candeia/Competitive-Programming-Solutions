#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> meses = {0,31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dia, mes, ano, n;
    char lixo;

    cin >> n;

    string dd, mm, aa, comp, best;
    for(int i=0;i<n;i++){
        cin >> dia >> lixo >> mes >> lixo >> ano >> lixo;
        best = string(4-to_string(ano).size(),'0') + to_string(ano) + string(2-to_string(mes).size(),'0') + to_string(mes) + string(2-to_string(dia).size(),'0') + to_string(dia);
        comp = "";
        string answ;
        //cout << best <<"\n";
        for(int m=1;m<=12;m++){
            for(int d=1;d<=meses[m];d++){
                dd = ((d<10) ? "0": "") + to_string(d);
                mm = ((m<10) ? "0": "") + to_string(m);
                aa = dd+mm;
                reverse(aa.begin(),aa.end());
                //cout << aa << " " << mm << " " << dd <<"\n";
                int a = stoi(aa);
                if(m==2 && d==29 && a%4!=0)
                    continue;
                if(aa+mm+dd > best && (aa+mm+dd<comp || comp=="")){
                    comp = aa+mm+dd;
                    answ = dd+"."+mm+"."+aa+".";
                }
            }   
        }
        cout << answ <<"\n";
    }


    return 0;
}