/*
���⣺ĳ������ʹ��һ�ֽ�����run length encoding���ķ�ʽ�������ߴ�ͼƬ��
	  ��һ�ּ򵥵� edge detection �㷨 �ǽ� ͼ���е�ÿһ�����ֵ������Χ�İ˸��������Ȼ���¼�¾���ֵ���ģ��������ͼ����ͼ���������㷨ת��֮��Ľ����
	  ��������������ʵ������㷨�������ͼƬ���� run length encoding ����ʽ��ʾ�ģ�ͬʱҲҪ��ת�����ͼƬҲ�� run length encoding ����ʽ��ʾ�� 
	  ����ÿһ����ͬ��ɫ�ĳ��ȣ�����<=1000�� 
����������ͼƬ��ȿ���Ϊ10^9����˲��ܿ����飬��MLE������Ϊ���ص�ܶ࣬����ֱ�ӱ�������TLE
	  ͻ�Ƶ�����Input��pair��pair����ֻ��1000�������������ٵģ����ֻ���������ȥ���⡣
	  Ҫ����pair���ͱ��붮�á���Ծʽ���롱������˵ֻ�����ط����仯��λ�ý��б��룬������û�б仯��λ���������ֵ������ߵ�����һ�¡�
	  �ȸ��������ص�pix˳����pos����1��ʼ����������pos��Ϊ�����ص�pix������
	  ����posȥģ��pix�ڶ�άͼƬ������row=(pos-1)/width��col=(pos-1)%width�����������趨���ά���飬�����鹹��һ����ά���飬�ͽ���˿ռ����MLE������
	  �������� ���ط����仯��λ�ã������Ϊ���߽硱���ĵط� ���룬ÿ�������ε���ʼ�񣬶���Ҫ����ĸ��ӣ�ͬʱ��ÿ��Ҫ����ĸ��ӣ�����һ����������ʼ�����Χ8�������е�һ���� 
	  �߽�λ����ʵ����ÿ��pair�ĸ��������ģ��Ա߽�λ�ü������⹲9�����ص���룬�ѱ���������Ӧ������pos�������OutMap�����뷽��������Ŀ�������㷨
	  ����OutMap�еı���ֵ����������ֵ���������������ζ�ȡOutMap�еı���ֵ��������ֵcode�����仯ʱ������ �仯��ı������� ��ȥ �仯ǰ�ı�������������code��OutMap�г��ֵĴ�����
*/
#include<cstdio>
#include<cstring>
#include<cmath> 
#include<algorithm>
#define size 1005
using namespace std;
struct pix{
    int pos,code;    //��ʾ����������λ��,������ϵĴ�ֵ
}outmap[size*8];
int inmap[size][2];//inmap[][0]��ʾ��������ε���ֵ��inmap[][1]��ʾ��������εĳ���
int width,cntp,tot;
int cmp(pix x,pix y){return x.pos<y.pos;}//����ȽϺ����������pos��������
int getnum(int pos){//����ԭͼ��posλ���ϵ���ֵ
    int p=0,i=0;
    while(p<pos)p+=inmap[i++][1]; 
    return inmap[i-1][0];
}
int getcode(int pos){//����posλ���ϵĴ�
    int num=getnum(pos),ret=0;
    int row=(pos-1)/width,col=(pos-1)%width;
    for(int i=row-1;i<=row+1;i++)
        for(int j=col-1;j<=col+1;j++){
            int tpos=i*width+j;
            if (i<0||j<0||j>=width||tpos>=tot || tpos==pos-1)continue;//��������ľ���ֵʱҪ�ų�pos�Լ�
            int tmp=getnum(tpos+1);
            if (abs(tmp-num)>ret)ret=abs(tmp-num);//����ret
        }
    return ret;
}
int main(){
    while (scanf("%d",&width)&& width>0){
        int num,len;
        cntp=tot=0;//�����ÿ�ζ���0
        while (scanf("%d%d",&num,&len)&& len>0){
            inmap[cntp][0]=num;
            inmap[cntp++][1]=len;
            tot+=len;//tot��map�����صĸ���
        }
        printf("%d\n",width);//����ͬ����ʽ���
        int pos=1,k=0;//pos��1��ʼ���
        for (int p=0;p<=cntp;p++){//ö��ÿһ��������
            int row=(pos-1)/width;
            int col=(pos-1)%width;
            for (int i=row-1;i<=row+1;i++)
                for (int j=col-1;j<=col+1;j++){
                    int tpos=i*width+j;//�����������tpos��ʵ��tpos�ı�ż�һ
                    if (i<0 || j<0 || j>=width || tpos>=tot)continue;//tpos��map��������
                    outmap[k].pos=tpos+1;
                    outmap[k++].code=getcode(tpos+1);//�𰸴���outmap   
                }
            pos+=inmap[p][1];//��Ծ����һ�������ε���ʼ��
        }
        sort(outmap,outmap+k,cmp);
        pix tmp=outmap[0];
        for (int i=0;i<k;i++){
            if (outmap[i].code==tmp.code)continue;//���������������������
            printf("%d %d\n",tmp.code,outmap[i].pos-tmp.pos);
            tmp=outmap[i];
        }
        printf("%d %d\n",tmp.code,tot-tmp.pos+1);//���һ����
        printf("0 0\n");//���ո�ʽ���
    }
    printf("0\n");//��ʽ
    return 0;
}
