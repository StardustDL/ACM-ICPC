/*
Dividing
���⣺�Ѽ�ֵΪ1��2��3��4��5��6�ı�ʯƽ���ֳ����ݣ������и��û�а취�ֿ���
���������ر�������ʵ���Ͽ���ͨ����֦�Ż�������01������˼·AC 
*/
#include<cstdio>
#include<cstring>
using namespace std;
int opt[60011],num[7],sum,total;
int main(){
	int kase=0;
	while(scanf("%d",&num[1])!=-1){
		sum=num[1];
		for(int i=2;i<=6;i++){scanf("%d",&num[i]);sum+=num[i]*i;}
		if(sum==0)break;
		kase++;
		if(sum&1){printf("Collection #%d:\nCan't be divided.\n\n",kase);continue;}
		total=sum/2;
		memset(opt,0,sizeof(opt));
		for(int k=0;k<=num[1]&&k<=total;k++)opt[k]=1;
		for(int i=2;i<=6;i++){
			for(int l=total;l>=0;l--){
				if(!opt[l])continue;
				for(int k=1;k<=num[i]&&k*i+l<=total;k++){
					if(opt[k*i+l])break;//��������Ĵ�һ���Ѿ�������� 
					opt[k*i+l]=1;
				}
			}
		}
		if(opt[total])printf("Collection #%d:\nCan be divided.\n\n",kase);
		else printf("Collection #%d:\nCan't be divided.\n\n",kase);
	}
	return 0;
}
