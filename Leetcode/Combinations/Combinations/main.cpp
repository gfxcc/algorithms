#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    
    bool isSign(char str) {
        if (str == '+' || str == '-' || str == '*') {
            return true;
        }
        return false;
    }
    
    void calculate(string input, vector<int> &result, int head) {

        bool single = true;
        for (int i = 1; i != input.length(); i++) {
            if (isSign(input[i])) {
                single = false;
                break;
            }
        }
        if (single) {
            result.push_back(atoi(input.c_str()));
            return;
        }
        
        int first = 0, second = 0;
        int begin = 0;
        for (int i = head == 0 ? 1 : head; i < input.length(); i++) {
            if (isSign(input[i]) && !isSign(input[i - 1])) {
                string str;
                int m = 0;
                for (m = i; m > 1; m--) {
                    if (isSign(input[m - 1]) && !isSign(input[m -2])) {
                        break;
                    }
                }
                str = input.substr(m > 1 ? m : 0, m > 1 ? (i - m) : i);

                first = atoi(str.c_str());
                int index = 0;
                for (int j = i + 1; j < input.length(); j++) {
                    if ((isSign(input[j]) && !isSign(input[j -1])) || j == (input.length() - 1)) {
                        string str = input.substr(i + 1, j - i);
                        second = atoi(str.c_str());
                        index = j;
                        break;
                    }
                }
                int res = 0;
                if (input[i] == '+') {
                    res = first + second;
                } else if (input[i] == '-') {
                    res = first - second;
                } else if (input[i] == '*') {
                    res = first * second;
                }
                string newInput;

                newInput = input.substr(0, m > 1 ? m : 0) + std::to_string(res) + input.substr(index, index == input.length() - 1 ? 0 : input.length() - index);
                
                calculate(newInput, result, begin);
                begin = i;
            }
        }
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        calculate(input, result, 0);
        return result;
    }
};

int main() {

    Solution a;
    vector<int> result;
    string t = "2*3-4*5";
    result = a.diffWaysToCompute(t);
    return 0;
}