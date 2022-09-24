#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Comp
{
public:
    Comp() {};
    bool operator()(int lhs, int rhs)
    {
        string l = to_string(lhs);
        string r = to_string(rhs);

        return stoi(l + r) > stoi(r + l);
    }
};

string solution(vector<int> numbers) {
    string answer = "";

    int max_num = *max_element(numbers.begin(), numbers.end());
    if (0 == max_num)
        return "0";

    sort(numbers.begin(), numbers.end(), Comp());

    for (int num : numbers)
    {
        answer += to_string(num);
    }

    return answer;
}

int main()
{
    vector<int> numbers = { 3, 30, 34, 5, 9 };
    //vector<int> numbers = { 979, 97, 978, 81, 818, 817 }; //9799797881881817
    //vector<int> numbers = {97, 978 };
    //vector<int> numbers = {42, 423, 34, 3, 30 };
    //vector<int> numbers = { 3, 33, 330 };
    cout << solution(numbers) << endl;
    return 0;
}