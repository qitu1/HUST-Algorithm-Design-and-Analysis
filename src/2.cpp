#include<stdio.h>
#define PI 3.1415926
int main()
{
	int n,ans;//n��������ans�� 
	double x,y,s;//x,y����,s��� 
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf %lf",&x,&y);
		s=(x*x+y*y)*PI/2;//�Դ�ԭ�㵽��������Ϊ�뾶�İ�Բ�ε���� 
		ans=s/50+1; 
		printf("Property %d: This property will begin eroding in year %d.\n",i,ans);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
