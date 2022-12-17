#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int o;
        string tempo;
        cin >> o >> tempo;
        if (tempo == "1T") {
            if (o > 45)
                cout << "45+" << o-45 << '\n';
            else
                cout << o << '\n';
        }
        else {
            if (o > 45)
                cout << "90+" << o-45 << '\n';
            else
                cout << 45+o << '\n';
        }
    }
    return 0;
}