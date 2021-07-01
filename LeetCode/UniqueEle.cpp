// https://leetcode.com/problems/sum-of-unique-elements/

int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> mp;
    for (auto it : nums) {
        mp[it]++;
    }
    int sum{0};
    for (auto &it : mp) {
        if (it.second == 1)
            sum += it.first;
    }
    return sum;
}

int sumOfUnique(vector<int>& nums) {
    unordered_map<int, int> m;
    for (auto n : nums)
        ++m[n];
    return accumulate(begin(m), end(m), 0, [](int sum, const auto & p) {
        return sum + (p.second == 1 ? p.first : 0);
    });
}

int sumOfUnique(vector<int>& nums) {
    int cnt[101] = {}, res = 0;
    for (auto n : nums)
        res += ++cnt[n] == 1 ? n : cnt[n] == 2 ? - n : 0;
    return res;
}


int sumOfUnique(vector<int>& nums) {
    unordered_map<int, bool> m;
    int res = 0;
    for (auto n : nums) {
        auto it = m.find(n);
        if (it != end(m)) {
            res -= it->second ? 0 : n;
            it->second = true;
        }
        else {
            m.insert({n, false});
            res += n;
        }
    }
    return res;
}