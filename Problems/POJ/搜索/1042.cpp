/*
Gone Fishing
���⣺John����h��Сʱ�Ŀ���ʱ�䣬������ȥ���㡣����ĵط�����n���������еĺ�����һ������·˳�����У�Johnÿ��һ�������������ֻ���ߵ���һ��������������John�����1�ź���ʼ���𣬵������������κ�һ�����������˴ε�����г̡�
	  ������5������Ϊ��λʱ�䣬John��ÿ������ÿ5���ӵ���������ʱ������������Եݼ���ÿ������ͷ5���ӿ��Ե�����������fi��ʾ��ÿ����������5���ӵ������ļ�������di��ʾ��John������һ�����ߵ�����һ������ʱ����ti��ʾ��
	  ��һ�ַ�����ʹ��John�����޵�hСʱ�п��Ե��������ܶ����
������������ע���һ���ǣ�Johnֻ����ǰ�ߣ����صĻ�ֻ������John��·�ϵ�ʱ�䣬��������������ʱ�䡣��˴�����ⲽ�����£�
	  1.ö��John���������һ������ÿ�������ȥ���貽�е�ʱ�䣬ʣ�µľ��ǵ����ʱ�䡣
	  2.ÿ5����ѡȡ���������ĺ����е��㣬ֱ��ʱ��ľ���
	  3.������ö�ٵ������ѡ������������������Ϊ��������Ž⡣
	  ������Ҫע��ļ������⣺
	  1.����ⲻΨһ��ѡ���ڵ�һ������ʱ���Ľ⣻����Ծɴ��ڲ�Ωһ�⣬ѡ���ڵڶ�������ʱ���Ľ⣬�Դ����ơ�
	  2.����ʱ������ӣ���ĳ�����еĵ��������ܻ���ָ�������ʱӦ���ú���ÿ��ʱ�䵥λ�ĵ���������Ϊ�㡣
	  3.�ڲ������ݻ�������еĹ����п��ܳ���ÿ��������ȫΪ0�������ע���ر���
	  4.ö��ʱ�������ı�־��ʣ��ʱ��<=0��
 	  ʵ�ʱ�д���鷳�����о��ǿ��˵�pojc++�汾������ ��Ҫ��g++ 
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct ss{
    friend bool operator<(const ss a,const ss b){
        if(a.sum<b.sum)return 1;
        else if(a.sum==b.sum&&a.num>b.num)return 1;
        else return 0;
    }
    int num,sum,d;
};
struct T{ 
    int sum,d;
}s[50];
int a[50],b[50],t[50];
int main(){
    int n,h;
    while(scanf("%d",&n)>0&&n){
        int tol=-10,tol1=0;
        memset(a,0,sizeof(a));
        scanf("%d",&h);
        h=h*12;
        for(int i=1;i<=n;i++){
            scanf("%d",&s[i].sum);
            if(s[i].sum<0)
            s[i].sum=0;
        }
        for(int i=1;i<=n;i++)
			scanf("%d",&s[i].d);
        t[0]=t[1]=0;
        for(int i=2;i<=n;i++)
			scanf("%d",&t[i]);
        for(int i=1;i<=n;i++){
            priority_queue<ss>q;
            int ht=h;
            tol1=0;
            memset(b,0,sizeof(b));
            for(int j=1;j<=i;j++){
                ss node=(ss){j,s[j].sum,s[j].d};
                ht=ht-t[j];
                if(node.sum>0)q.push(node);
            }
            while(!q.empty()&&ht>0){
                ss node=q.top();q.pop();
                tol1+=node.sum;
                node.sum-=node.d;
                b[node.num]++;
                ht--;
                if(node.sum>0)q.push(node);
            }
            if(tol1>=tol){
                if(tol1>tol){
                    tol=tol1;
                    if(ht>0)
                    b[1]+=ht;
                    for(int k=1;k<=n;k++)a[k]=b[k];
                }
                else{
                    if(ht>0)b[1]+=ht;
                    for(int k=1;k<=n;k++){
                        if(a[k]>b[k])break;
                        else if(a[k]<b[k]){
                            for(int j=1;j<=n;j++)a[j]=b[j];
                            break;
                        }
                    }
                }
            }
        }
        for(int i=1;i<n;i++)printf("%d, ",a[i]*5);
        printf("%d\n",a[n]*5);
        printf("Number of fish expected: %d\n\n",tol);
    }
    return 0;
} 
