# question
#GIVEN
#  a rod of length n meters,a price distribution array 
#  example - 5 meter is sold for 13, 2 meter for 9....
 
#TASK
#  write a program which tells how to cut that n meter rod to gain maximum profit




#include<stdio.h>
#include<conio.h>
void sort(float pbyl[100],int length[100],int price[100],int m);
int pricevalue(int length[100],int price[100],int m,int n);
void main()
{
	int i,ans,n,m,length[100],price[100];
	float pbyl[100];
//pbyl is price per unit length, highest pbyl is best
	scanf("%d%d",&n,&m);
//	printf("length values\n\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&length[i]);
	}
//	printf("price values\n\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&price[i]);
		pbyl[i] = (float)price[i]/(float)length[i];
	}
	sort(pbyl,length,price,m);

//pbyl[0] is the best way to have more value,pbyl[1] is the 2nd most best way...
	ans=pricevalue(length,price,m,n);
	printf("the total price is %d \n",ans);
	getch();
}
void sort(float pbyl[100],int length[100],int price[100],int m)
{
	int i,j,t1,t2;
	float t;
	for(i=0;i<m;i++)
	{
		for(j=0;j<m-i;j++)
		{
			if (pbyl[j]<pbyl[j+1])
			{
				t=pbyl[j];
				pbyl[j]=pbyl[j+1];
				pbyl[j+1]=t;

				t1=price[j];
				price[j]=price[j+1];
				price[j+1]=t1;

				t2=length[j];
				length[j]=length[j+1];
				length[j+1]=t2;
			}
		}
	}
}

int pricevalue(int length[100],int price[100],int m,int n)
{
	int i,answer=0;
	for(i=0;i<m;i++)
	{
		while(n>=length[i])
		{
			n=n-length[i];
			answer=answer+ price[i];
		}
	}
	return answer;
}
