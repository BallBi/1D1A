#include <vector>
#include <set>

using namespace std;

int solution(vector<int> nums)
{
    int maxPoket = nums.size()/2;
    set<int> poketmon;
    
    for(int i = 0; i < nums.size(); ++i)
    {
        poketmon.insert(nums[i]);
    }
    
    maxPoket = maxPoket > poketmon.size() ? poketmon.size() : maxPoket;
    
    return maxPoket;
}