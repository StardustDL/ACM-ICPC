/*
题意：某种卫星使用一种叫做“run length encoding”的方式来储存大尺寸图片，
	  有一种简单的 edge detection 算法 是将 图像中的每一个点的值与他周围的八个点相减，然后记录下绝对值最大的，上面的右图是左图经过这种算法转换之后的结果。
	  现在你的任务就是实现这个算法，输入的图片是以 run length encoding 的形式表示的，同时也要求转换后的图片也以 run length encoding 的形式表示。 
	  给出每一段相同颜色的长度（段数<=1000） 
分析：由于图片宽度可能为10^9，因此不能开数组，会MLE，又因为像素点很多，不能直接暴力，会TLE
	  突破点在于Input的pair，pair上限只有1000，数据量是最少的，因此只能利用这点去解题。
	  要利用pair，就必须懂得“跳跃式编码”，就是说只在像素发生变化的位置进行编码，而像素没有变化的位置则其编码值与其左边的像素一致。
	  先给所有像素点pix顺序标号pos，从1开始，以这个标号pos作为该像素点pix的索引
	  利用pos去模拟pix在二维图片的坐标row=(pos-1)/width，col=(pos-1)%width，这样就无需定义二维数组，仅仅虚构了一个二维数组，就解决了空间溢出MLE的问题
	  接下来在 像素发生变化的位置（下面称为“边界”）的地方 编码，每个连续段的起始格，都是要处理的格子，同时，每个要处理的格子，都是一个连续段起始格的周围8个格子中的一个。 
	  边界位置其实就是每对pair的个数决定的，对边界位置及其周遭共9个像素点编码，把编码结果及对应的索引pos都存放在OutMap，编码方法就是题目给出的算法
	  最后把OutMap中的编码值根据其索引值进行升序排序，依次读取OutMap中的编码值，当编码值code发生变化时，则用 变化后的编码索引 减去 变化前的编码索引，就是code在OutMap中出现的次数。
*/
#include<cstdio>
#include<cstring>
#include<cmath> 
#include<algorithm>
#define size 1005
using namespace std;
struct pix{
    int pos,code;    //表示答案中这个点的位置,这个点上的答案值
}outmap[size*8];
int inmap[size][2];//inmap[][0]表示这个连续段的数值，inmap[][1]表示这个连续段的长度
int width,cntp,tot;
int cmp(pix x,pix y){return x.pos<y.pos;}//排序比较函数，最后以pos升序排序
int getnum(int pos){//返回原图中pos位置上的数值
    int p=0,i=0;
    while(p<pos)p+=inmap[i++][1]; 
    return inmap[i-1][0];
}
int getcode(int pos){//计算pos位置上的答案
    int num=getnum(pos),ret=0;
    int row=(pos-1)/width,col=(pos-1)%width;
    for(int i=row-1;i<=row+1;i++)
        for(int j=col-1;j<=col+1;j++){
            int tpos=i*width+j;
            if (i<0||j<0||j>=width||tpos>=tot || tpos==pos-1)continue;//这里计算差的绝对值时要排除pos自己
            int tmp=getnum(tpos+1);
            if (abs(tmp-num)>ret)ret=abs(tmp-num);//更新ret
        }
    return ret;
}
int main(){
    while (scanf("%d",&width)&& width>0){
        int num,len;
        cntp=tot=0;//必须得每次都赋0
        while (scanf("%d%d",&num,&len)&& len>0){
            inmap[cntp][0]=num;
            inmap[cntp++][1]=len;
            tot+=len;//tot是map中像素的个数
        }
        printf("%d\n",width);//按照同样格式输出
        int pos=1,k=0;//pos从1开始标号
        for (int p=0;p<=cntp;p++){//枚举每一个连续段
            int row=(pos-1)/width;
            int col=(pos-1)%width;
            for (int i=row-1;i<=row+1;i++)
                for (int j=col-1;j<=col+1;j++){
                    int tpos=i*width+j;//这里算出来的tpos其实是tpos的标号减一
                    if (i<0 || j<0 || j>=width || tpos>=tot)continue;//tpos在map的外面了
                    outmap[k].pos=tpos+1;
                    outmap[k++].code=getcode(tpos+1);//答案存入outmap   
                }
            pos+=inmap[p][1];//跳跃到下一个连续段的起始格
        }
        sort(outmap,outmap+k,cmp);
        pix tmp=outmap[0];
        for (int i=0;i<k;i++){
            if (outmap[i].code==tmp.code)continue;//表明连续，则跳过不输出
            printf("%d %d\n",tmp.code,outmap[i].pos-tmp.pos);
            tmp=outmap[i];
        }
        printf("%d %d\n",tmp.code,tot-tmp.pos+1);//最后一部分
        printf("0 0\n");//按照格式输出
    }
    printf("0\n");//格式
    return 0;
}
