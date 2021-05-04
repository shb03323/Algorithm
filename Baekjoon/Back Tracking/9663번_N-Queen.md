## 문제
N-Queen 문제는 크기가 N × N인 체스판 위에 퀸 N개를 서로 공격할 수 없게 놓는 문제이다.

N이 주어졌을 때, 퀸을 놓는 방법의 수를 구하는 프로그램을 작성하시오.

## 입력
첫째 줄에 N이 주어진다. (1 ≤ N < 15)

## 출력
첫째 줄에 퀸 N개를 서로 공격할 수 없게 놓는 경우의 수를 출력한다.

## 풀이
1. 한 행에 하나의 퀸이 놓일수 밖에 없으므로 2차원 배열을 쓸 필요없이 열의 배열(row)만 쓴다.
2. check 함수로 이전 열의 퀸들과 현재 퀸이 서로 공격할 수 없는지 확인한다.
3. dfs 함수로 첫번째 열부터 마지막 열까지 check가 True로 return되면 그것이 하나의 경우이므로 answer에 1씩 추가한다.
4. 최종적으로 추출되는 answer가 모든 경우의 수이다.

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
