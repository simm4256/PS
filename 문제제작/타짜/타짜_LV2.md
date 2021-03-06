당신은 카드 5장으로 하는 게임을 플레이 중입니다.

카드 한 장은 모양과 숫자의 조합으로 구성되어 있습니다.

모양은 ◆, ♥, ♣, ♠ 4종류가 있습니다. 그러나 이 문제에선 편의상 0,1,2,3으로 표현합니다.

숫자는 1부터 9까지 9종류가 있습니다.

모양과 숫자가 동일한 카드는 없습니다.

따라서 카드는 총 36종류입니다.

<br>
이 포커의 족보는 다음과 같습니다.

1. `FC(포카드)` : 같은 숫자 4장 (ex. 64444)
2. `FH(풀하우스)` : 같은 숫자 3장 + 같은 숫자 2장 (ex. 55533)
3. `FL(플러쉬)` : 같은 모양 5장
4. `ST(스트레이트)` : 연속된 숫자 5장 (ex. 76543)
5. `TP(탑)` : 위 4개의 족보에 해당하지 않는 모든 카드 조합

<br>
카드 조합 간의 우위는 다음 조건에 따라 정합니다.

1. 위 족보 리스트에서 낮은 번호의 족보가 높은 번호의 족보를 이깁니다. 예를 들어, `1.FC(포카드)`는 `2.FH(풀하우스)`를 이깁니다.
2. 두 카드 조합이 같은 족보라면 해당 족보에 따라 다음과 같이 결정됩니다.
   * `FC(포카드)` : 포카드를 이루는 4장의 숫자가 높은 쪽이 이깁니다. 이 숫자가 같으면 나머지 1장의 숫자가 높은 쪽이 이깁니다. 나머지 1장의 숫자도 같으면 무승부입니다.
   * `FH(풀하우스)` : 3장의 같은 숫자를 이루는 카드가 높은 쪽이 이깁니다. 이 숫자가 같으면 나머지 2장의 숫자가 높은 쪽이 이깁니다. 나머지 2장의 숫자도 같으면 무승부입니다.
   * `FL(플러쉬)` : 5장의 카드 중 숫자가 가장 높은 카드가 더 높은 쪽이 이깁니다. 가장 높은 카드가 같으면, 그 다음으로 높은 카드가 높은 쪽이 이깁니다. 이 과정을 5장에 걸쳐 반복합니다. 만약 모든 번호가 같다면 무승부입니다.
   * `ST(스트레이트)` : 플러쉬와 동일합니다.
   * `TP(탑)` : 플러쉬와 동일합니다.
3. 여러 족보가 동시에 적용되는 카드 조합이라면, 그 중 가장 우위에 있는 족보로 결정됩니다. 예를 들어,  카드의 숫자가 `33322` 이고 모든 카드의 모양이 `◆`라면 `FH(풀하우스)`임과 동시에 `FL(플러쉬)`이지만 `FH(풀하우스)`로 표기합니다.
4. 모양에 따른 우위는 없습니다.

<br>
타짜인 당신은 5장의 카드를 받은 후 2장의 카드를 골라 원하는 카드로 교체할 수 있습니다.

단, 모양과 숫자가 동일한 카드를 여러 개 가질 수는 없습니다.

5장의 카드에 대한 정보 numbers와 shapes가 입력으로 주어집니다.

주어진 카드 중 2장을 원하는 카드로 교체했을 때 만들 수 있는 가장 우선순위가 높은 카드 조합을 return하는 solution 함수를 완성해주세요.

<br>

## 제한 사항

* numbers에는 각 카드의 숫자 목록이 주어집니다. 숫자의 범위는 1~9입니다.
* shapes에는 각 카드의 모양 목록이 주어집니다. 모양의 범위는 0~3입니다.
* 숫자와 모양이 같은 카드는 없습니다.
* return값은 8글자의 문자열입니다. 첫 2글자는 해당하는 족보의 약자이고, 한 칸을 띄운 후 5장의 카드 숫자를 내림차순으로 채웁니다.


<br>

## 입출력 예

|   numbers   |   shapes    |   return   |
| :---------: | :---------: | :--------: |
| [5,2,7,6,3] | [1,1,3,3,3] | "FL 98763" |
| [4,7,4,7,4] | [0,1,2,3,1] | "FC 77774" |


<br>

## 입출력 예 설명

<br>

### 입출력 예 #1

1,2번 카드를 각각 9(shape:3), 8(shape:3) 으로 바꾼 98763 FL(플러쉬)가 만들 수 있는 가장 높은 조합입니다.


<br>

### 입출력 예 #2

숫자가 4인 카드 중 2개를 7로 바꾼 77774 FC(포카드)가 만들 수 있는 가장 높은 조합입니다.