#include <string>
#include <vector>
#include <queue>
#include <cstdio>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    int sco = K;
    priority_queue<int,vector<int>, greater<int>> pq;
    for(const auto& it : scoville)
        pq.push(it);
    
    while(false == pq.empty())
    {
        int f = pq.top();
        if(f >= K)
            return answer;
        pq.pop();
        
        if(true == pq.empty())
            return -1;
        
        int s = pq.top();
        pq.pop();
        
        pq.push(f + s * 2);
        answer++;
    }
    return -1;
}