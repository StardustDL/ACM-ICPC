/*
[HNOI2006]������
������������ʵ�й��ɡ���������̽��кڰ�Ⱦɫ����Ȼ��������ֻ���ߵ��������ɫ�ĵ㣬ż����ֻ���ߵ�ͬɫ�㡣
		������x������ô�յ㵽���������پ���Ӧ<=3x����������յ�ĺ�����֮����������֮�Ӧ<=2x��
		��ôһ·ö����ȥ���ɡ�
		���Ƕ���5*5��ͼ�У������������ļ�����ȴ��Ҫ3-4���������ö���л�����õ�1��2��
		����һ�¼��� 
	  ���߿��Դ�Χ̰�ģ�С��Χbfs 
*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath> 
using namespace std;
const int MAXN=1000,INF=0x3f3f3f3f;
int xp,yp,xs,ys,d,a,b,ans=0; 
int main(){
	scanf("%d%d%d%d",&xp,&yp,&xs,&ys);
	d=(a=abs(xp-xs))+(b=abs(yp-ys));
	for(ans=0;;ans++){
		if(((xp+yp&1)^(xs+ys&1))!=(ans&1))continue;//�жϵ����ɫ�ܷ��ߵ� 
		if(d<=ans*3&&a<=ans*2&&b<=ans*2)break;
	}
	//cout<<ans<<endl;
	if(d==1)ans=3;
	else if(d==4&&a==2&&b==2)ans=4;
	printf("%d\n",ans); 
	return 0;
}

