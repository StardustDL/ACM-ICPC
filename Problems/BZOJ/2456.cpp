/*
mode
��������ÿ�����ͺ���һ��������ͬ���������������Ҫ����������˳���n div 2�Σ���ô���ʣ�µľ��Ǵ𰸡�
ע�⣺��Ҫ������ô��ͷ�ļ�����MLE 
*/
#include<cstdio>
using namespace std;
int n,t,ans=0,tme=0;
int main(){
	scanf("%d%d",&n,&t);
	ans=t;tme=1; 
	for(--n;n;n--){
		scanf("%d",&t);
		if(t==ans)tme++;
		else if(tme==0)ans=t,tme=1;
		else tme--;
	}
	printf("%d\n",ans);
	return 0;
}

