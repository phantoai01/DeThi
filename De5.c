#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
using namespace std;

int n;


// Ham cau 1
long long * functionA(){
    printf("--------------------------------------\ncau 1: \n");
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);
    long long *m = (long long *)calloc(n,sizeof(long long));
    printf("Nhap mang: ");
    for(int i=0;i<n;i++) scanf("%lld", &m[i]);
	return m;
}

void Xuat(long long *m) {
	printf("Mang duoc luu tru: ");
	for(int i=0;i<n;i++) printf("%lld ", m[i]);	
	printf("\n--------------------------------------\n");
}

// Ham cau 2

int len(long long n) {
	int res = 0;
	while(n!=0) {
		res++;
		n/=10;
	}
	return res;
}

void functionB(long long *A){
	printf( "--------------------------------------\ncau 2:\n");
	printf("Do dai cac chu so lan luot la: ");
	
	int nhieunhat = 0;
	int vitri = 0;
	
	for(int i=0; i<n; i++) {
		printf("%d ", len(A[i]));
		if(len(A[i])>nhieunhat) {
			nhieunhat = len(A[i]);
			vitri = i;
		}
 	}
 	printf("\nSo co chu so nhieu nhat la: %lld o vi tri thu: %d",  A[vitri], vitri + 1 ) ;
 	printf("\n--------------------------------------\n");
}

// Ham cau 3
void functionC(long long *m){
	printf("--------------------------------------\ncau 3:\n");
	printf("Uoc chung lon nhat cua cac cap so lien nhau: ");
	for(int i=0; i<n-1;i++)
	{
		printf("%lld ", (long long)__gcd (m[i],m[i+1]));
	}
	printf("\n--------------------------------------\n");
}
void functionD(long long *m){
	printf("--------------------------------------\ncau 4:\n");
	printf("Tong cac chu so lan luot la: ");
	int lonnhat = 0;
	int vitri = 0;
	int tong_chu_so = 0;
	long long tmp;
	for(int i=0; i<n; i++) {
		tong_chu_so = 0;
		tmp = m[i];
		while(tmp!=0) {
			tong_chu_so = tong_chu_so + tmp%10;
			tmp/=10;
		}
		if(tong_chu_so>lonnhat) {
			lonnhat = tong_chu_so;
			vitri = i;	
		}
		printf("%d ", tong_chu_so);
	}
	printf("\nSo co tong cac chu so lon nhat la: %lld tai vi tri thu %d\n", m[vitri], vitri+1);
	printf("\n--------------------------------------\n");
	
}
int main(){
	char debai[] = "Nhap lua chon can thuc hien: \n1.nhap va luu tru day so gom n so nguyen, kiem tra n<=0 thi yeu cau nhap lai\n2.dem so chu so cua tung so nguyen co trong day vua nhap, dua ra so co so chu so lon nhat va vi tri\n3.xac dinh uoc so chung lon nhat cua cac cap so ke nhau\n4.tinh tong cac chu so cua tung so nguyen trong day so vua nhap, dua ra cac so co tong cac chu so la lon nhat va vi tri\n0.thoat chung trinh\n--------------------------------------\n";
	printf("%s", debai);
	
	
	int luachon;
	do{
		do {
			printf("LUA CHON: ");
			scanf("%d",&luachon);
		} while (luachon < 0 or luachon > 4);
		
		long long *mang;
		switch(luachon){
			case 1: {
				mang = functionA(); 
				Xuat(mang);
				break;
				}
			case 2: functionB(mang); break;
			case 3: functionC(mang); break;
			case 4: functionD(mang); break;
			case 5: break; 
		}
	}
		while(luachon!=0);
	
}

