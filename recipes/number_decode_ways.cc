#include <stdio.h>
#include <vector>
using namespace std;

void solve(int s, int current, vector<int>& numbers, vector<int>& answers, int start) {
    // 当前和为0，输出结果
    if (current == 0) {
        printf("%d=", s);
        for (int i = 0; i < start-1; i++) {
            if (answers[i] != 0) {
                printf("%d*%d+", numbers[i], answers[i]);
            }
        }
        if (answers[start-1] != 0) {
            printf("%d*%d", numbers[start-1], answers[start-1]);
        }
        printf("\n");
        return;
    }

    // 到达末尾无需递归求解了
    if (start == numbers.size()) {
        return;
    }

    solve(s, current, numbers, answers, start+1);

    if (current - numbers[start] >= 0) {
        answers[start]++;
        solve(s, current-numbers[start], numbers, answers, start);
    }
}

int main() {
    int s = 5;
    int array[] = {3,2,1};
    vector<int> numbers(array, array+3);
    vector<int> answers(3, 0);

    solve(s, s, numbers, answers, 0);
    return 0;
}
