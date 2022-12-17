#include <iostream>
using namespace std;

long long f(long long n) {
    return 2ll * n + (((n - 1)*n)/2ll)*3ll;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        long long c;
        cin >> c;
        long long begin = 0ll, end = 1000000000ll;
        while (begin < end) {
            long long mid = (begin + end) >> 1;
            if (f(mid) > c) end = mid;
            else begin = mid + 1;
        }
        cout << end - 1 << '\n';
    }
    return 0;
}