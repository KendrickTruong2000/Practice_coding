#include <iostream>
#include <string>
#include <vector>

using namespace std;

void getVersionNum(string, string, vector<int>&, vector<int>&);

bool isValidVersion(string, string);
int compareVersion(string, string);

int main(int argc, char const *argv[])
{
    string version1, version2;
    int result = 0;

    cout << "Please enter version 1: ";
    cin >> version1;
    cout << "Please enter version 2: ";
    cin >> version2;

    result = compareVersion(version1, version2);

    if (result == 0)
    {
        cout << "Both version are equal.\n";
    }
    else if (result == -1)
    {
        cout << "Version 1 is older than version 2";
    }
    else
    {
        cout << "Version 1 is newer than version 2";
    }

    return 0;
}

void getVersionNum(string version1, string version2, vector<int>& versionNum1, vector<int>& versionNum2)
{
    int count = 0;

    for (int i = 0; i < version1.length(); i++)
    {
        if (isdigit(version1[i]))
        {
            versionNum1.push_back(version1[i]-'0');
        }
    }

    for (int j = 0; j < version2.length(); j++)
    {
        if (isdigit(version2[j]))
        {
            versionNum2.push_back(version2[j]-'0');
        }
    }

    while (count < versionNum1.size() - versionNum2.size())
    {
        if (versionNum1.size() > versionNum2.size())
        {
            versionNum2.push_back(0);
        }
        else
        {
            versionNum1.push_back(0);
        }
        count++;
    }
}

bool isValidVersion(string version1, string version2)
{
    bool isValid = false;

    if (version1.length() < 1 && version2.length() > 500)
    {
        cout << "Version is too long or too short.\n";
        return isValid;
    }

    else
    {
        for (char c : version1)
        {
            if (!isdigit(c) && c != '.')
            {
                cout << "Version contains invalid characters.\n";
                return isValid;
            }
        }

        for (char c : version2)
        {
            if (!isdigit(c) && c != '.')
            {
                cout << "Version contains invalid characters.\n";
                return isValid;
            }
        }
    }
    isValid = true;

    return isValid;
}

int compareVersion(string version1, string version2)
{
    vector<int> versionNum1;
    vector<int> versionNum2;
    int result;

    if (isValidVersion(version1, version2))
    {
        getVersionNum(version1, version2, versionNum1, versionNum2);

        for (int i = 0; i < versionNum1.size(); i++)
        {
            if (versionNum1[i] > versionNum2[i])
            {
                result = 1;
            }
            else if ( versionNum1[i] < versionNum2[i])
            {
                result = -1;
            }
            else
            {
                result = 0;
            }
        }
    }

    return result;
}
