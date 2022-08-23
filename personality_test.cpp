#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char, int> m = {
    {'R', 0}, {'T', 0},
    {'C', 0}, {'F', 0},
    {'J', 0}, {'M', 0},
    {'A', 0}, {'N', 0}, };

    for (size_t i = 0; i < choices.size(); ++i)
    {
        int n = choices[i];
        int key_idx = (n < 4) ? 0 : 1;
        char key = survey[i][key_idx];
        int score = abs(4 - n);
        m[key] += score;
    }

    answer += (m['R'] < m['T']) ? 'T' : 'R';
    answer += (m['C'] < m['F']) ? 'F' : 'C';
    answer += (m['J'] < m['M']) ? 'M' : 'J';
    answer += (m['A'] < m['N']) ? 'N' : 'A';


    return answer;
}

int main()
{
    vector<string> survey = { "AN", "CF", "MJ", "RT", "NA" };
    vector<int> choices = { 5, 3, 2, 7, 5 };
    cout << solution(survey, choices) << endl;

    return 0;
}