#include <vector>
#include <string>
#include <string_view>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;
        if (s.empty() || words.empty()) return result;

        int word_len = words[0].length();
        int num_words = words.size();
        int total_len = word_len * num_words;
        
        if (s.length() < total_len) return result;

        // Count the frequency of each word in the input array
        std::unordered_map<std::string_view, int> word_count;
        for (const std::string& word : words) {
            word_count[word]++;
        }

        std::string_view sv(s);

        // Slide the window across different starting offsets
        for (int i = 0; i < word_len; ++i) {
            int left = i, right = i;
            std::unordered_map<std::string_view, int> seen_words;
            int count = 0;

            while (right + word_len <= sv.length()) {
                std::string_view sub = sv.substr(right, word_len);
                right += word_len;

                auto it = word_count.find(sub);
                if (it != word_count.end()) {
                    seen_words[sub]++;
                    count++;

                    // If the word count exceeds the allowed limit, shrink the window from the left
                    while (seen_words[sub] > word_count[sub]) {
                        std::string_view left_sub = sv.substr(left, word_len);
                        seen_words[left_sub]--;
                        left += word_len;
                        count--;
                    }

                    // If all words matched, record the starting index
                    if (count == num_words) {
                        result.push_back(left);
                        std::string_view left_sub = sv.substr(left, word_len);
                        seen_words[left_sub]--;
                        left += word_len;
                        count--;
                    }
                } else {
                    // Reset the window if an invalid word is encountered
                    seen_words.clear();
                    count = 0;
                    left = right;
                }
            }
        }

        return result;
    }
};