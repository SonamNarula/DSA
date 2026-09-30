class Solution {
private:
    std::set<string> multiply(const std::set<string>& set1, const std::set<string>& set2) {
        if (set1.empty()) return set2;
        if (set2.empty()) return set1;
        
        std::set<string> result;
        for (const string& s1 : set1) {
            for (const string& s2 : set2) {
                result.insert(s1 + s2);
            }
        }
        return result;
    }

    std::set<string> parse(const std::string& expr, int& index) {
        std::set<string> totalSet;
        std::set<string> currentSet;
        currentSet.insert("");

        while (index < expr.length()) {
            char ch = expr[index];

            if (ch == '{') {
                index++;
                std::set<string> subSet = parse(expr, index);
                currentSet = multiply(currentSet, subSet);
            } 
            else if (ch == '}') {
                index++;
                break;
            } 
            else if (ch == ',') {
                index++;
                totalSet.insert(currentSet.begin(), currentSet.end());
                currentSet.clear();
                currentSet.insert("");
            } 
            else {
                std::set<string> charSet = {std::string(1, ch)};
                currentSet = multiply(currentSet, charSet);
                index++;
            }
        }

        totalSet.insert(currentSet.begin(), currentSet.end());
        return totalSet;
    }

public:
    std::vector<std::string> braceExpansionII(std::string expression) {
        int index = 0;
        std::set<string> resultSet = parse(expression, index);
        return std::vector<std::string>(resultSet.begin(), resultSet.end());
    }
};