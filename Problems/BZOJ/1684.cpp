/*
[Usaco2005 Oct]Close Encounter
������ע���ĸ��С��ö�ټ��� 
*/
#include<cstdio>
#include<cmath>
int a,b,ans1,ans2;
double delta=1e10;
void check(int x,int y){
    if(x*b==y*a)return;//������ȣ���С������� 
    double d=fabs((double)x/y-(double)a/b);
    if(d<delta)delta=d,ans1=x,ans2=y;
}
int main(){
    scanf("%d%d",&a,&b);
    for(int j=1;j<=32767;j++){
    	int i=(int)floor((double)a/b*j);
    	check(i,j);check(i+1,j);
	}
    printf("%d %d\n",ans1,ans2);
    return 0;
}
