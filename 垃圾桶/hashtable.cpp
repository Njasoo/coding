struct HastTable {
    vector<vector<pair<int, long long>>> table; // pair<key, value>
    int max_size;

    HastTable() {
        max_size = 1e6;
        table.assign(max_size, vector<pair<int, long long>>());
    }
    pair<bool, long long> find_and_return_value(int key) {
        int key_after_mod = (key % max_size + max_size) % max_size; // 防止负数
        for (int i = 0; i < int(table[key_after_mod].size()); i++) { // 不强转int跑不动
            if (table[key_after_mod][i].first == key) {
                return {true, table[key_after_mod][i].second};
            }
        }
        return {false, 0};
    }
    void insert(int key, int value) {
        if (this->find_and_return_value(key).first) return;
        int key_after_mod = (key % max_size + max_size) % max_size;
        table[key_after_mod].push_back({key, value});
    }
};