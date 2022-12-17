#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<pair<int, int>, int> p3i;
const int INF = 0x3f3f3f3f;

int to_int(string& s) {
    int min, seg, ms;
    min = seg = ms = 0;
    int start = 0, end = -1;
    for (int i = end + 1; 1; ++i) {
        if (s[i] < '0' || s[i] > '9') {
            end = i;
            break;
        }
    }
    for (int i = end - 1, j = 1; i >= start; --i, j*=10) {
        min += (s[i] - '0') * j;
    }
    start = end + 1;
    for (int i = end + 1; 1; ++i) {
        if (s[i] < '0' || s[i] > '9') {
            end = i;
            break;
        }
    }
    for (int i = end - 1, j = 1; i >= start; --i, j*=10) {
        seg += (s[i] - '0') * j;
    }
    start = end + 1;
    for (int i = end + 1; 1; ++i) {
        if (s[i] < '0' || s[i] > '9') {
            end = i;
            break;
        }
    }
    for (int i = end - 1, j = 1; i >= start; --i, j*=10) {
        ms += (s[i] - '0') * j;
    }
    //cout << min << ':' << seg << ':' << ms << ' ';
    seg += (min * 60);
    ms += (seg) * 1000;
    return ms;
}

int main() {
    int n, v;
    cin >> n >> v;
    vector<int> num_comp(n);
    vector<pair<int, int>> tempo(n);
    vector<p3i> min_tempo(n, {{INF, 0}, 0});
    for (int i = 0; i < n; ++i) {
        cin >> num_comp[i];
        string s;
        int tempo_total = 0;
        for (int j = 0; j < v; ++j) {
            cin >> s;
            int t = to_int(s);
            tempo_total += t;
        //    cout << t << ' ';
            if (t < min_tempo[i].first.first) {
                min_tempo[i] = {{t, tempo_total}, i};
            }
        }
      //  cout << '\n';
        tempo[i] = {tempo_total, i};
    }
    sort(min_tempo.begin(), min_tempo.end());
    sort(tempo.begin(), tempo.end());
    bool ganhou = false;
    for (int i = 0; i < n; ++i) {
        if (tempo[i].second == min_tempo[0].second && i < 10)
            ganhou = true;
    }
    if (ganhou)
        cout << num_comp[min_tempo[0].second] << '\n';
    else
        cout << "NENHUM\n";
    return 0;
}