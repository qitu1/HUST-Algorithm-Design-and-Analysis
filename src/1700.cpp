#include <stdio.h>
#define N 1001
int t[N];
void Init(int n)
{
    for(int i=1;i<=n;i++){
        scanf("%d",&t[i]);
    }
    return ;
}
int max(int a,int b)
{
    return a<b?b:a;
}
int min(int a,int b)
{
    return  a>b?b:a;
}
void quick_Sort(int array[],int left,int right)
{
    int i=left,j=right,temp;
    int pivot=array[(i+j)/2];
    while (i<=j)
    {
        while(array[i]<pivot)  i++;
        while(array[j]>pivot)  j--;
        if (i<=j)
        {
            temp=array[i];
            array[i]=array[j];
            array[j]=temp;
            i++;
            j--;
        }
    }
    if(i<right) quick_Sort(array,i,right);
    if(left<j)  quick_Sort(array,left,j);
}
int solve(int n)
{
   int sum=0;
   while (n>=4){
       sum+=min(t[n]+2*t[2]+t[1],t[n]+t[n-1]+2*t[1]);
       n-=2;
   }
   if(n==3)  sum+=t[1]+t[2]+t[3];
   if(n==2)  sum+=t[2];
   return sum;
}
int main()
{
    int T,n;
    scanf("%d",&T);
    while (T--){
        scanf("%d",&n);
        Init(n);
        if(n==1){
            printf("%d\n",t[1]);
        }
        else if(n==2){
            printf("%d\n",max(t[1],t[2]));
        }
        else if(n==3){
            printf("%d\n",t[1]+t[2]+t[3]);
        }
        else{
            quick_Sort(t,1,n);
            printf("%d\n",solve(n));
        }
    }
    return 0;
}

