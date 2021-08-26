#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

typedef struct
{
    int phanthuc;
    int phanao;
    float module;
}sophuc;

void nhap(sophuc *x, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\n nhap phan thuc thu %d: ", i+1);
        scanf("%d", &(x+i)->phanthuc);
        printf("\n nhap phan ao thu %d: ", i+1);
        scanf("%d", &(x+i)->phanao);
    }
}

void xuat(sophuc *x, int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\nso thu %d: %d+%di",i+1, (x+i)->phanthuc, (x+i)->phanao);
    }
}

void tinhmodule(sophuc *x,int n)
{
	float module;
	int a, b;
	for(int i=0; i<n; i++)
	{
		a=pow((x+i)->phanthuc, 2);
		b=pow((x+i)->phanao, 2);
		(x+i)->module= sqrt(a+b);	
	}
}

void xuatmodule(sophuc *x,int n)
{
	float module;
	int a, b;
	for(int i=0; i<n; i++)
	{
		a=pow((x+i)->phanthuc, 2);
		b=pow((x+i)->phanao, 2);
		(x+i)->module= sqrt(a+b);
		printf("\nmodule cua so phuc thu %d la: %5.2f", i+1,(x+i)->module);		
	}
}

void modulemax(sophuc *x,int n )
{
	tinhmodule(x,n);
    float max=0;
	for(int i=0; i<n; i++)
	{
		if((x+i)->module>max)
		{
			max= (x+i)->module;
		}
	}
	
	for(int i=0; i<n; i++)
	{
		if((x+i)->module==max)
		{
			printf("\n %d+%di voi module=%5.2f", (x+i)->phanthuc, (x+i)->phanao, (x+i)->module);
		}
	}
}

float tbc(sophuc *x, int n)
{
	float tbcphanthuc;
	float tbcphanao;
	int tongphanthuc=0;
	int tongphanao=0;
	for(int i=0; i<n; i++)
	{
		tongphanthuc +=(x+i)->phanthuc;
		tongphanao +=(x+i)->phanao;
	}
	tbcphanthuc= tongphanthuc/n;
	tbcphanao= tongphanao/n;
	printf("\ntrung binh cong cac so phuc la %5.2f+%5.2fi", tbcphanthuc, tbcphanao);
}

void sapxep(sophuc *x, int n)
{
	tinhmodule(x,n);
	sophuc tg;
	int a, b;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			if((x+i)->module > (x+j)->module)
			{ 
				tg = *(x+j);
				*(x+j) = *(x+i);
				*(x+i)= tg;
			}
		}
	}
	xuat(x,n);
}
	

int main ()
{
	int kt;
    int n;
    sophuc *x;
    bool daNhap = false;
    do
	{
	    printf("\nnhap so cac so phuc n=");
	    scanf("%d", &n);
	}
	while(n<=0||n>50);
	x=(sophuc *)malloc(n*sizeof(int));
	do{
		printf("\n               ==============MENU_Danh_Sach Chay_Chuong_Trinh===============");
		printf("\n               | chon 1: tao day so phuc                                     |");
		printf("\n               | chon 2: in ra man hinh day so phuc vua nhap                 |");
		printf("\n               | chon 3: tinh module tung so phuc co trong day               |");
		printf("\n               | chon 4: in ra so phuc co module lon nhat                    |");
		printf("\n               | chon 5: tinh trung binh cong cac so phuc co trong day       |");
		printf("\n               | chon 6: sap xep cac so phuc theo gia tri module tang dan    |");
		printf("\n               | chon 0: ket thuc chuong trinh                               |");
		printf("\n               =============================================================");
		printf("\nMoi ban chon: ");
		scanf("%d",&kt);
		switch(kt)
		{
	
		case 1:
                printf("\nBan da chon nhap day so phuc!");
                nhap(x, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                
                break;
            case 2:
                if(daNhap)
				{
                    printf("\nBan da chon xuat day so phuc!");
                    xuat(x, n);
                }
				else
				{
                    printf("\nNhap day so phuc truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                
                break;
            case 3:
                if(daNhap)
				{
                	printf("\nBan da chon tinh module tung so phuc co trong day ");
                	xuatmodule(x,n);
                }else
				{
                    printf("\nNhap day so phuc truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                
                break;
            case 4:
            	if(daNhap)
            	{
            		printf("\nBan da chon dua ra so phuc co modul lon nhat ");
            		modulemax(x,n);
				}
				else
				{
					 printf("\nNhap day so phuc truoc!!!!");
				}
				 printf("\nBam phim bat ky de tiep tuc!");
                
                break;
            case 5:
                if(daNhap)
				{
                    printf("\nBan da chon tinh trung binh cong cac so phuc co trong day");
                	tbc(x,n);
                }
				else
				{
                    printf("\nNhap day so phuc truoc!!!!");
                    
                }
                printf("\nBam phim bat ky de tiep tuc!");
                
                break;
            case 6:
                if(daNhap)
				{
                    printf("\nBan da chon sap xep cac so phuc theo gia tri module tang dan");
                	sapxep(x,n);
                }else
				{
                    printf("\nNhap day so phuc truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                
                break;
            case 0:
                printf("\nBan da chon ket thuc chuong trinh!");
                
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                
                break;
        }
    }
	while(kt);
    return 0;
}
