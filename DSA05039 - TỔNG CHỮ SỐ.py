import sys

MAXN = 102
MAXM = 10004
INF = 1e100

dp = [[INF] * MAXM for _ in range(MAXN)]

def solve():
    for i in range(101):
        for j in range(10001):
            dp[i][j] = INF

    dp[0][0] = 0

    for i in range(1, 101):
        for j in range(1, 10001):
            for d in range(1, 10):
                if i - d >= 0 and j - d * d >= 0 and dp[i - d][j - d * d] != INF:
                    dp[i][j] = min(dp[i][j], dp[i - d][j - d * d] * 10 + d)

def main():

    solve()
    
    tc = int(input())
    for _ in range(tc):
        n, m = map(int, input().split())
        print(-1 if dp[n][m] == INF else dp[n][m])

main()