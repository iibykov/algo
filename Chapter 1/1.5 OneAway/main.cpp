#include <iostream>
#include <string>

using namespace std;

bool isOneOrZeroEdit(const string &original, const string &modified)
{
    int dif = original.size() - modified.size();
    if (abs(dif) > 1)
        return false;

    int count = 0;
    for (size_t i = 0; i < original.size();)
    {
        bool isEqual = ( original[i + count * dif] == modified[i] );
        if (!isEqual)
            count++;

        if (count > 1)
            return false;

        if ((dif != 1) || isEqual)
            i++;
    }

    return true;
}

int main()
{
    // remove
    cout << isOneOrZeroEdit("pale", "ple") << endl;
    cout << isOneOrZeroEdit("pales", "pale") << endl;
    cout << isOneOrZeroEdit("pale", "ale") << endl;

    // change
    cout << isOneOrZeroEdit("pale", "bale") << endl;
    cout << isOneOrZeroEdit("pales", "paled") << endl;

    // add
    cout << isOneOrZeroEdit("ple", "pale") << endl;
    cout << isOneOrZeroEdit("pale", "pales") << endl;
    cout << isOneOrZeroEdit("ale", "pale") << endl;

    return 0;
}
