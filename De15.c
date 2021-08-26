#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h> 
#include <math.h>

void hienthi_menu(void);
unsigned long long giaithua(int n);
unsigned long long tohop_chapk(int n, int k);
int thuaso_nt(unsigned n);
unsigned long long chuyendoi_he10(int n,int m );

void hienthi_menu(void)
{
    printf("-------------------------------------------------------------------------------------------------------------------- \n");
    printf("                                                 CHUONG TRINH CHINH \n");
    printf("-------------------------------------------------------------------------------------------------------------------- \n");
    printf("1. Tinh n! \n");
    printf("2. Tinh to hop chap k cua n phan tu \n");
    printf("3. Phan tich n thanh thua so nguyen to \n");
    printf("4. Doi so he 10 sang he m \n");
    printf(" De ket thuc chuong trinh chon phim 0 \n");
    printf("-------------------------------------------------------------------------------------------------------------------- \n");
}

//int nhap_gt(unsigned n,unsigned k, unsigned m)
//{
//    printf("Nhap lan luot 3 so nguyen n,k,m thoa man dieu kien (n > 0, 0 <= k <= n,  2<= m <= 10) de thuc hien cac lua chon sau: \n");
//
//    do
//    {
//
//        if(n<0 || k<0 || k>n || m>10 || m<2)
//        {
//            printf("Sai dieu kien nhap lai 3 so tren \n");
//        }
//    }while(n<0 || k<0 || k>n || m>10 || m<2);
//    return((void)(n),(void)(k),m);
//
//}

unsigned long long giaithua(int n)
 {
   if (n <= 1)
     return 1;
   else
     return n * giaithua(n-1);
 }

unsigned long long tohop_chapk(int n, int k)
{
    return (giaithua(n)/(giaithua(k)*giaithua(n-k)));
}

int thuaso_nt(unsigned n)
{
    if(n < 2)
    {
        printf("Nhap n > 1");
    }
    else
    {
        unsigned int i = 2;
        printf("%u = ", n);
        while(n > 1)
        {
            if(n % i == 0)
            {
                printf("%u", i);
                if(n != i)
                {
                    printf("x");
                }
                n /= i;
            }
            else
            {
                i++;
            }
        }
    }
    printf("\n");

    return 0;
}


unsigned long long chuyendoi_he10(int n,int m )
{
    long long h = 0;
    int p = 0;
    if(m==2 || m==8 || m==10)
    {
        if(m==2)
        {
                while (n > 0)
                {
                    h += (n % 2) * pow(10, p);
                    ++p;
                    n /= 2;
                }
        }
                
        if(m==8)
        {
            while(n > 0)
            {
                h += (n % 8) * pow(10, p);
                p++;
                n /= 8;
            }
        }
        if(m==10)
        {
            h=10;
        }
        return h;
    }
    else
    {
        return n;
    }
}
int main()
{
    unsigned n = 0,k = 0,m = 0;
    int luachon;
    hienthi_menu();
//    printf("Nhap n: ");scanf("%d",&n);
//    printf("Nhap k: ");scanf("%d",&k);
//    printf("Nhap m: ");scanf("%d",&m);
//    nhap_gt(n,k,m);
    do
        {
            printf("Nhap n: ");scanf("%d",&n);
            printf("Nhap k: ");scanf("%d",&k);
            printf("Nhap m: ");scanf("%d",&m);
    
            if(n<0 || k<0 || k>n || m>10 || m<2)
            {
                printf("Sai dieu kien nhap lai 3 so tren \n");
            
            }
        }while(n<0 || k<0 || k>n || m>10 || m<2);

    do
    {
        printf("\nLua chon chuong trinh (1-5): ");
        scanf("%d", &luachon);
        switch(luachon)
        {
            case 1: printf("%d! = %lld\n",n,giaithua(n));
                break;
            case 2: printf("%d!/(%d!*(%d!-%d!) = %lld\n",n,k,n,k,tohop_chapk(n,k));
                break;
            case 3: thuaso_nt(n);
                break;
            case 4: printf("%d chuyen doi tu he 10 sang he %d = %lld\n",n,m,chuyendoi_he10(n, m ));
                break;
            case 0: return(printf("------------------------------------------------KET THUC CHUONG TRINH------------------------------------------------ \n"));
                break;
        default:
                printf("Khong co lua chon nay, moi ban nhap lai! ");
                break;
        }
        
    }while (true);
    
}


    
    
    
    

