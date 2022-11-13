#include <string>
#include <vector>

using namespace std;

int solution(int n, int k) {
    int answer = 0;
    int discount_cnt=0;
    discount_cnt=n/10;
    answer=(12000*n)+(2000*(k-discount_cnt));
    return answer;
}