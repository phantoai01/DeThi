#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
typedef struct SinhVien {
	char msv[20];
	char hodem[20];
	char ten[10];
	int namsinh;
}SV;
//khai báo tất cả các hàm được sử dụng ở trong bài
void xoa_enter(char ds[]);
void NhapSv(SV &sv);
void NhapDSSV(SV ds[], int &n);
void xuatSv(SV sv);
void XuatDSSV(SV ds[], int n);
void SVTruocNamNhap(SV ds[], int n);
void SVtuoiMin(SV ds[], int n);
void SXDStheoten(SV ds[], int n);
//định nghĩa các hàm đã khai báo ở trên
void xoa_enter(char ds[]) {
	size_t len = strlen(ds);
	if (ds[len - 1] == '\n') {
		ds[len - 1] = '\0';
	}
}
// hàm nhập 1 sinh viên 
void NhapSv(SV &sv) {
	printf("\nMaSV:");fflush(stdin);  fgets(sv.msv, sizeof(sv.msv), stdin); xoa_enter(sv.msv);
	printf("\nNhap Ho Dem: ");fflush(stdin); fgets(sv.hodem, sizeof(sv.hodem), stdin); xoa_enter(sv.hodem);
	printf("\nNhap Ten: "); fflush(stdin); fgets(sv.ten, sizeof(sv.ten), stdin); xoa_enter(sv.ten);
	printf("\nNhap nam sinh: "); scanf("%d", &sv.namsinh);
}
//hàm xuất 1 sinh viên ra màn hình
void xuatSv(SV sv) {
	printf("%s \t\t %s \t\t %s \t\t %d\n", sv.msv, sv.hodem, sv.ten, sv.namsinh);
}
//Chức năng 1: Nhập thông tin các sinh viên
void NhapDSSV(SV ds[], int &n) {	
        printf("\n____________________________________\n");
	for (int i = 0; i < n; i++) {
		printf("\nNhap vao sinh vien thu %d", i + 1);
		NhapSv(ds[i]);
        printf("\n____________________________________\n");
	}
}
//Chức năng 2:in ra danh sách sinh viên
void XuatDSSV(SV ds[], int n) {
	printf("\nDanh sach sinh vien gom:\n");
	printf("\n MaSV \t\t Ho Dem  \t\t Ten \t\t Nam Sinh\n");
	for (int i = 0; i < n; ++i) {
		xuatSv(ds[i]);
	}
}
//Chức năng 3: đưa ra tất cả các sinh viên được sinh trước năm nhập vào từ bàn phím
void SVTruocNamNhap(SV ds[], int n) {
	int nam;
	do {
		printf("Nhap Nam:");
		scanf("%d", &nam);
	} while (nam < 1900 || nam > 2021);
	printf("\nDanh sach sinh vien duoc nhap truoc nam %d la:\n",nam);
        printf("\n MaSV \t\t Ho Dem  \t\t Ten \t\t Nam Sinh\n");
	for (int i = 0; i < n; i++) {
		if (ds[i].namsinh < nam){
			xuatSv(ds[i]);
		}
		
	}
}
//Chức năng 4:Đưa ra sinh viên nhỏ tuổi nhất có trong danh sách
void SVtuoiMin(SV ds[], int n) {
	int tuoi[50];
	for (int i = 0; i < n; i++) {
		tuoi[i] = 2021 - ds[i].namsinh;
	}
	int min = tuoi[0];
	for (int i = 1; i < n; i++) {
		if (min > tuoi[i])
			min = tuoi[i];
	}
	for (int i = 0; i < n; i++) {
		if (tuoi[i] == min)
			xuatSv(ds[i]);
	}
}
//Chức năng 5:Sắp xếp lại danh sách sinh viên theo thứ tự tăng dần của tên A --> Z
void SXDStheoten(SV ds[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (strcmp(ds[i].ten, ds[j].ten) > 0) {
				SV tg;
				tg = ds[i];
				ds[i] = ds[j];
				ds[j] = tg;
			}
		}
	}
	XuatDSSV(ds, n);
}
int main() {
	int luachon;
	int n;
	bool DaNhap = false; 
	do {
		printf("\nNhap vao so sinh vien co trong danh sach: ");	scanf("%d", &n);
	} while (n < 1 || n > 50);
	SV ds[50];
	while (true) {
		system("cls");
		printf("			                       ***********************************************************************************\n");
		printf("			                       **                        CHUONG TRINH QUAN LY SINH VIEN                         **\n");
		printf("			                       **      1. Nhap du lieu sinh vien!                                               **\n");
		printf("			                       **      2. In danh sach sinh vien                                                **\n");
		printf("			                       **      3. Danh sach sinh vien sinh truoc nam duoc nhap vao tu ban phim          **\n");
		printf("			                       **      4. Dua ra danh sach sinh vien nho tuoi nhat                              **\n");
		printf("			                       **      5. sap xep lai danh sach sach sv theo thu tu tang dan cua ten            **\n");
		printf("			                       **      0. Thoat                                                                 **\n");
		printf("			                       ***********************************************************************************\n");		
		printf("					       **                        Hay chon chuc nang ma ban muon thao tac:");	scanf("%d", &luachon);
		switch (luachon) {
		case 1:
			printf("\nNhap du lieu sinh vien!");
			NhapDSSV(ds, n);
			printf("\nBan da nhap thanh cong!");
			DaNhap = true;
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case 2:
			if (DaNhap) {
				printf("\nBan da chon In danh sach sinh vien!\n");
				XuatDSSV(ds, n);
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case 3:
			if (DaNhap) {
				printf("\nBan da chon in ra Danh sach sinh vien sinh truoc nam duoc nhap vao tu ban phim!\n");
				SVTruocNamNhap(ds, n);
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case 4:
			if (DaNhap) {
				printf("\nBan da chon Dua ra danh sach sinh vien nho tuoi nhat!\n");
				printf("\nDanh sach sinh vien nho tuoi nhat trong danh sach la:\n");
				SVtuoiMin(ds, n);
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case 5:
			if (DaNhap) {
				printf("\nBan da chon sap xep lai danh sach sach sv theo thu tu tang dan cua ten!\n");
				printf("\nDanh sach sinh vien sau khi duoc sap xep theo ten tang dan la:\n");
				SXDStheoten(ds, n);
				printf("\nDa Sap Xep Thanh Cong Sinh Vien Theo Ten.");
			}
			else {
				printf("\nNhap DS SV truoc!!!!");
			}
			printf("\nBam phim bat ky de tiep tuc!");
			getch();
			break;
		case 0:
			printf("\nBan da chon thoat chuong trinh!");
			printf("\nBam phim bat ky de thoat!");
			exit(0);
		default:
			printf("\nKhong co chuc nang nay vui long nhap lai!");
			printf("\nBam phim bat ky de quay lai!");
			getch();
			break;
		}
	}
}