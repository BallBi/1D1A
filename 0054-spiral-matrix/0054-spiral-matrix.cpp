class Solution {
    enum class Direction : int
    {
        right = 0,
        down,
        left,
        up,
    };
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> answer;
        int n = 0;
        int m = 0;

        int left = 0, top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;
        int totalSize = (right + 1) * (bottom + 1);
    
        bool change = false;
        bool isEnd = false;

        int d = 0;

        while (totalSize > answer.size())
        {
            switch((Direction)d)
            {
                case Direction::right:
                {
                    while(n <= right)
                    {
                        answer.push_back(matrix[m][n]);
                        n++;
                    }
                    n = right;
                    m++;
                    right--;
                } break;
                case Direction::down:
                {
                    while(m <= bottom)
                    {
                        answer.push_back(matrix[m][n]);
                        m++;
                    }
                    m = bottom;
                    n--;
                    bottom--;
                } break;
                case Direction::left:
                {
                    while(n >= left)
                    {
                        answer.push_back(matrix[m][n]);
                        n--;
                    }
                    n = left;
                    m--;
                    left++;
                } break;
                case Direction::up:
                {
                    while(m > top)
                    {
                        answer.push_back(matrix[m][n]);
                        m--;
                    }
                    n++;
                    top++;
                    m = top;
                } break;
            }

            d++;
            d %= 4;
        }

        return answer;
    }
};