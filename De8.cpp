/*  de tai 08 - nhom 4 - lop 71DCHT23
    thanh vien nhom:
    Nguyen Thi Ngoc Anh - 71DCHT22016
    Nguyen Ngoc Khanh - 71DCHT22059
    Tran Ngoc Duy - 71DCHT22029 */
#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#define max 100

void  Nhap( float MT[][max], int n);
void Nhapcapn(int *n);
void  Xuat(float MT[][max], int n);
float tongcheo(float MT[][max], int n);
void tonghaimatran(float A[][max], float B[][max], float C[][max], int n);
void tichhaimatran( float A[][max], float B[][max], float C[][max], int n);

// a. nhap xuat ma tran vuong cap n
// nhap ma tran vuong cap n
void  Nhap( float MT[][max], int n)
{   
   for (int i=0; i<n; i++)

       for (int j=0; j<n; j++)
       {  
	     printf ("[%d][%d] =",i,j);
           scanf ("%f", &MT[i][j]);
           }
}
// nhap n
void  Nhapcapn(int *n) {
			*n = 0;
			do{
				printf ("\n Nhap ma tran cap n :");
				scanf ("%d", n);
			}while (*n <= 0 || *n > max);
}				
// xuat ma tran vuong cap n
void  Xuat(float MT[][max], int n)
{	
	for (int i = 0; i < n; i++)
		{
				printf ("\n");
	  	for (int j=0; j < n; j++)
			printf ("%.1f\t", MT[i][j]);
			}
}
//b tính tong duong cheo chinh và duong cheo phu cua tung ma tran vua nhap
float tongcheo(float MT[][max], int n)
{
	float tongcheo=0;
		for (int i=0; i<n;i++)
		{ for (int j=0;j<n;j++)
			if (i == j)
			tongcheo += MT[i][i];
			}
		for (int i=0; i<n; i++)
		{
			for (int j=0; j < n; j++)
			if (i+j==n-1)
			tongcheo += MT[i][j];
			}
			return tongcheo;
		}

			 	
// c tinh tong hai ma tran
void tonghaimatran(float A[][max], float B[][max], float C[][max], int n)
{	
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	C[i][j]= A[i][j]+B[i][j];
	}
// d tinh tich hai ma tran
void tichhaimatran( float A[][max], float B[][max], float C[][max], int n)
{
	for (int i=0; i<n; i++)
	for (int j=0;j<n;j++)
		{ 
			C[i][j]= 0;
		  	for (int d=0;d<n;d++)
		  	{
		  		C[i][j] += A[i][d] * B[d][j];
		  		}
		  	}
		}
int main()
{
	int chon;
	int n;
	float a[max][max];
	float b[max][max];
	float c[max][max];
	Nhapcapn (&n);
	
    do
    {
        system("cls");
        printf("\t\t\t ============MENU==================================\n");
        printf("\t\t\t |1. nhap ma tran                                 |\n");
        printf("\t\t\t |2. In ra ma tran vua nhap                       |\n");
        printf("\t\t\t |3. Tinh Tong cheo chinh va cheo phu tung ma tran|\n");
        printf("\t\t\t |4. Tinh tong cua 2 ma tran                      |\n");
        printf("\t\t\t |5. Tinh tich cua 2 ma tran                      |\n");
        printf("\t\t\t |0. Thoat                                        |\n");
        printf("\t\t\t ==================================================\n");
        printf("Ban chon: ");
        scanf("%d", &chon);
        switch(chon)
        {
            case 1:
			printf ("\n Nhap ma tran A : \n");
			Nhap (a, n);
			printf ("\n Nhap ma tran B : \n");
			Nhap (b, n);
			printf("\nBan da nhap thanh cong!");
			printf("\nBam phim bat ky de tiep tuc!");
				getch();
                break;
            case 2:
			printf ("\n ma tran A : \n");
			Xuat (a, n);
			printf ("\n ma tran B : \n");
			Xuat (b, n);
  			printf("\nIn thanh cong ma tran vua nhap!");
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
                break;
            case 3:
			printf ("\n tong duong cheo cua ma tran A: %.2f \n ", tongcheo(a,n));
			printf ("\n tong duong cheo cua ma tran B: %.2f \n", tongcheo(b,n));
				printf("\nDa tinh thanh cong tong cheo chinh va cheo phu !");
				printf("\nBam phim bat ky de tiep tuc!");
				getch();
                break;
            case 4:
			tonghaimatran(a,b,c,n);
			printf ("\n tong hai ma tran A và B:  ");
			Xuat (c,n);
				printf("\nDa tinh tong thanh cong 2 ma tran !");
				printf("\nBam phim bat ky de tiep tuc!");
  				getch();
                break;
            case 5:
			tichhaimatran(a,b,c,n);
			printf ("\n tich hai ma tran A và B:  ");
			Xuat (c,n);
				printf("\nDa tinh tich thanh cong 2 ma tran !");
				printf("\nBam phim bat ky de tiep tuc!");
  				getch();
                break;
            case 0:
            	printf("\nBan da chon thoat chuong trinh!");
            	return 0;
                break;
            default:
                printf("Ban chon sai. Moi ban chon lai MENU!\n");
                break;
        }
    }while(chon!=0);
}
