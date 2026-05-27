#include <iostream>
#include <vector>
#include <string>

using namespace std;

void sendCAN(vector<string> data);
vector<string> receiveACK();
string decToHexa(int n);
int hexToDec(string hex);
void print(vector<string> data);

int main()
{
    vector<string> data =
    {
        "0x22", "0xAA", "0xBB", "0xCC",
        "0xDD", "0xEE", "0x11", "0xFF",
        "0x41", "0x22", "0x33"
    };

    sendCAN(data);

    return 0;
}

void print(vector<string> data)
{
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << " ";
    }

    cout << endl;
}

string decToHexa(int n)
{
    if (n == 0)
        return "0x00";

    string ans;

    while (n != 0)
    {
        int rem = n % 16;

        if (rem < 10)
            ans = char(rem + 48) + ans;
        else
            ans = char(rem + 55) + ans;

        n /= 16;
    }

    return "0x" + ans;
}

int hexToDec(string hex)
{
    int result = 0;

    for (int i = 2; i < hex.size(); i++)
    {
        result *= 16;

        if (hex[i] >= '0' && hex[i] <= '9')
            result += hex[i] - '0';
        else
            result += hex[i] - 'A' + 10;
    }

    return result;
}

vector<string> receiveACK()
{
    vector<string> flow =
    {
        "0x30", // Continue To Send
        "0x08", // Block Size
        "0x00"  // STmin
    };

    cout << "Receive Flow Control: ";
    print(flow);

    return flow;
}

void sendCAN(vector<string> data)
{
    int len = data.size();

    vector<string> frame;

    //-----------------------------------
    // SINGLE FRAME
    //-----------------------------------

    if (len <= 7)
    {
        frame.push_back("0x0" + to_string(len));

        for (int i = 0; i < len; i++)
        {
            frame.push_back(data[i]);
        }

        cout << "Single Frame: ";
        print(frame);

        return;
    }

    //-----------------------------------
    // FIRST FRAME
    //-----------------------------------

    frame.push_back("0x10");
    frame.push_back(decToHexa(len));

    int index = 0;

    for (int i = 0; i < 6; i++)
    {
        frame.push_back(data[index++]);
    }

    cout << "First Frame: ";
    print(frame);

    //-----------------------------------
    // FLOW CONTROL
    //-----------------------------------

    vector<string> flow = receiveACK();

    int blockSize = hexToDec(flow[1]);

    //-----------------------------------
    // CONSECUTIVE FRAMES
    //-----------------------------------

    int sequence = 1;
    int sentFrames = 0;

    while (index < len)
    {
        vector<string> cf;

        //--------------------------------
        // Sequence Number
        //--------------------------------

        int pci = 0x20 | (sequence & 0x0F);

        cf.push_back(decToHexa(pci));

        //--------------------------------
        // Add up to 7 bytes
        //--------------------------------

        int count = 0;

        while (count < 7 && index < len)
        {
            cf.push_back(data[index++]);
            count++;
        }

        cout << "Consecutive Frame: ";
        print(cf);

        sequence++;

        if (sequence > 15)
            sequence = 0;

        sentFrames++;

        //--------------------------------
        // Block Size Handling
        //--------------------------------

        if (sentFrames == blockSize && index < len)
        {
            cout << "Wait For Next Flow Control..." << endl;

            flow = receiveACK();

            sentFrames = 0;
        }
    }
}