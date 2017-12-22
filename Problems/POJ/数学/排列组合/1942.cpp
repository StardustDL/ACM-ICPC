/*
Paths on a Grid
��������׼C(n+m,m)��һ��С�Ż���C(n+m,min(n,m))
	  ���Ǳ����ᳬʱ�����ò�ֽ׳ˣ�����������ٳ���ǰ��������֮�������ַ�����һ��ѭ����OK�ˣ�ʱ�临�Ӷ�ֻ��O(n-m)���ǳ��ɹۡ�
	  ��ϸ�����룬C(5,2)=5!/(2!3!)=5/3*4/2*3/1
	  ע�⾫������ 
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<bitset>
using namespace std;
const int INF=0x3f3f3f3f,MAXN=1000;
typedef unsigned int UI;
UI C(UI n,UI m){
	double ans=1.0;
	while(m>0)ans*=(double)(n--)/(double)(m--);
	return (UI)(ans+0.5);//ǿ��ת������ȥ���ȼ�0.5��ʵ��4��5�� 
}
int main(){
	UI n,m;
	while(scanf("%u%u",&n,&m)&&(n!=0||m!=0))//n,m������һ��Ϊ0 
		printf("%u\n",C(n+m,min(n,m)));
	return 0;
}

