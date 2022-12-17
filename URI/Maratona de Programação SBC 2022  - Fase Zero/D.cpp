#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int dp(string& s1, string& s2, int i, int j, vector<vector<int>>& memo) {
    if (i == s1.size() || j == s2.size()) return 0;

    int& pmd = memo[i][j];
    if (pmd != -1) return pmd;
    
    if (s1[i] == s2[j]) {
        pmd = dp(s1, s2, i + 1, j + 1, memo) + 1;
    }

    return pmd = max({pmd, dp(s1, s2, i + 1, j, memo), dp(s1, s2, i, j + 1, memo)});
}

int main() {
    int n;
    cin >> n;
    vector<double> notas(6);
    vector<int> clcs(6);
    while (n--) {
        string s;
        cin >> s;
        int _min = 30;
        for (int i = 1; i <= 5; ++i) {
            string s1;
            cin >> s1;
            vector<vector<int>> memo(s.size(), vector<int>(s1.size(), -1));
            int lcs = dp(s, s1, 0, 0, memo);
            if (s1.size() == s.size())
                clcs[i] = s.size() - lcs;
            else if (s1.size() < s.size())
                clcs[i] = s.size() - lcs;
            else 
                clcs[i] = s1.size() - lcs;
            _min = min(_min, clcs[i]);
        }
        if (_min == 0) {
            for (int i = 1; i <= 5; ++i)
                if (_min == clcs[i])
                    notas[i] += 1.0;
        }
        else {
            for (int i = 1; i <= 5; ++i)
                if (_min == clcs[i])
                    notas[i] += 0.5;
        }

        for (int i = 1; i < 6; ++i)
            cout << clcs[i] << ' ' << notas[i] << " | ";
        cout << '\n';
    }
    double maior = *max_element(notas.begin(), notas.end());
    cout.precision(1);
    cout << fixed << maior << '\n';
    vector<int> vencedores;
    for (int i = 1; i < 6; ++i)
        if (notas[i] == maior)
            vencedores.push_back(i);
    for (int i = 0; i < vencedores.size(); ++i) {
        cout << vencedores[i] << (i + 1 == vencedores.size() ? '\n' : ' ' );
    }
    return 0;
}