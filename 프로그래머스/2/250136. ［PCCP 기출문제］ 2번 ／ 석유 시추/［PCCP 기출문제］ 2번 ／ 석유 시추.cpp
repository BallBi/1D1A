#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

void bfs(vector<vector<int>>& land, vector<vector<bool>>& visited, int x, int y, map<int, int>& YOilAmount)
{
    // 상 하 좌 우
    int dx[4] = { -1,1,0,0 };
    int dy[4] = { 0,0, -1, 1 };

    queue<pair<int, int>> q;
    set<int> setY;

    q.push({ x,y });
    setY.insert(y);

    int oilSize = 0;

    while (true != q.empty())
    {
        int nX = q.front().first;
        int nY = q.front().second;
        q.pop();

        visited[nX][nY] = true;

        int cX = 0;
        int cY = 0;

        for (int i = 0; i < 4;++i)
        {
            cX = nX + dx[i];
            cY = nY + dy[i];

            if(cX < 0 || cX >= land.size()
                || cY < 0 || cY >= land[0].size())
                continue;
            if (true == visited[cX][cY] || 0 == land[cX][cY])
                continue;

            visited[cX][cY] = true;
            q.push({ cX, cY });
            setY.insert(cY);
        }
        oilSize++;
    }

    for (auto y : setY)
        YOilAmount[y] += oilSize;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    int n = land[0].size();
    int m = land.size();
    
    map<int, int> YOilAmount;
    vector<vector<bool>> visited (m, vector<bool>(n, false));
    for (int i = 0; i < m;++i)
    {
        for (int j = 0; j < n;++j)
        {
            if (true == visited[i][j] || 0 == land[i][j])
                continue;

            bfs(land, visited, i, j, YOilAmount);
        }
    }
    
    for(auto it : YOilAmount)
        answer = answer > it.second ? answer : it.second;
    
    return answer;
}