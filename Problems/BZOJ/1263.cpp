/*
[SCOI2006]��������
���������ǵĹ���𰸣��߾��ȣ�
	  ���ۣ�
		���n��3�ı��� ��ô��n���ֳ�n/3��3�����ŵ�
		���n��3�ı���+1 ��ô��n���ֳ�(n-4)/3��3������2�����ŵ�
		���n��3�ı���+2 ��ô��n���ֳ�(n-2)/3��3��1��2�����ŵ�
	  ֤���� 
		���ǲ��ǻ��ֳ����������ǻ��ֳ�����ʵ��
		�����ǽ�n���ֳ���x����ʵ��֮��
		��֪����x�������ʱ�������ŵ�
		��ôÿ��������n/x������(n/x)^x
		��y=(n/x)^x
		����lny=x[ln(n)-ln(x)]
		�����󵼿ɵ�y'=(n/x)^x * ( ln(n) - ln(x) - 1 )
		��x=n/eʱy��ȡ0 ��ʱ�˻����
		���ÿ����Ҫ��������e����ʹ�����
		���ڿ������� ��e�����������3 ���Ҫ��n�����ֳ�3 �������2���� �������Ա�֤�����ŵġ� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int R=10;
struct bign{
	int d[5000+3],len;
	bign(){len=1;memset(d,0,sizeof(d));}
	void operator *=(int num){
		for(int i=0;i<len;i++)d[i]*=num;
		for(int i=0;i<len;i++){
			if(d[i]>=R){
				d[i+1]+=d[i]/R;d[i]%=R;
				if(i==len-1)len++;
			}
		}
	}
	void output(){
		printf("%d\n",len);
		for(int i=len-1;i>=0&&i>=len-100;i--)printf("%d",d[i]);
	}
}ans;
int n;
int main(){
	scanf("%d",&n);
	ans.d[0]=1;
	switch(n%3){
		case 0:
			for(int i=3;i<=n;i+=3)ans*=3;
			break;
		case 1:
			for(int i=3+4;i<=n;i+=3)ans*=3;
			ans*=4;
			break;
		case 2:
			for(int i=3+2;i<=n;i+=3)ans*=3;
			ans*=2;
			break;
	}
	ans.output();
	return 0;
}

