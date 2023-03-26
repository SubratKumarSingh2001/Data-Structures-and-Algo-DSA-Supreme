class Solution {
public:

    void solve(vector<string> &ans,int index, string output, string digits,vector<string> &mapping) {
        //base case
        if(index >= digits.length()) {
            ans.push_back(output);
            return;
        }

        //1 case solve, baaki recursion
        char digitCharacter = digits[index];

        int digitInteger = digitCharacter -'0';

        string value = mapping[digitInteger];

        for(int i=0; i<value.length(); i++) {
            char ch = value[i];

            //include
            //output.push_back(ch);
            //recursive call
            solve(ans, index+1, output + ch, digits, mapping);
            //backtrack
           // output.pop_back();
        }

    }
 
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        //empty string k liye answer empty array hoga 
        if(digits.length() == 0)
            return ans;
        
        int index = 0;
        string output = "";
        vector<string> mapping(10);
        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        // unordered_map<int, string> mapping;
        // mapping[2] = "abc";
        // mapping[3] = "def";
        // mapping[4] = "ghi";
        // mapping[5] = "jkl";
        // mapping[6] = "mno";
        // mapping[7] = "pqrs";
        // mapping[8] = "tuv";
        // mapping[9] = "wxyz";

        solve(ans, index, output, digits, mapping);

        return ans;

        
    }
};