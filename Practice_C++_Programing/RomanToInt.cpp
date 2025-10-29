#include <iostream>
#include <string>

using namespace std;

int romanToInt(string);

int main(int argc, char const *argv[])
{
    string roman;
    cout << "Please enter Roman number: ";
    cin >> roman;
    cout << romanToInt(roman) << "\n";
    return 0;
}

int romanToInt(string s)
{
    string symbol[] = {"I", "V", "X", "L", "C", "D", "M"};
    int value[] = {1, 5, 10, 50, 100, 500, 1000};
    string temp;
    int sum = 0;

    if (s.length() >= 1 && s.length() <= 15)
    {
        for (int i = 0; i < s.length(); i++)
        {
            temp = s[i];
            // cout << s[i] << "\n";
            // cout << sum << "\n";

            if (temp.compare(symbol[0]) == 0)
            {
                temp = s[i + 1];

                if (temp.compare(symbol[1]) == 0)
                {
                    sum += (value[1] - 1);
                    i += 1;
                    continue;
                }

                if (temp.compare(symbol[2]) == 0)
                {
                    sum += (value[2] - 1);
                    i += 1;
                    continue;
                }
                else
                {
                    sum += value[0];
                    continue;
                }
            }
            else if (temp.compare(symbol[2]) == 0)
            {
                temp = s[i + 1];

                if (temp.compare(symbol[3]) == 0)
                {
                    sum += (value[3] - 10);
                    i += 1;
                    continue;
                }

                if (temp.compare(symbol[4]) == 0)
                {
                    sum += (value[4] - 10);
                    i += 1;
                    continue;
                }
                else
                {
                    sum += value[2];
                    continue;
                }
            }
            else if (temp.compare(symbol[4]) == 0)
            {
                temp = s[i + 1];

                if (temp.compare(symbol[5]) == 0)
                {
                    sum += (value[5] - 100);
                    i += 1;
                    continue;
                }

                if (temp.compare(symbol[6]) == 0)
                {
                    sum += (value[6] - 100);
                    i += 1;
                    continue;
                }
                else
                {
                    sum += value[4];
                    continue;
                }
            }
            else
            {
                for (int j = 0; j < 7; j++)
                {
                    if (temp.compare(symbol[j]) == 0)
                    {
                        sum += value[j];
                    }
                }
                continue;
            }
        }
    }

    return sum;
}
