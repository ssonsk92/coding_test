#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";

    vector<int> lstNumber;
    size_t pos = 0;
    while ((pos = s.find(" ")) != string::npos)
    {
        string strNum = s.substr(0, pos);
        s = s.substr(pos + 1);
        std::stringstream ssInt(strNum);

        int num = 0;;
        ssInt >> num;

        if (!ssInt.fail())
        {
            lstNumber.push_back(num);
        }
    }

    std::stringstream ssInt(s);
    int num = 0;;
    ssInt >> num;

    if (!ssInt.fail())
    {
        lstNumber.push_back(num);
    }

    std::stringstream strMinNum;
    strMinNum << *min_element(lstNumber.begin(), lstNumber.end());
    std::stringstream strMaxNum;
    strMaxNum << *max_element(lstNumber.begin(), lstNumber.end());
    answer += strMinNum.str() + " " + strMaxNum.str();

    return answer;
}

int main()
{
    string s("-1 -2 -3 -4");
    cout << solution(s) << endl;
}