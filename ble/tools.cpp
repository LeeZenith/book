#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm> // 用于std::remove_if

std::vector<int> splitStringToIntVector(const std::string& str) {
    std::vector<int> result;
    std::stringstream ss(str);
    std::string token;

    while (getline(ss, token, ',')) {
        // 去除可能存在的空格
        token.erase(remove_if(token.begin(), token.end(), ::isspace), token.end());
        // 将字符串转换为整数并添加到vector中
        result.push_back(stoi(token));
    }

    return result;
}

std::vector<int> splitStringToIntVector(const std::string& str, char delimiter) {
    std::vector<int> result;
    std::stringstream ss(str);
    std::string token;

    while (getline(ss, token, delimiter)) {
        // 去除可能存在的空格
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        // 将字符串转换为整数并添加到vector中
        result.push_back(std::stoi(token));
    }

    return result;
}

std::string saveOutputToString(const std::vector<int>& numbers) {
    std::ostringstream oss;
    for (size_t i = 0; i < numbers.size(); ++i) {
        oss << numbers[i];
        if (i < numbers.size() - 1) {
            oss << " "; // 在数字之间添加空格，最后一个数字后不添加
        }
    }
    return oss.str();
}

std::vector<std::string> splitStringToVector(const std::string& str) {
    std::vector<std::string> result;
    std::istringstream iss(str);
    std::string token;

    while (getline(iss, token, ' ')) {
        result.push_back(token);
    }

    return result;
}

template<typename T>
std::string toString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename... Args>
std::string concatenateToString(Args... args) {
    std::vector<std::string> strings = { toString(args)... };
    std::string result;
    for (const auto& str : strings) {
        result += str + " ";
    }
    // 移除最后一个多余的空格
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

int main() {
    std::string numbers = "1,2,3,4,5";
    std::vector<int> vec = splitStringToIntVector(numbers);

    // 打印结果，验证函数是否正确工作
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
