#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
typedef struct NhanVien {
	int manv;
	char hodem[50];
	char ten[50];
	double luongcb;
}NV;
//hàm nhap 1 nhân viên
void nhapnv(NV &nv){
	printf("\nNhap ma nhan vien: "); scanf("%d",&nv.manv);
	printf("Nhap ho dem nhan vien: ");fflush(stdin); gets(nv.hodem);
	printf("Nhap ten nhan vien: "); gets(nv.ten);
	printf("Nhap luong co ban: "); scanf("%lf", &nv.luongcb);
}
//hàm nhap nhiêu nhân viên
void nhapNnv(NV a[], int n){
    for(int i = 0; i< n; ++i){
        printf("\nNhap nhan vien thu %d", i+1);
        nhapnv(a[i]);
    }
}
//hàm xuât 1 nhân viên
void xuatnv(NV nv){
	printf("\n%d", nv.manv);
	printf("%20s",nv.hodem);
	printf("%10s",nv.ten);
	printf("%20.2lf",nv.luongcb);
	printf("\n");
}
//hàm xuât nhiêu nhân viên
void xuatNnv(NV a[],int n){
	printf("\n%5s %15s %10s %20s\n","Ma nv","Ho Dem","Ten","Luong CB");
	for(int i=0;i<n;i++){
		xuatnv(a[i]);
    }
}
//hàm tìm kiêm theo ma nhan vien
void timKiemTheoManv(NV a[], int n) {
   int manv;
   int k=0;
   printf("Nhap ma nhan vien can tim: ");scanf("%d",&manv);
   for(int i=0;i<n;i++){
   	if(manv == a[i].manv){
   	xuatnv(a[i]);
   	k=1;
   }
   }
   if(k==0)
   printf("Khong co nhan ven can tim!!!");
   
}
// hàm nhân viên có luong co ban thap nhat
void LCBmin(NV a[],int n){
	NV min=a[0];
   for(int i=0;i<n;i++){
   if(a[i].luongcb<a[0].luongcb){
	   xuatnv(a[i]);
   		}
   }
}
//hàm tính luong TB
void TBluong(NV a[],int n){
 double tb=0;
    for(int i=0;i<n;i++){
            tb+=a[i].luongcb;
        }
        printf("\nLuong trung binh cua cac nhan vien la:%.2lf ", tb/n);
}
//hàm sap xep nhan vien theo luong co ban
void sapxep(NV a[], int n){
for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i].luongcb<a[j].luongcb)
			{
				NV t=a[0];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
    for(int i=0;i<n;i++){
    	xuatnv(a[i]);
	}
}
//menu cua ca chuong trình bat dau tu day
int main(){
	int chon;
    NV a[50];
    int n; 
    do{ 
        system("cls");
        printf("\n\n*****************CHUONG TRINH QUAN LY NHAN VIEN********************\n");
        printf("**      1. Nhap du lieu                                            **\n");
        printf("**      2. In danh sach nhan vien                                  **\n");
        printf("**      3. Tim Kiem NV theo ma nhan vien                           **\n");
        printf("**      4. Danh sach nhan vien co luong co ban thap nhat. TB Luong **\n");
		printf("**      5. Sap xep danh sach NV theo thu tu giam dan luong co ban  **\n");
		printf("**      0. Thoat                                                   **\n");
        printf("Nhap chuc nang ban muon su dung: ");
        scanf("%d",&chon);
        switch(chon){
        	case 1:
			do {
				printf("\nNhap vao so nhan vien: ");	scanf("%d", &n);
			} while (n > 1 && n > 50);
        		nhapNnv(a,n);
				break;
        	case 2:
        		printf("\nban da chon chuc nang 2. in danh sach nhan vien!\n");
        		printf("\n----Danh sach nhan vien----\n");
        		xuatNnv(a,n);
        		printf("\nBam phim bat ky de tiep tuc!");
        		getch();
				break;
        	case 3:
        		printf("\nban da chon chuc nang 3. Tim Kiem NV theo ma nhan vien\n !");
        		printf("\n----Thong tin nhan vien duoc tim----\n");
        		timKiemTheoManv(a,n);
        		printf("\nBam phim bat ky de tiep tuc!");
        		getch();
				break;
        	case 4:
        		printf("\nBan da chon chuc nang 4. Danh sach nhan vien co luong co ban thap nhat. TB Luong\n");
        		printf("\n----Danh sach nhan vien co luong co ban thap nhat----\n");
        		LCBmin(a,n);
                TBluong(a,n);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
        		break;
        	case 5:
          	    printf("\nban da chon chuc nang 5. Sap xep danh sach NV theo thu tu giam dan luong co ban !");
        		printf("\n----Danh sach nhan vien theo thu tu giam dan cua luong co ban----\n");
        		sapxep(a,n);
        		printf("\nBam phim bat ky de tiep tuc!");
        		getch();
				break;
			case 0:
				printf("\nBan da chon thoat chuong trinh!");
				printf("\nBam 2 lan phim bat ky de thoat!");
				getch();
				return 0;
        	default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                break;
        }
    }while(n!=0);
}
