#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    double d2 = pow(d,2);
    
    for(int i = 0;i<=d; i += k)
    {
        long long maxY = sqrt(static_cast<long long>(d2) - static_cast<long long>(i) * i);
        answer += (maxY / k) + 1;
    }
    
    return answer;
}