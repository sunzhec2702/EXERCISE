'''
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

Subscribe to see which companies asked this question.
'''

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        exist_dict = {}
        max_len = 0
        last_index = 0
        for i in range(len(s)):
            if (s[i] in exist_dict.keys() and exist_dict[s[i]] >= last_index):
                if ((i - last_index) > max_len):
                    max_len = i - last_index
                last_index = exist_dict[s[i]] + 1
                exist_dict[s[i]] = i
            else:
                exist_dict[s[i]] = i
        if ((len(s) - last_index) > max_len):
            max_len = len(s) - last_index
        return max_len

strings = "pwwkew"
solution = Solution()
print(solution.lengthOfLongestSubstring(strings))