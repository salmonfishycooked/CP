/**
 * 按正则表达式分割字符串 (Divide a specific string by regex pattern)
 */

#include <bits/stdc++.h>

std::vector<std::string> splitString(const std::string& input, const std::string& regexPattern) {
    std::regex re(regexPattern);
    std::sregex_token_iterator it(input.begin(), input.end(), re, -1);
    std::sregex_token_iterator reg_end;

    std::vector<std::string> result;
    for (; it != reg_end; ++it) {
        result.push_back(it->str());
    }

    return result;
}
