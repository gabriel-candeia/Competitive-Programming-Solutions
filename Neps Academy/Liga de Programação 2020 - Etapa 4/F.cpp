int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    int n, q;
    std::cin >> n >> q;
    std::map<int, int> freq;
    freq[1] = n;
    ColorUpdate<> col;
    col.upd(0, n, 1);
    std::priority_queue<std::pair<int, int>> hp;
    hp.push({n, 1});
    while(q--) {
        int t;
        std::cin >> t;
        if(t == 1) {
            int l, r, x;
            std::cin >> l >> r >> x;
            l--;
            freq[x] += r - l;
            for(auto range : col.upd(l, r, x)) {
                freq[range.v] -= range.r - range.l;
            }
            hp.push({freq[x], x});
        } else if(t == 2) {
            int x;
            std::cin >> x;
            std::cout << freq[x] << '\n';
        } else {
            while(freq[hp.top().second] != hp.top().first) {
                int x = hp.top().second;
                hp.pop();
                hp.push({freq[x], x});
            }
            std::cout << hp.top().first << '\n';
        }
    }
}