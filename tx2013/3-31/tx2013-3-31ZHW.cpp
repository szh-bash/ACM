#include <iostream>
using namespace std;
int b[10],a[10][100005],f[100],i,j,A,B,n;
int main()
{
    a[3][++b[3]]=1;
    // kdjalfj kadsjfkjadks
    a[4][++b[4]]=0;
    a[3][++b[3]]=2;
    a[5][++b[5]]=3;
    a[4][++b[4]]=4;
    a[4][++b[4]]=5;
    /*
       dklafjkdsjfdasjfkl
       dasfjkaj
    dasfkjfklas
    ahdksfda
          dfkajd
          */
    a[3][++b[3]]=6;
    a[5][++b[5]]=7;
    a[5][++b[5]]=8;
    a[4][++b[4]]=9;
    a[3][++b[3]]=10;
    a[6][++b[6]]=11;
    a[6][++b[6]]=12;
    a[8][++b[8]]=13;
    a[8][++b[8]]=14;
    a[7][++b[7]]=15;
    a[7][++b[7]]=16;
    /*
     dkasjf
       jwerjiqje  waetaerhy3w124124awet
        kdsjasdas
     asdhfkajlfaw
     */
    a[9][++b[9]]=17;
    a[8][++b[8]]=18;
    a[8][++b[8]]=19;
    a[6][++b[6]]=20;
    // klajufeiwrujqwkjdkasf
    f[1]=3; f[2]=3; f[3]=5; f[4]=4; f[5]=4; f[6]=3; f[7]=5; f[8]=5; f[9]=4;
    f[20]=6; f[30]=6; f[40]=5; f[50]=5; f[60]=5; f[70]=7; f[80]=6; f[90]=6;
    for (i=21; i<=99; i++)
      if (f[i% 10]+f[i-i%10]<=9)  /kasjfkasdj   waetaweg sdckjew523e
        a[f[i%10]+f[i-i%10]][++b[f[i%10]+f[i-i%10]]]=i;
    cin>>n;
    for (i=1; i<=n; i++)
    {
        cin>>A>>B;
        cout<<"Case #"<<i<<": ";
        if (A==4 && B==1) {cout<<0<<endl; continue;}
        if (A!=9 && a[A][B]==0) {cout<<-1<<endl; continue;}
        if (a[A][B]!=0) {cout<<a[A][B]<<endl; continue;}
        /*
         dkjafjkasfjlas  weagya214fhdfnh
            dkfjqwejrtiaetdfhdhae
            asdfcjkasjca
    dasfksdjflds
    */
        if (b[9]+4<B) {cout<<-1<<endl; continue;}
        if (b[9]+1==B) cout<<1;  
        if (b[9]+2==B) cout<<2;
        if (b[9]+3==B) cout<<6;
        if (b[9]+4==B) cout<<10;
/*
 dskafjlexfdfhsdfhxnwf  asdfawet
    dafjjfqeiwruiovfjsdfv
    */
        for (j=1; j<=100; j++) cout<<0;
        cout<<endl;
    } 
    return 0;
}