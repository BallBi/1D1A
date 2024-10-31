class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> sRows(1001, "");
        string answer = "";
        int idx = 0;
        bool up = false;
        while(s.length() > idx)
        {
            if(false == up)
            {
                for(int i = 0; i < numRows; ++i)
                {
                    if(s.length() == idx)
                        break;

                    sRows[i] += s[idx];
                    idx++;
                }
                up = true;
            }
            else
            {
                for(int i = numRows - 2; i > 0; --i)
                {
                    if(s.length() == idx)
                        break;

                    sRows[i] += s[idx];
                    idx++;
                }
                up = false;
            }
        }

        for(int i = 0; i<numRows; ++i)
            answer += sRows[i];
        
        return answer;
    }
};