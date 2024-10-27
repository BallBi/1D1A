class Solution {
public:
    bool isValid(string s) 
    {
        vector<char> list;

        for(int i = 0; i < s.length(); ++i)
        {
            if('(' == s[i] || '{' == s[i] || '[' == s[i])
            {
                list.push_back(s[i]);
                continue;
            }

            if (true == list.empty())
                return false;

            if(')' == s[i])
            {
                if('(' == list.back())
                {
                    list.pop_back();
                    continue;
                }
                return false;
            }
            else if('}' == s[i])
            {
                if('{' == list.back())
                {
                    list.pop_back();
                    continue;
                }

                return false;
            }
            else if(']' == s[i])
            {
                if('[' == list.back())
                {
                    list.pop_back();
                    continue;
                }
                return false;
            }
        }

        if (false == list.empty())
            return false;

        return true;
    }
};