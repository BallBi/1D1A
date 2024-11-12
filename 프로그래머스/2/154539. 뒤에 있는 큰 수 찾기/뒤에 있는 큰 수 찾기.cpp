#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    int n =numbers.size();
    vector<int> answer(n,-1);
    stack<int> num;
    for(int i = n -1; i >= 0; --i)
    {
        while(false == num.empty() && num.top() <= numbers[i])
            num.pop();
                
        if(false == num.empty())
            answer[i] = num.top();
        
        num.push(numbers[i]);
    }
    return answer;
}