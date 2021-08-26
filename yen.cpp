#include"stdio.h"
void nhapmang(int a[][100],int n)
{
	for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
      {
      	 printf("A[%d][%d] = ", i, j);
         scanf("%d", &a[i][j]);
      }
}
void inmang(int a[][100], int n)
{
	for(int i = 0; i < n; i++)
      {
      	for(int j = 0; j < n; j++)
        	printf("%d\t", a[i][j]);
        printf("\n");   
	  }
      
}
int tongduongcheo(int a[][100],int n)
{
	int s=0;
		for(int i = 0; i < n; i++)
       	{
        	s=s+a[i][i];
		}  
	for(int i = 0; i < n; i++)
        {
      	for(int j = 0; j < n; j++)
        	if(i+j==n-1)
        	s=s+a[i][j];
	 	}
	return s;
}
void tich(int A[][100], int B[][100], int C[][100], int n)
{
   for(int i = 0; i<n ; i++)
   for(int k = 0; k<n ; k++)
   {
      C[i][k] = 0;
      for(int j = 0; j<n ; j++)
         C[i][k] = C[i][k] + A[i][j]*B[j][k];
   }
}

main()
{
	int a[100][100],n=1,b[100][100],c[100][100],d[100][100],h=1;
	do
	{
		if(n<=0)
		{
			printf("Vui long nhap lai n:\n");
		}
		printf("n bang:\n");scanf("%d",&n);
	}
	while(n<=0);
		printf("Vui long nhap ma tran A:\n");
		nhapmang(a,n);
		printf("Vui long nhap ma tran B:\n");
		nhapmang(b,n);
		printf("Vui long chon chuc nang:\n");
		printf("Chuc nang 1: In ra ma tran A.\n");
		printf("Chuc nang 2: In ra ma tran B.\n");
		printf("Chuc nang 3: Tong cac duong cheo trong ma tran A.\n");
		printf("Chuc nang 4: Tong cac duong cheo trong ma tran B.\n");
		printf("Chuc nang 5: Tich hai ma tran vua nhap.\n");
		printf("Muon thoat chuong trinh vui long chon phim 0.\n");
		printf("Vui long chon chuc nang:");
	do
	{
		scanf("%d",&h);
		switch(h)
		{
			case 1:
				{
					printf("Ma tran A vua nhap la:\n");
					inmang(a,n);break;
				}
			case 2:
				{
					printf("Ma tran B vua nhap la:\n");
					inmang(b,n);break;
				}
			case 3:
				{
					printf("Tong 2 duong cheo cua ma tran A la: %d\n",tongduongcheo(a,n));	break;
				}
			case 4:
				{
					printf("Tong 2 duong cheo cua ma tran B la: %d\n",tongduongcheo(b,n));	break;
				}
			case 5:
				{
					printf("Tich 2 ma tran A va B la ma tran D la:\n");
					tich(a,b,d,n);
					inmang(d,n);break;
				}
		}
	}
	while(h!=0);
}
