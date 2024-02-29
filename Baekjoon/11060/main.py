from collections import deque
import sys
 
def solve(arr):
    n = len(arr)
    vis = [False]*n
    q = deque()
    q.append((0, 0))
    vis[0] = True
    
    while q:
        cur, cnt = q.popleft()
        
        if cur == n-1:
            return cnt
        
        for i in range(1, arr[cur]+1):
            if cur+i >= n:
                continue
            if vis[cur+i]:
                continue
            q.append((cur+i, cnt+1))
            vis[cur+i] = True
    return -1
 
 
n = int(input())
arr = list(map(int, input().split()))
 
print(solve(arr))