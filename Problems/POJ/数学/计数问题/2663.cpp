/*
Tri Tiling
���⣺����1*2��С���Σ�ȥƴ��һ��3*n��n<30���ľ��Σ����ж����ַ����� 
������nΪ�����϶�Ϊ0��nΪż����ÿ�ζ��Ǽ����У����ǰ����п�Ϊһ�У������һ����ǰ��ֿ���ֻ�����ַ�����3*a[n-2],�����һ�в���ǰ��ķֿ�����ô���ɷֽ���ζ�ֻ�������������Ϊ2*��a[n-4]+a[n-6]+����a[0])
	  ����Ϊa[n]=4*a[n-2]-a[n-4]
	  ������ô���ã�û��̫�� 
*/
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef long long LL; 
LL a[31],n;
int main(){
    a[0]=1;a[2]=3;
    for(int i=4;i<=30;i+=2)a[i]=4*a[i-2]-a[i-4];
    while(scanf("%lld",&n),n!=-1)printf("%lld\n",a[n]);
}


