class Solution {
public:
    bool rec(vector<vector<char>> &nums, string &word, string &hold, int i, int j,
             int index) {
        if (index == word.size()) {
            return true;
        }

        if (i < 0 || j < 0 || i >= nums.size() || j >= nums[0].size() ||
            nums[i][j] == '0' || index >= word.size()) {
            return false;
        }

        if (nums[i][j] != word[index]) {
            return false;
        } else {
            hold.push_back(nums[i][j]);
            char h = nums[i][j];
            nums[i][j] = '0';
            bool res =  (rec(nums, word, hold, i, j + 1, index + 1) ||
                    rec(nums, word, hold, i, j - 1, index + 1) ||
                    rec(nums, word, hold, i + 1, j, index + 1) ||
                    rec(nums, word, hold, i - 1, j, index + 1));
            nums[i][j] = h;
            return res;
        }
    }

    bool exist(vector<vector<char>>& nums, string word) {
        string hold;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                if (rec(nums, word, hold, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};