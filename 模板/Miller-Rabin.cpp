#include <iostream>   
#include <cstdio>   
#include <algorithm>    
#include <cmath>    
#include <cstring>    
#include <map>    
using namespace std;

const int times = 20;  
int number = 0;  
  
map<long long, int>m;  
long long Random( long long n )         //����[ 0 , n ]�������  
{  
    return ((double)rand( ) / RAND_MAX*n + 0.5);  
}  
  
long long q_mul( long long a, long long b, long long mod ) //���ټ��� (a*b) % mod  
{  
    long long ans = 0;  
    while(b)  
    {  
        if(b & 1)  
        {  
            b--;  
            ans =(ans+ a)%mod;  
        }  
        b /= 2;  
        a = (a + a) % mod;  
  
    }  
    return ans;  
}  
  
long long q_pow( long long a, long long b, long long mod ) //���ټ��� (a^b) % mod  
{  
    long long ans = 1;  
    while(b)  
    {  
        if(b & 1)  
        {  
            ans = q_mul( ans, a, mod );  
        }  
        b /= 2;  
        a = q_mul( a, a, mod );  
    }  
    return ans;  
}  
  
bool witness( long long a, long long n )//miller_rabin�㷨�ľ���  
{//�ü�������a������n�ǲ�������  
    long long tem = n - 1;  
    int j = 0;  
    while(tem % 2 == 0)  
    {  
        tem /= 2;  
        j++;  
    }  
    //��n-1���Ϊa^r * s  
  
    long long x = q_pow( a, tem, n ); //�õ�a^r mod n  
    if(x == 1 || x == n - 1) return true;   //����Ϊ1��Ϊ����  
    while(j--) //������������2���Ƿ�������� j  
    {  
        x = q_mul( x, x, n );  
        if(x == n - 1) return true;  
    }  
    return false;  
}  
  
bool miller_rabin( long long n )  //����n�Ƿ�������  
{  
  
    if(n == 2)  
        return true;  
    if(n < 2 || n % 2 == 0)  
        return false;               //�����2�������������<2������>2��ż����������  
  
    for(int i = 1; i <= times; i++)  //��times���������  
    {  
        long long a = Random( n - 2 ) + 1; //�õ������������ a  
        if(!witness( a, n ))                        //��a����n�Ƿ�������  
            return false;  
    }  
    return true;  
}  
  
  
int main( )  
{  
    long long tar;  
    cout<<rand()<<endl;
    cout<<RAND_MAX<<endl;
    cout<<Random( 100 - 2 )<<endl;
    cout<<Random( 100 - 2 )<<endl;
    while(cin >> tar)  
    {  
        if(miller_rabin( tar )) //����tar�ǲ�������  
            cout << "Yes, Prime!" << endl;  
        else  
            cout << "No, not prime.." << endl;  
    }  
    return 0;  
}  
