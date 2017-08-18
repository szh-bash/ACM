#include <stdio.h> 
int main(){
int a,b,c,t;
a=1;  
b=2;  
c=2;
while(a<b && b<c)
{
 t=a; a=b; b=t;
 c--;
}
printf("%d,%d,%d", a, b, c);
}
