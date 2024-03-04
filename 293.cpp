class Solution {

public:
    vector<string> generatePossibleNextMoves(string currentState) {
        vector<string> answer;
        int fast = 1;
        while (fast < currentState.length()) {
            if (currentState[fast - 1] == '+' and currentState[fast] == '+') {
                currentState[fast - 1] = currentState[fast] = '-';
                answer.push_back(currentState);
                currentState[fast - 1] = currentState[fast] = '+';
            }
            fast ++;
        }
        return answer;
    }
};