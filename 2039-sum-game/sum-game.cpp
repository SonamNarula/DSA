class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int diff = 0;
        int qLeft = 0, qRight = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                qLeft++;
            else
                diff += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                qRight++;
            else
                diff -= num[i] - '0';
        }

        // Equal number of '?' on both sides:
        // Bob can mirror Alice's moves.
        if (qLeft == qRight) {
            return diff != 0;
        }

        // Odd difference in '?' count:
        // Alice gets an unmatched move and can force inequality.
        if (abs(qLeft - qRight) % 2 == 1) {
            return true;
        }

        // Even difference: Bob can potentially compensate.
        // Alice wins unless the existing difference can be
        // exactly cancelled.
        return diff != 9 * (qRight - qLeft) / 2;
    }
};