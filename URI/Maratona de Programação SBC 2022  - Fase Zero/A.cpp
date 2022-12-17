#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    string lixo;
    getline(cin, lixo);
    while (n--) {
        string name;
        getline(cin, name);
        string notas;
        
        getline(cin, notas);
        //vector<pair<int,int>> __notas;
        vector<double> __notas;
        for (int i = 0; notas[i]; ++i) {
            if ('0' <= notas[i] && notas[i] <= '9') {
                //__notas.push_back(make_pair(notas[i] - '0', notas[i+2] - '0'));
                //cout << i << __notas.back().first << '.' << __notas.back().second << ' ';
                __notas.push_back(notas[i] - '0' + ((notas[i+2] - '0') / 10.0));
                //cout << i << ' ' << __notas.back() << ' ';
                i += 3;
            }
        }
        for (int i = 0; notas[i]; ++i) notas[i] = 0;
        sort(__notas.begin(), __notas.end());
        cout << name << ": ";
        //pair<int, int> nota_final;
        double nota_final;
        if (__notas.size() == 1) {
            //nota_final = make_pair(__notas[0].first/2, __notas[0].second/2 + (__notas[0].first * 5) % 10);
            nota_final = __notas[0] / 2;
        }
        else if (__notas.size() == 2) {
            /*
            nota_final = make_pair(__notas[0].first + __notas[1].first,
                        __notas[0].second + __notas[1].second);
            nota_final.first += nota_final.second / 10;
            nota_final.second %= 10;
            nota_final.second /= 2;
            nota_final.second += (nota_final.first * 5) % 10;
            nota_final.first /= 2;
            */
            nota_final = __notas[0] + __notas[1];
            nota_final /= 2;
        }
        else if (__notas.size() == 3) {
            /*
            nota_final = make_pair(__notas[0].first + __notas[1].first + __notas[2].first,
                        __notas[0].second + __notas[1].second + __notas[2].second);
            nota_final.first += nota_final.second / 10;
            nota_final.second %= 10;
            nota_final.second /= 3;
            nota_final.second += ((nota_final.first * 10) / 3) % 10;
            nota_final.first /= 3;
            */

            nota_final = __notas[0] + __notas[1] + __notas[2];
            nota_final /= 3;
        }
        else {
            /*
            nota_final = make_pair(__notas[3].first + __notas[1].first + __notas[2].first,
                        __notas[3].second + __notas[1].second + __notas[2].second);
            nota_final.first += nota_final.second / 10;
            nota_final.second %= 10;
            nota_final.second /= 3;
            nota_final.second += ((nota_final.first * 10) / 3) % 10;
            nota_final.first /= 3;
            */

            nota_final = __notas[3] + __notas[1] + __notas[2];
            nota_final /= 3;
        }
        cout.precision(1);
        cout << fixed << nota_final << '\n';
        //cout << nota_final.first << '.' << nota_final.second << '\n';
    }
    return 0; 
}