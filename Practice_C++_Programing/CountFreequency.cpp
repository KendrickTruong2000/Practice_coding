#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

void findMaxFrequency(int[], int, int *, vector<int> &);
int countFrequency(int[], int);

int main(int argc, char const *argv[])
{
    int nums[] = {1, 2, 2, 3, 1, 4};
    // int nums[] = {1, 2, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    int maxFrequency = 0;

    maxFrequency = countFrequency(nums, size);

    cout << "Max Frequency is: " << maxFrequency << "\n";

    return 0;
}
void findMaxFrequency(int nums[], int size, int *maxFrequency, vector<int> &elements)
{
    unordered_map<int, int> freqMap;
    *maxFrequency = 0;

    for (int i = 0; i < size; i++)
    {
        if (nums[i] >= 1 && nums[i] <= 100)
        {
            freqMap[nums[i]]++;
            if (freqMap[nums[i]] > *maxFrequency)
            {
                *maxFrequency = freqMap[nums[i]];
            }
        }
    }

    for (auto &pair : freqMap)
    {
        if (pair.second == *maxFrequency)
        {
            elements.push_back(pair.first);
        }
    }
}

int countFrequency(int nums[], int size)
{
    vector<int> elements;
    int maxFrequency = 0, count = 0, result = 0;
    findMaxFrequency(nums, size, &maxFrequency, elements);

    result = maxFrequency * elements.size();

    return result;
}