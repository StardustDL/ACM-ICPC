/*
Gone Fishing
题意：John现有h个小时的空闲时间，他打算去钓鱼。钓鱼的地方共有n个湖，所有的湖沿着一条单向路顺序排列（John每在一个湖钓完鱼后，他只能走到下一个湖继续钓），John必须从1号湖开始钓起，但是他可以在任何一个湖结束他此次钓鱼的行程。
	  此题以5分钟作为单位时间，John在每个湖中每5分钟钓的鱼数随时间的增长而线性递减。每个湖中头5分钟可以钓到的鱼数用fi表示，每个湖中相邻5分钟钓鱼数的减少量用di表示，John从任意一个湖走到它下一个湖的时间用ti表示。
	  求一种方案，使得John在有限的h小时中可以钓到尽可能多的鱼
分析：首先须注意的一点是，John只能向前走，返回的话只会增加John在路上的时间，因而减少他钓鱼的时间。因此此题解题步骤如下：
	  1.枚举John经过的最后一个湖，每种情况减去所需步行的时间，剩下的就是钓鱼的时间。
	  2.每5分钟选取钓鱼量最多的湖进行钓鱼，直到时间耗尽。
	  3.在所有枚举的情况中选择钓鱼量最多的情况，即为问题的最优解。
	  此题需要注意的几个问题：
	  1.如果解不唯一，选择在第一个湖耗时最多的解；如果仍旧存在不惟一解，选择在第二个湖耗时最多的解，以此类推。
	  2.随着时间的增加，在某个湖中的钓鱼数可能会出现负数，此时应将该湖中每个时间单位的钓鱼数更新为零。
	  3.在测试数据或程序运行的过程中可能出现每个湖鱼数全为0的情况，注意特别处理。
	  4.枚举时，结束的标志是剩余时间<=0。
 	  实际编写咯麻烦，还有就是坑人的pojc++版本。。。 非要用g++ 
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
