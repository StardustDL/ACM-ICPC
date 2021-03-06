/*
DNA 
题意： 一种病毒入侵了，病毒有两种DNA 111和101，人有L位的基因，也是由0和1组成。如果人的基因中有与病毒相同的串，则会被影响，问，给一个L，有多少中可能的基因组合不会受到影响。结果对2005取模。
分析：方法不错：第二个递推式要想一想 
		解法1：L的取值为10^8次方，显然数据很大，但结果对2005取模，说明可能有混环节。对前几项进行手工运算找规律。 
		1 —> 2 1*2 2 —> 4 2*2 
		3 —> 6 2*3 4 —> 9 3*3 
		5 —> 15 3*5 6 —> 25 5*5 
		7 —> 40 5*8 8 —> 64 8*8 
		9 —> 104 8*13 10 —> 169 13*13 
		可以看出为斐波拉契数列：1 2 3 5 8 13 21 。然后找循环节。
		for(i=2;i<10000;i++)
	    {
	        f[i]=(f[i-1]+f[i-2])%2005;
	        if(f[i]==2&&f[i-1]==1) break;
	    } 
	    circle=i-1 
		解法2：找规律：f[n]=f[n-1]+f[n-3]+f[n-4]；然后在找循环节。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int f[220];
int main(){
    int n,i;
    f[0]=1;
    f[1]=2;
    for(i=2;i<210;i++)f[i] = (f[i-1] + f[i-2])%2005;//知道循环点在200处，故打表210就够了
    while(~scanf("%d",&n))
        printf("%d\n",(f[(n/2+n%2)%200]*f[n/2%200])%2005);//利用找到的规律以及mod的性质求解
    return 0;
}
