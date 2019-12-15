// Decode String

class Solution {
public:
    string decodeString(string s) {
    
    int i=0; 
    return decode(s, i);
    }
    
    string decode(string &s, int &i)
    {
        int count;
        string result;
        while(i<s.size())
        {
            if(isdigit(s[i]))
            {
                int beg = i;
                while(isdigit(s[i]))
                    i++;
                count = stoi(s.substr(beg, i-beg));
            }
            if(s[i] == '[')
            {
                string temp = decode(s, ++i);
                while(count--)
                    result = result + temp;
            }
            else
            if(isalpha(s[i]))
            {
                result = result + s[i];
            }
            else
            {
                return(result);
            }
            i++;
        }
        return(result);
    }
};
