/*
타짜_LV2.cpp
완전탐색으로 1) 교체할 2장의 카드를 선택하고, 2) 해당 카드 위치에 36종류의 카드를 대입하면서 가장 우위의 조합을 저장합니다.
1) 2장의 카드를 선택하는 경우의 수는 5C2 = 10
2) 2개의 위치에 36종의 카드를 대입하는 경우의 수는 36*36 = 1296
총 경우의 수는 12960개이므로 완전탐색이 가장 쉬운 접근법입니다.

문제에 트릭이 숨어있는데, 정답으로 FH와 TP는 존재할 수 없습니다.
입력으로 주어진 카드 중 숫자가 같은 카드가 있으면 나머지 카드 중 2장을 바꿔 FC를 만들 수 있습니다.
모든 숫자가 다르다면 FH를 만들 수 없음이 자명하므로 FH는 어떤 입력에서도 답이 될 수 없습니다.
또, 모든 숫자가 다를 때 ST를 만들 수 없는 경우는 없으므로 TP는 답이 될 수 없습니다.
이 트릭을 눈치챈 사람은 구현 문제인 만큼 코드양이 줄어 시간을 절약할 수 있을 것입니다.
*/

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ans;
int ans_grade;

void update_ans(vector<int> numbers, vector<int> shapes)
{
    //모양 숫자 동일한 카드 검사
    vector<bool> check(36, false);
    for (int i = 0; i < 5; i++)
    {
        int ind = (numbers[i] - 1) + shapes[i] * 9;
        if (check[ind])
            return;
        check[ind] = true;
    }

    sort(numbers.begin(), numbers.end(), greater<int>());
    sort(shapes.begin(), shapes.end());
    string res;
    int res_grade;
    if (numbers[0] == numbers[3] || numbers[1] == numbers[4])
    {
        res.append("FC");
        res_grade = 3;
    }
    else if (shapes[0] == shapes[4])
    {
        res.append("FL");
        res_grade = 2;
    }
    else if ((numbers[0] == numbers[1] + 1) && (numbers[1] == numbers[2] + 1) && (numbers[2] == numbers[3] + 1) && (numbers[3] == numbers[4] + 1))
    {
        res.append("ST");
        res_grade = 1;
    }
    else
    {
        res.append("TP");
        res_grade = 0;
    }

    res.push_back(' ');
    for (int i = 0; i < 5; i++)
        res.push_back(numbers[i] + '0');

    if (ans_grade > res_grade)
        return;
    if (res_grade > ans_grade)
    {
        ans = res;
        ans_grade = res_grade;
        return;
    }

    if (res_grade == 3)
    { //포카드
        char ans_most, ans_second, res_most, res_second;
        if (ans[3] == ans[4])
        {
            ans_most = ans[3];
            ans_second = ans[7];
        }
        else
        {
            ans_most = ans[7];
            ans_second = ans[3];
        }
        if (res[3] == res[4])
        {
            res_most = res[3];
            res_second = res[7];
        }
        else
        {
            res_most = res[7];
            res_second = res[3];
        }
        if (res_most > ans_most || (res_most == ans_most && res_second > ans_second))
            ans = res;
    }
    else
    {
        for (int i = 3; i < 7; i++)
        {
            if (res[i] < ans[i])
                break;
            if (res[i] > ans[i])
            {
                ans = res;
                break;
            }
        }
    }
}

void pick_two(vector<int> numbers, vector<int> shapes, int ind, int picked)
{
    if (ind >= 5)
        return;
    if (picked != -1)
    {
        int i, j;
        vector<int> new_numbers = numbers, new_shapes = shapes;
        // numbers[picked]->i, numbers[ind]->j로 교체
        for (i = 0; i < 36; i++)
        {
            new_numbers[picked] = i % 9 + 1;
            new_shapes[picked] = (int)i / 9;
            for (j = 0; j < 36; j++)
            {
                new_numbers[ind] = j % 9 + 1;
                new_shapes[ind] = (int)j / 9;
                update_ans(new_numbers, new_shapes);
            }
        }
    }
    else
    {
        pick_two(numbers, shapes, ind + 1, ind);
    }
    pick_two(numbers, shapes, ind + 1, picked);
}

string solution(vector<int> numbers, vector<int> shapes)
{
    ans = "TP 00000";
    ans_grade = 0;
    pick_two(numbers, shapes, 0, -1);
    return ans;
}

int main()
{
    solution({5, 2, 7, 6, 3}, {1, 1, 3, 3, 3});
}