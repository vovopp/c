#include <stdio.h>
#include<string.h>
#define N 6
void swap(char *a, char *b)
{
	char temp[128];
	 
	strcpy(temp, a);
	strcpy(a, b);
	strcpy(b, temp);
}
void print(int n, char data[][128])
{
	int i;
	for(i=0; i<n; i++)
	{
	printf("%s ", data[i]);
	}
	printf("\n");
}
void bsort(char data[][128],int n)
{
	int i, j;
	for(i=n; i>1; i--)
	{
		for(j=0; j<i-1; j++)
		{
			if(strcmp(data[j+1],data[j]) > 0)
			{
				swap(data[j+1], data[j]);
			}			
		}
		print(n, data);
	}
} 
void ssort(char data[][128],int n)
{
	
	int i, j, pos;
	
	for(i=0; i<n-1; i++)
	{
	pos = i;
	for(j=i+1; j<n; j++) 
	{
		if(strcmp(data[j],data[pos]) > 0)
			pos = j;
	}
	
		swap(data[i], data[pos]);
		print(n, data);		
	} 
} 
void isort(char data[][128],int n)
{
		
	int i, j;
	char key[128]; 

	for( i=1; i<n; i++)
	{
	strcpy(key, data[i]);
	for(j=i-1; j>=0 && strcmp(data[j],key)<0; j--)
	{
	
		strcpy(data[j+1], data[j]);
	}
	strcpy(data[j+1], key);
	print(n, data);  
	}
}
int main(){
	char ary[N][128];
	int op;
	int i;
	
	for(i=0;i<N;i++)
		scanf("%s",ary[i]);
		
	scanf("%d",&op);	
	switch(op){
		case 1:
			bsort(ary,N);
			break;
		case 2:
			ssort(ary,N);
			break;
		case 3:
			isort(ary,N);
			break;	
	}
	print(N,ary);	
}