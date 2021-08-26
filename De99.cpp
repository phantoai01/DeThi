#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>

//su dung kieu du lieu struct
typedef struct
{
	//khai bao phan thuc
    int phanthuc;
    //khai bao phan ao
    int phanao;
    //module cua so phuc
    float module;
}sophuc;

// ham nhap cac so phuc
void nhap(sophuc *x, int n)
{
    for(int i=0; i<n; i++)
    {
        printf(" nhap phan thuc thu %d: ", i+1);
        //nhap gia tri cho tung phan thuc
        scanf("%d", &(x+i)->phanthuc);
        printf(" nhap phan ao thu %d: ", i+1);
        //nhap gia tri cho tung phan ao
        scanf("%d", &(x+i)->phanao);
    }
}

//ham in ra cac so phuc
void xuat(sophuc *x, int n)
{
    for(int i=0; i<n; i++)
    {
    	//in ra man hinh tat ca cac so phuc theo dang a+bi
        printf("\nso thu %d: %d+%di",i+1, (x+i)->phanthuc, (x+i)->phanao);
    }
}

//tinh module tung so phuc
void module(sophuc *x,int n)
{
	float module;
	int a, b;
	for(int i=0; i<n; i++)
	{
		//tinh binh phuong cua phan thuc
		a=pow((x+i)->phanthuc, 2);
		//tinh binh phuong cua phan ao
		b=pow((x+i)->phanao, 2);
		//tinh va gan gia tri cho bien module
		(x+i)->module= sqrt(a+b);
		//in ra man hinh module tat ca so phuc
		printf("\nmodule cua so phuc thu %d la: %5.2f", i+1,(x+i)->module);		
	}
}

//dua ra man hinh cac so phuc co module lon nhat
void modulemax(sophuc *x,int n )
{
    float max=0;
	for(int i=0; i<n; i++)
	{
		//tim gia tri lon nhat cua module va gan vao bien max
		if((x+i)->module>max)
		{
			max= (x+i)->module;
		}
	}
	for(int i=0; i<n; i++)
	{
		//tim module co gia tri = bien max
		if((x+i)->module==max)
		{
			//in ra ma hinh cac so phuc co gia tri lon nhat theo dang a+bi
			printf("\n %d+%di voi module=%5.2f", (x+i)->phanthuc, (x+i)->phanao, (x+i)->module);
		}
	}
}

//tinh trung binh cong cac so phuc
float tbc(sophuc *x, int n)
{
	float tbcphanthuc;
	float tbcphanao;
	int tongphanthuc=0;
	int tongphanao=0;
	for(int i=0; i<n; i++)
	{
		//tinh tong phan thuc
		tongphanthuc +=(x+i)->phanthuc;
		//tinh tong phan ao
		tongphanao +=(x+i)->phanao;
	}
	//tinh tbc phan thuc
	tbcphanthuc= tongphanthuc/n;
	//tinh tbc phan ao
	tbcphanao= tongphanao/n;
	//in ra man hinh tbc cua cac so phuc theo dang a+bi
	printf("\ntrung binh cong cac so phuc la %5.2f+%5.2fi", tbcphanthuc, tbcphanao);
}

//sap xep theo gia tri tang dan cua module
void sapxep(sophuc *x, int n)
{
	sophuc tg;
	float module;
	int a, b;
	for(int i=0; i<n-1; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			// so sanh module cua cac so phuc
			if((x+i)->module > (x+j)->module)
			{
				//doi vi tri 
				tg = *(x+i+1);
				*(x+i+1) = *(x+i);
				*(x+i)= tg;
			}
		}
	}	
}
	

int main ()
{
	printf("\n               ==============MENU_Danh_Sach Chay_Chuong_Trinh===============");
	printf("\n               | 1.tao day so phuc                                          |");
	printf("\n               | 2.in ra man hinh day so phuc vua nhap                      |");
	printf("\n               | 3.tinh module tung so phuc co trong day                    |");
	printf("\n               | 4.tinh trung binh cong cac so phuc co trong day            |");
	printf("\n               | 5.sap xep cac so phuc theo gia tri module tang dan         |");
	printf("\n               | 6.ket thuc chuong trinh                                    |");
	printf("\n               =============================================================");
	int kt;
    int n;
    sophuc *x;
    do
	{
	//nhap vao so cac so phuc
	    printf("\nnhap so cac so phuc n=:");
	    scanf("%d", &n);
	}
	// nhap vao tu 0->50 so phuc
	while(n<=0||n>50);
	x=(sophuc *)malloc(n*sizeof(int));
	nhap(x,n);
    xuat(x,n);
    module(x,n);
    printf("\ncac so phuc co modul lon nhat la:");
    modulemax(x,n);
    tbc(x,n);
	sapxep(x,n);
	printf("\ndanh sach cac so phuc duoc sap xep theo chieu tang dan la:");
	xuat(x,n);
    free(x);
   	do
	{
		//bam 0 de ket thuc chuong trinh
		printf("\nbam 0 de ket thuc chuong trinh");
	    scanf("%d", &kt);
    }
    while(kt!=0);
    return 0;
}

