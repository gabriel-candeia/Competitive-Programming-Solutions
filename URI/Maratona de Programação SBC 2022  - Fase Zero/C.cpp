#include <iostream>
#include <map>
using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const long long mod = 1e9 + 7;

int main() {
    long long ans = 0ll;
    long long n, q;
    cin >> n >> q;
    long long n_pow_k = 1;
    map<map<long long, long long>> mp;
    for (long long k = 0; k < q; ++k) {
        long long x, y;
        cin >> x >> y;
        if (x == y)
            continue;
        n_pow_k %= mod;
        long long cx = x, cy = y;
        long long _2_pow_n = (1 << n);
        long long d = n;
        if (mp.find(x) == mp.end()) {
            mp[x] = map<long long, long long>();
            for (long long i = 1; i <= n; ++i) {
                cx += cx;
                if (cx > _2_pow_n) cx -= _2_pow_n;
                if (mp[x].find(cx) == mp[x].end()) mp[x][cx] = i;
            }
        }
        for (long long i = 1; i <= n; ++i) {
            cy += cy;
            if (cy > _2_pow_n) cy -= _2_pow_n;
            if (mp[y].find(cy) == mp[y].end()) mp[y][cy] = i;
            auto it = mpX.find(cy);
            if (it != mpX.end()) {
                d = min(d, it->second + i);
            }
        }
        //cout << d << ' ' << n_pow_k << '\n';
        ans += d * n_pow_k;
        ans %= mod;
    }
    cout << ans << '\n';
    return 0;
}