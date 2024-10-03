#include<stdio.h>
#define PI 3.1415926
int main()
{
	int n,ans;//n坐标数，ans答案 
	double x,y,s;//x,y坐标,s面积 
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%lf %lf",&x,&y);
		s=(x*x+y*y)*PI/2;//以从原点到给出坐标为半径的半圆形的面积 
		ans=s/50+1; 
		printf("Property %d: This property will begin eroding in year %d.\n",i,ans);
    }
    printf("END OF OUTPUT.\n");
    return 0;
}
