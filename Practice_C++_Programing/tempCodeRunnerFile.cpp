if (tempStr.find(str[i]) == string::npos)
        {
            tempStr += str[i];
            if (tempStr.length() > maxLen)
                maxLen = tempStr.length();
        }
        else
        {
            // Remove characters up to and including the first occurrence of str[i]
            tempStr = tempStr.substr(tempStr.find(str[i]) + 1);
            tempStr += str[i];
        }
