/*
I Think I Need a Houseboat
���⣺������ (0,0) ��ʼ���԰�ԲΪ��״ÿ����ʴ50m^2����(0,0)��ʼ��(x,y)������Ҫ�೤ʱ��
��������r^2 ÿ������100�����ڸ��������꣬��Բ�ĵľ���ƽ��Ϊ d=x*x + y*y�������d /100����Ϊd�������ĳ���뾶������   ��d /100���һ����һ����С��������������Ϊn.m����˵���������ڵ�n�����ʱ��û����ʴ������n+1��ʱ�ᱻ��ʴ�� 
*/
#include<cstdio>
#include<cmath>
int main(){
	int n;
	float pi,x,y,years;
	scanf("%d",&n);
	pi=acos(-1.0);
	for(int i=1;i<=n;i++){
		scanf("%f%f",&x,&y);
	    years = pi*(x*x+y*y)/100;
	    printf("Property %d: This property will begin eroding in year %d.\n",i,(int)years+1);
	}
	printf("END OF OUTPUT.\n");
    return 0;
}

