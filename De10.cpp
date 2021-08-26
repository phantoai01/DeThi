#include<stdio.h>
#include<conio.h>
#include<string.h>
#include <windows.h>
struct ps
{
	int ts,ms;
};

void nhap (ps *s, int n)
{
	for(int i=0; i<n;i++)
	{
		printf("\tnhap vao phan so thu %d\n",i+1);
		do 
		{
			printf("\t\ttu so = ");
			scanf("%d",&s[i].ts);
		} while (s[i].ts==0);
		do 
		{
			printf("\t\tmau so = ");
			scanf("%d",&s[i].ms);
		} while (s[i].ms==0);
	}
}
void xuat1PS(ps x)
{
	printf("%d/%d",x.ts,x.ms);

}
void xuat(ps s[], int n)
{
	for(int i=0;i<n;i++)
	{
		xuat1PS(s[i]);
		printf(" ");
	}
	printf("\n");
}
int UCLN(int a,int b)
{
	int kq=1;
	for(int i=a;i>0;i--)
		if (a%i==0 && b%i==0)
		{
			kq=i;
			break;
		}
		return kq;
}
void rutgon(ps &phanso)
{
	int c=UCLN(phanso.ts,phanso.ms);
	phanso.ts=phanso.ts/c;
	phanso.ms=phanso.ms/c;
}
void toigianPS(ps *s, int n)
{
	for(int i = 0; i < n;i ++)
	{
		rutgon(s[i]);
	}
}
ps tongps(ps s[], int n)
{
    int i,z;
    ps tmp=s[0];
    for (i=1; i< n; i++)
    {
        tmp.ts = tmp.ts*s[i].ms + tmp.ms*s[i].ts;
        tmp.ms = tmp.ms*s[i].ms;
        z=UCLN(tmp.ts, tmp.ms);
        tmp.ts /=z;
        tmp.ms /=z;
    }
    return tmp;
}
//sap xep n phan so theo thu tu tang dan
void sapxepps(ps *a,int n)
{
	for(int i=0;i<n;i++)
		for(int j=0;j<i;j++)
		{
            float A,B;
			A=(a[j].ts/(float)a[j].ms);
			B=(a[i].ts/a[i].ms);
			if(A<B)
            {
					int x=a[i].ts;
					int y=a[i].ms;
					a[i].ts=a[j].ts;
					a[i].ms=a[j].ms;
					
	                a[j].ts=x;
					a[j].ms=y;
		    }
        }
}

void Menu() 
{
	printf("=================MENU================\n");
	printf( " 1. Nhap phan so\n");
	printf( " 2. Toi gian phan so trong day\n");
	printf( " 3. Tinh tong cac phan so trong day\n");
	printf( " 4. Sap xep phan so trong day. Phan so lon nhat, nho nhat\n");
	printf( " 0. Ket thuc chuong trinh\n");
	printf( "=====================================\n");
	printf( "Nhap lua chon: ");
}
int main()
{
	int n = 0;
	ps s[100];
	
	int luachon; 
	while(1)
	{
		system("cls"); // xoa man hinh
		Menu();
		scanf("%d",&luachon);
		switch(luachon)
		{
			case 1:
			{
				do 
				{
					printf("Nhap vao so phan so (n >=1 && n <=50): ");
					scanf("%d",&n);
				} while (n<1 || n>50);
				nhap(s,n);
				printf( "Day phan so vua nhap\n");
				xuat(s,n);
				system("pause"); // dung man hinh
				break;	
			}
			case 2:
			{
				if(n == 0)
				{
					printf("Danh sach rong\n");
					break;
				}
				toigianPS(s,n);
				printf("Day phan so sau khi toi gian\n");
				xuat(s,n);
				system("pause"); // dung man hinh
				break;
			}
			case 3:
			{
				if(n == 0)
				{
					printf("Danh sach rong\n");
					break;
				}
				ps tong = tongps(s,n);
				printf("Tong phan so: %d/%d\n", tong.ts, tong.ms);
				
				system("pause"); // dung man hinh
				break;
			}
			case 4:
			{
				if(n == 0)
				{
					printf( "Danh sach rong\n");
					break;
				}
				sapxepps(s,n);
				printf("Day phan so sau khi sap xep\n");
				xuat(s,n);
				printf("Phan so lon nhat: ");
				xuat1PS(s[0]);
				
				printf("\nPhan so nho nhat: ");
				xuat1PS(s[n-1]);
				printf("\n");
				system("pause"); // dung man hinh
				break;
			}
			case 0:
			{
				printf("Ban chon thoat\n");
				system("pause");
				return 0;
			
			}
		}
	}
	return 1;
}
