已知: $a+b=n$，求最小化 $lcm(a,b)$

令 $d=gcd(a,b), m=lcm(a,b)$

由 $\ a\times b=d\times m,\ d|n$

得到 $$m=\frac{a\times b}{d}=d\times a'\times b',\ a'+b'=\frac{n}{d}$$

固定 $d$，最小化 $m$ 得 $$a'=1, b'=\frac{n}{d}-1$$

进而 $$m=d\times b'=d\times(\frac{n}{d}-1)=n-d$$ $$b'=\frac{n}{d}-1>0\Rightarrow d<n$$

此时最大化 $d|n$ 且 $d<n$ 可得 $m$ 最小值。

综上$$m=n-\argmax_{d<n} d|n$$