/**
 * KATA:
 * - https://www.codewars.com/kata/52f787eb172a8b4ae1000a34
 * - https://www.codewars.com/kata/5324945e2ece5e1f32000370
 */

#include <iostream>

#include <cmath>
// note: https://mathworld.wolfram.com/Factorial.html
long zeros(long n) {
    long Z = 0;
    long k_max = (long)(std::log(n) / std::log(5));
    for (long k = 1; k <= k_max; k++) {
        Z += (long)(n / std::pow(5, k));
    }
    return Z;
}

std::string sum_strings(const std::string& a, const std::string& b) {
    const long N = (long)std::max(a.size(), b.size());
    const size_t a_len = a.size();
    const size_t b_len = b.size();
    std::string result(N, '0');
    int carry = 0,a_digit,b_digit;
    for (long i = 0; i < N ; ++i) {
        if(i < a_len) {
            a_digit = a[a_len - i - 1] - '0';
        } else {
            a_digit = 0;
        }
        if(i < b_len) {
            b_digit = b[b_len - i - 1] - '0';
        } else {
            b_digit = 0;
        }
        int sum = a_digit + b_digit + carry;
        carry = sum / 10;
        result[N-1-i] = (char)((sum % 10) + '0');
    }
    if(carry > 0) {
        result.insert(result.begin(), (char)(carry + '0'));
    }
    return result;
}


#include <vector>
int maxSequence(const std::vector<int>& arr){
    int max_sum = 0;
    int sum = 0;
    for (int i : arr) {
        sum += i;
        if(sum < 0) {
            sum = 0;
        }
        if(sum > max_sum) {
            max_sum = sum;
        }
    }
    return max_sum;
}


#include <string>
#include <vector>

void foo(std::vector<std::string>& res, const std::string& s, std::string prefix){
    if(s.empty()){
        for (const auto& item:res) {
            if(item == prefix){
                return ;
            }
        }
        res.push_back(prefix);
    } else {
        for (size_t i = 0; i < s.size(); ++i) {
            foo(res, s.substr(0, i) + s.substr(i+1), prefix + s[i]);
        }
    }
}

std::vector<std::string> permutations(std::string s) {
    if(s.empty()){
        return {""};
    }
    std::vector<std::string> res;
    std::cout << "input: " << s << std::endl;
    for(int i = 0;i<s.size();i++){
        foo(res,s.substr(0,i) + s.substr(i+1), s.substr(i,1));
    }
    return res;
}


int main() {
    auto res = permutations("");
    for (const auto& item:res) {
        std::cout << item << std::endl;
    }
    return 0;
}
