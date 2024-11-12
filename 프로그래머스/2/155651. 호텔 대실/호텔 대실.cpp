#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<pair<int,int>> times;
    for(int i = 0; i < book_time.size(); ++i)
    {
        int start_h = stoi(book_time[i][0].substr(0, 2));
        int start_m = stoi(book_time[i][0].substr(3, 2));
        int end_h = stoi(book_time[i][1].substr(0, 2));
        int end_m = stoi(book_time[i][1].substr(3, 2));
        
        int start = start_h * 60 + start_m;
        int end = end_h * 60 + end_m + 10; 
        
        times.push_back({start, 1});
        times.push_back({end, -1}); 
    }
    
    int curRoom = 0;
    sort(times.begin(), times.end());
    for(const auto& time : times)
    {
        curRoom += time.second;
        answer = max(answer, curRoom);
    }
    return answer;
}