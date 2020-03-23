// a sequence of stones with a number >0 written on it are there
// a frog steps on first stone and can jump max to the number written on the standing stone
// find the least number of jumps required and its path, if frog jumps further than the last stone then its ok
// jumping from initial pos to first step counts as 1st step taken

#include<stdio.h>
int main()
{ 
	int a[100],i,n,pre,l,val,count=1;
	printf("Number of stones present?\n");   
	scanf("%d",&n);
	printf("\nEnter the numbers written on the stone\n");  
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	pre=a[0];  // intial stone num // pos where frog is currently present
	l=a[pre];  // max possible jump allowed 
	count++;
	i=0;
	printf("%d-->%d-->",a[0],a[pre]);
	while(1)
	{
		// finding the max number between the next step and max possible jump allowed
		for(i=pre;i<pre+l;i++)
		{
			if(a[i]>a[i+1])
				val=a[i];
			else
				val=a[i+1];
		}
		printf("%d-->",val);  // val is the stone with the largest num on it on which frog can jump
		count++;
		l=val;
		pre=pre+l;
		if(pre+l>n)
			break;
	}
	printf("%d\n",a[n-1]);
	printf("The minimum number of jumps required are %d",count);
	return 0;
}
