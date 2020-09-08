import os
n = int(input())
p = []
flag = []
size = []
zs = [False]
pro = [[]]
ans = [1]
s = input().split()

for i in range(n):
    p.append(int(s[i])-1),
    flag.append(False)
    zs.append(True)
    pro.append([])
    ans.append(1)
for i in range(2, n+1):
    if zs[i]==False : continue
    pro[i].append(i)
    for j in range(2,n//i+1):
        if i*j>n: break
        zs[i*j] = False
        pro[i*j].append(i)

# get_size
for i in range(n):
    if flag[i]==True: continue
    flag[i] = True
    j = p[i]
    temp = 1
    while flag[j]==False:
        flag[j] = True
        temp += 1
        j = p[j]
    size.append(temp)
size.sort()

# calc lcm
for i in range(len(size)):
    if i==0 or size[i]!=size[i-1]:
        x = u = size[i]
        for j in range(len(pro[u])):
            tmp = 0
            v = pro[u][j]
            w = 1
            while (x%v)==0:
                x //= v
                tmp += 1
                w *= v
            ans[v]=max(ans[v],w)
res = 1
for i in range(n+1):
    if ans[i]==1: continue
    res *= ans[i]
print(res)