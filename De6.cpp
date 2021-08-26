#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double *arr;
int n;

void nhap() {
	while(true) {
		printf("Nhap n: ");
		scanf("%d", &n);	
		if(n <= 0) printf("Loi: n <= 0\nNhap lai!\n");
		else {
			printf("Nhap vao %d so thuc:\n", n);
			arr = (double *)malloc(n * sizeof(double));
			for(int i = 0 ; i < n ; i++) {
				printf("Nhap so thuc %d: ", i);
				scanf("%lf", arr+i);
			}	
			break;
		}
	}	
}

void in(double *arr, int n) {
	for(int i = 0 ; i < n ; i++) {
		printf("%lf ", *(arr+i));
	}	
	printf("\n");
}

void sapxep() {
	double *temp = (double *)malloc(n * sizeof(double));
	int j = 0;
	for(int i = 0 ; i < n ; i++) 
		if(*(arr+i) < 0)
			*(temp+j++) = *(arr+i);
	for(int i = 0 ; i < n ; i++) 
		if(*(arr+i) == 0)
			*(temp+j++) = *(arr+i);
	for(int i = 0 ; i < n ; i++) 
		if(*(arr+i) > 0)
			*(temp+j++) = *(arr+i);	
	in(temp, j);
	double min = 100000, max = -100000;
	for(int i = 0 ; i < n ; i++) {
		if(*(arr+i) < min) min = *(arr+i);
		if(*(arr+i) > max) max = *(arr+i);
	}
	printf("So nho nhat la: %lf\n", min);
	printf("So lon nhat la: %lf\n", max);
	free(temp);
}

void tbc() {
	double tbcam = 0, tbcduong = 0;
	int soAm = 0;
	int soDuong = 0;
	for(int i = 0 ; i < n ; i++) {
		if(*(arr+i) < 0) {
			soAm++;
			tbcam += *(arr+i);
		}
			
		if(*(arr+i) >= 0) {
			soDuong++;
			tbcduong += *(arr+i);
		}			
	}
	printf("Trung binh cong cac so am la: %lf\n", tbcam/soAm); 
	printf("Trung binh cong cac so khong am la: %lf\n", tbcduong/soDuong);
} 

void doixung() {
	for(int i = 0 ; i < n ; i++)
		if(*(arr+i) != *(arr+n-1-i)) {
			printf("Day so khong doi xung"); 
			return;
		}
	printf("Day so doi xung"); 
}

int main() {
	nhap();
	
	while(true) {
		printf("\n\n\n-------------------Menu-------------------\n");
		printf("1. In ra day so da nhap\n");
		printf("2. Dua tat ca cac so am len dau, cac so duong xuong cuoi và cac so 0 dung giua, thu tu khong thay doi. Dua ra so lon nhat, nho nhat co trong day\n");
		printf("3. Kiem tra xem day so nay co doi xung hay khong. Neu khong hay doi cho cac phan tu day so theo thu tu doi xung nhau\n");
		printf("4. Tinh trung binh cong cac phan tu am, khong am\n");
		printf("0. Thoat chuong trinh\n");
		printf("------------------------------------------\n");
		printf("Nhap lua chon: ");
		int chon;
		scanf("%d", &chon);
		if(chon == 0) break;
		if(chon >= 1 && chon <= 4)
			switch(chon) {
				case 1: 
					in(arr, n);
					break;
				case 2: 
					sapxep();
					break;
				case 3: 
					doixung();
					break;
				case 4: 
					tbc();
					break;
			}
		else printf("Nhap lai lua chon!\n");
	}

	//free(arr);
    return 0;
}
