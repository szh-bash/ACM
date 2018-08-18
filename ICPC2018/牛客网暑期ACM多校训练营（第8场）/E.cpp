#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}
/*
#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}#include <map>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
typedef unsigned long long ull;
typedef long long ll;
using namespace std;
int n, m, k;
int read(){
    int p=0, q=1;
    char ch=getchar();
    while (ch<'0' || ch>'9')
        (ch=='-'?q=-1:0),
        ch=getchar();
    while (ch>='0' && ch<='9') p=p*10+ch-'0', ch=getchar();
    return p*q;
}
int main(){
	for (int _=read();_;_--){
		n=read();m=read();k=read();
		int flag=1;
		for (int i=1;i<=k;i++){
			int u1=read(), v1=read(), u2=read(), v2=read();
			if (u1==u2 && v1==v2) continue;
			if (((u1+v1)&1)==((u2+v2)&1) && ((u1+v1)&1)==0) flag=0;
		}
		if (!(n&1) || !(m&1)) flag=0;
		cout<<n*m+flag<<endl;
	}
    return 0;
}
*/
