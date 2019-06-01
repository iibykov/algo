#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

// if ASCII
bool isUnique(const string &str)
{
    vector<bool> existence(CHAR_MAX, false);
    for(size_t c = 0; c < str.size(); ++c)
    {
        if(existence[ tolower(str[c]) ] != false)
            return false;
        else
            existence[ tolower(str[c]) ] = true;
    }

    return true;
}

bool isUniqueChars(string str)
{
    int checker = 0;
    for (size_t i= 0; i < str.length(); i++)
    {
        int val = str[i] - 'a';
        if ((checker & (1 << val)) > 0)
            return false;

        checker |= (1 << val);
    }
    return true;
}

int main()
{
    string str = "Helo Ilya!";
    cout << isUniqueChars(str) << endl;
    return 0;
}
