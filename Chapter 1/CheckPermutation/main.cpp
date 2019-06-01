#include <iostream>
#include <vector>

using namespace std;

// ASCII
bool isPermutation(const string &str1, const string &str2)
{
    if (str1.size() != str2.size())
        return false;

    vector<int> letters(CHAR_MAX, 0);
    for (size_t i = 0; i < str1.size(); ++i)
    {
        letters[ str1[i] ]++;
        letters[ str2[i] ]--;
    }

    for (size_t i = 0; i < letters.size(); ++i)
    {
        if (letters[i] != 0)
            return false;
    }

    return true;
}

int main()
{
    cout << isPermutation("abbcccdddd", "babcdcdcdd") << endl;
    return 0;
}
