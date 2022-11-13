#include <string>
#include <vector>

using namespace std;

double solution(vector<int> numbers) {
    double answer = 0;
    int size=numbers.size();
    while(numbers.size())
    {
        answer=answer+numbers.back();
        numbers.pop_back();
    }
    return answer/size;
}