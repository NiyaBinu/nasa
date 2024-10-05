#include <stdio.h>
struct poly{
	float coeff;
	int exp;
	}p1[10],p2[10],p3[10];

	

int readPoly(struct poly p1[], struct poly p2[],int t1,int t2)
{
	int i,j;
	
	printf("\n enter the no of terms in polynomial");
    scanf("%d",&t1);
    printf("\nenter coefficients and exponents in the descendin gorder\n");
    printf("struct1\n");
	for(i=0;i<t1;i++)
	{
	printf("Enter the coefficient  :  ");
	scanf("%f",&p1[i].coeff);
	printf("Enter the exponential  :  ");
	scanf("%d",&p1[i].exp);	
	}

	
	printf("struct2\n");
	for(j=0;j<t2;j++)
	{
	printf("Enter the coefficient  :  ");
	scanf("%f",&p2[j].coeff);
	printf("Enter the exponential  :  ");
	scanf("%d",&p2[j].exp);
	}
}

int addPoly(struct poly p1[10], struct poly p2[10],struct poly p3[10],int t1,int t2)
{
	int i=0,j=0,k=0;
	while(i<t1 && j<t2)
	{
			if (p1[i].exp==p2[j].exp)
			{
				p3[k].coeff=p1[i].coeff+p2[j].coeff;
				p3[k].exp=p1[i].exp;
				i++;
				k++;
				j++;
			}
			
			else if (p1[i].exp>p2[j].exp)
			{
				p3[k].coeff=p1[i].coeff;
				p3[k].exp=p1[i].exp;
				i++;
				k++;
			}
			else
			{
				p3[k].coeff=p2[j].coeff;
				p3[k].exp=p2[j].exp;
				j++;
				k++;
			}
	}
	while(i<t1)	
	{
		p3[k].coeff=p1[i].coeff;
		p3[k].exp=p1[i].exp;
		i++;
		k++;
	}
while(j<t2)	
	{
		p3[k].coeff=p2[j].coeff;
		p3[k].exp=p2[j].exp;
		j++;
		k++;
	}
	return k;
}

void displayPoly(struct poly p1[], struct poly p2[],struct poly p3[],int t1,int t2,int p)
{
	int i,j,k;
	printf("POLYNOMIAL  1   :  ");
	for(i=0;i<1;i++)
	{
	    printf("%f x^%d ",p1[i].coeff,p1[i].exp);
	    if(i==t1-1){
	    break;
	    }
	    printf("+");
	}
	printf("\n");
	printf("POLYNOMIAL  2   :  ");
	for(j=0;j<t2;j++)
	{
	printf("%f x^%d ",p2[j].coeff,p2[j].exp);
	if(j==t2-1){
	    break;
	    }
	    printf("+");
	}
	printf("\n");
	printf("SUM     :  ");
	for(k=0;k<p;k++)
	{
	printf("%f x^%d ",p3[k].coeff,p3[k].exp);
	if(k==p-1){
	    break;
	    }
	    printf("+");
	}
}

void main()
{
	

	int t1,t2,s;
	printf("Enter the numbers of elements in first poly   :  ");
	scanf("%d",&t1);
	printf("Enter the numbers of elements in second poly   :  ");
	scanf("%d",&t2);
	readPoly(p1, p2,t1,t2);
	s=addPoly(p1,p2,p3,t1,t2);
	displayPoly(p1,p2,p3,t1,t2,s);
}




