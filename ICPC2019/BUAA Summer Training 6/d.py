def exgcd(a, b):
    if b==0:
        return 1, 0, a
    x, y, d = exgcd(b, a%b)
    t = x
    x = y
    y = t-a//b*y
    return x, y, d 

def check(i, j):
    x, y, d = exgcd(a[i], a[j])
    if (b[i]-b[j])%d != 0:
        return 1
    return 0

n, m=input().split()
n = int(n)
m = int(m)
# print(n**100)
a, b=[0], [0]
for i in range(1, n+1):
    x, y=input().split()
    x = int(x)
    y = int(y)
    a.append(x)
    b.append(y)
# print(a)
for i in range(1, n+1):
    for j in range(i+1,n+1):
        if check(i,j):
            print("he was definitely lying")
            exit (0)
k=a[1]
r=b[1]
for i in range(2, n+1):
    x, y, d = exgcd(k, a[i])
    x=(x*(b[i]-r)//d+a[i]//d)%(a[i]//d)
    y=k//d*a[i]
    # print(k, r, x, y)
    r=(x*k+r)%y
    k=y
if r>m :
    print("he was probably lying")
else:
    print(r)
        
