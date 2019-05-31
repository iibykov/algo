#include <iostream>
#include <string>

using namespace std;

string replaceCharByString(const string &str, char ch, const string &sub)
{
    int spaceCount = 0;
    for (size_t i = 0; i < str.size(); ++i)
    {
        if (str[i] == ch)
            spaceCount++;
    }

    string result = str + string(spaceCount * (sub.size() - 1), ' ');
    size_t shiftPos = result.size() - 1;
    for (int i = str.size() - 1; i > 0; --i)
    {
        if (result[i] != ch)
        {
            result[shiftPos] = result[i];
            shiftPos--;
        }
        else
        {
            result[shiftPos] = '0';
            result[shiftPos - 1] = '2';
            result[shiftPos - 2] = '%';
            shiftPos -= 3;
        }
    }

    return result;
}

string urlif(const string &str)
{
    return replaceCharByString(str, ' ', "%20");
}


int main()
{
    cout << urlif("but it differs from most other such systems") << endl;
    return 0;
    QSerialPort
}
