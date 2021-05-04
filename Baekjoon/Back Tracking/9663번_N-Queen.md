## 문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

## 입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

## 출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

## 풀이

```python
# n 입력
n = int(input())
row = [0] * n
answer = 0

def check(x):
    for i in range(x):
        # 열이 같은 경우 & 대각선에 놓인 경우
        if row[x] == row[i] or abs(row[x] - row[i]) == x - i:
            return False
    return True

def dfs(x):
    global answer

    if x == n:
        answer += 1
        
    else:
        for i in range(n):
            row[x] = i
            if check(x):
                dfs(x + 1)

dfs(0)
print(answer)
