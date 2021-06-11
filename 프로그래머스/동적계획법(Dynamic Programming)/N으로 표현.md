## 문제 설명
아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

## 제한사항
- N은 1 이상 9 이하입니다.
- number는 1 이상 32,000 이하입니다.
- 수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
- 최솟값이 8보다 크면 -1을 return 합니다.

## 입출력 예
|N|number|return|
|--|--|--|
|5|12|4|
|2|11|3|

## 입출력 예 설명
#### 예제 #1
문제에 나온 예와 같습니다.

#### 예제 #2
`11 = 22 / 2`와 같이 2를 3번만 사용하여 표현할 수 있습니다.

## 풀이
1. calculation 메소드에서 더하기, 빼기, 곱하기, 나누기, 숫자 붙이기 5가지를 최대 8회 진행한다.
2. 8회가 되기 전에 number와 현재 숫자가 같게 되면 재귀를 멈추고 answer와 count를 비교하여 더 작은 값을 answer로 한다.
3. 모든 경우의 수를 다 진행했는데 answer가 갱신이 되지 않으면 answer = -1로 한다.

```java
class Solution {
    public static int answer = 9;
    public static void calculation(int N, int number, int now, int count) {
        //count가 8을 넘을 때 재귀 종료
        if(count > 8) {
            return;
        }
        //현재 숫자가 number와 같을 때 재귀 종료
        if(now == number) {
            answer = Math.min(answer, count);
            return;
        }

        //temp : 사칙연산 없이 이어지는 숫자(n*10+n)를 표현하기 위함
        int temp = N;
        for(int i = 0; i < 8 - count; i++) {
            calculation(N, number, now + temp, count + i + 1);
            calculation(N, number, now - temp, count + i + 1);
            calculation(N, number, now * temp, count + i + 1);
            calculation(N, number, now / temp, count + i + 1);
            temp = temp * 10 + N;
        }
    }

    public static int solution(int N, int number) {
        calculation(N, number, 0, 0);
        if(answer == 9) {
            answer = -1;
        }
        return answer;
    }
}
```
