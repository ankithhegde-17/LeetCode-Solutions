#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> map;
        for (const std::string& s : strs) {
            std::string t = s;
            std::sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        std::vector<std::vector<std::string>> result;
        for (auto& pair : map) {
            result.push_back(pair.second);
        }
        return result;
    }
};