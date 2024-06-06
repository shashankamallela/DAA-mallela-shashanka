cpp
#include <unordered_map>
#include <list>
#include <vector>
#include <algorithm>
class FirstUnique {
public:
    FirstUnique(std::vector<int>& nums) {
        for (int num : nums) {
            cnt[num]++;
            if (cnt[num] == 1) {
                unique.push_back(num);
            } else if (cnt[num] == 2) {
                unique.remove(num);
            }
        }
    }

    int showFirstUnique() {
        if (unique.empty()) {
            return -1;
        } else {
            return unique.front();
        }
    }
    void add(int value) {
        cnt[value]++;
        if (cnt[value] == 1) {
            unique.push_back(value);
        } else if (cnt[value] == 2) {
            unique.remove(value);
        }
    }

private:
    std::unordered_map<int, int> cnt;
    std::list<int> unique;
};
