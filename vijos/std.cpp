#include <stdio.h>
#include <string.h>
#include<iostream>
int dp[13][4096];
int count[4096];      //��¼ÿһ��״̬��1�ĸ���
char legal[4096];    //��¼ÿһ��״̬�Ƿ�Ϸ�
int len[13];              //��¼ÿһ���ж��ٸ���С��n
int pow4[13],pow5[13],pow2[31];    //Ϊ�˱�����c��pow����
int n;
int main()
{
int i,j,k,step;
int sum=0;
memset(legal,1,4096);
for(i=1;i<4096;i++)    //Ԥ����legal��count
{
   int flag=0,temp=i;
   count[i]=count[i>>1]+(i%2==1);
   while(temp!=0)
   {
    if(temp%2)
    {
     if(flag)
     {
      legal[i]=0;
      break;
     }
     else
     {
      flag=1;
     }
    }
    else
     flag=0;
    temp>>=1;
   } 
}
pow4[0]=pow5[0]=pow2[0]=1;
for(i=1;i<13;i++)
{
   pow4[i]=pow4[i-1]*4;
   pow5[i]=pow5[i-1]*5;
}
for(i=1;i<31;i++)
{
   pow2[i]=pow2[i-1]*2;
}
scanf("%d",&n);
for(i=0;i<13;i++)    //Ԥ����len
{
   for(j=0;j<11;j++)
   {
    if(pow4[i]*pow5[j]>n)
    {
     len[i]=j;
     break;
    }
   }
   if(len[i]==0)
   {
    step=i;
    break;
   }
}
for(i=0;i<pow2[len[0]];i++)    //�߽�����
{
   if(legal[i])dp[0][i]=1;
}
for(i=1;i<step;i++)    //״̬ת��
{
   for(j=0;j<pow2[len[i]];j++)
   {
    if(!legal[j])continue;
    dp[i][j]=0;
    for(k=0;k<pow2[len[i-1]];k++)
    {
     if(!legal[k])continue;
     if((j&k)==0)
     {
      dp[i][j]+=dp[i-1][k];
      dp[i][j]%=100000000;
     }
    }
   }
}
for(i=0;i<pow2[len[step-1]];i++)    //ͳ�ƽ��
{
   sum+=dp[step-1][i];
   sum%=100000000;
}
printf("%d\n",sum);
system("pause");
return(0);
}
