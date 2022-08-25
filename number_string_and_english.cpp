#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(string s) {
    map<string, int> number_table = {
       { "zero", 0 }, {"one", 1}, { "two", 2 }, { "three", 3 }, { "four", 4 },
       { "five", 5 }, { "six", 6 }, { "seven", 7 }, { "eight", 8 }, { "nine", 9 } };

    for (auto it : number_table)
    {
        string num_str = it.first;
        size_t pos = s.find(num_str);
        while (pos != string::npos)
        {
            auto start = s.begin() + pos;
            auto end = start + num_str.size();
            s.replace(start, end, to_string(it.second));
            pos = s.find(num_str);
        }
    }

    return stoi(s);
}

int main()
{
    string s("one4seveneight");
    cout << solution(s) << endl;

    return 0;
};