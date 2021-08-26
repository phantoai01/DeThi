#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
struct cuonsach{
	char masach[50];
	char tensach[50];
	char tacgia[50];
	int namxuatban;
};
void nhap(cuonsach &s){
	printf("Nhap ma sach: ");
	fflush(stdin);
	gets(s.masach);
	printf("Nhap ten sach: ");
    fflush(stdin);
	gets(s.tensach);
	printf("Nhap tac gia: ");
	fflush(stdin);
	gets(s.tacgia);
	printf("Nhap nam xuat ban: ");
	scanf("%d",&s.namxuatban);
}
void xuat(cuonsach s){
	printf( "\nMa sach: %s",s.masach);
	printf( "\tTen sach: %s",s.tensach);
	printf( "\tTac gia: %s",s.tacgia);
	printf("\tNam xuat ban: %d\n",s.namxuatban);
}
int my_strcmp(char x1[], char x2[]){
	int ketQua = 0;
	size_t len1 = strlen(x1);
	size_t len2 = strlen(x2);
	size_t min = len1<len2?len1:len2;
	for(int i=0; i<min; i++){
		ketQua = x1[i]-x2[i];
		if(ketQua!=0)
			break;
	}
	if(ketQua>0)
		return 1;
	else if (ketQua<0)
		return -1;
	else
		return 0;
}
void timkiem(cuonsach s[],int n,char ms[150]){
    int a=0;
	for(int i=0;i<n;i++){
		if(my_strcmp(s[i].masach,ms)==0){
	    if(a==0) printf("Danh sach trung voi ma sach can tim la: ");
		a++;
			xuat(s[i]);
		}
	}
	if(a==0) printf("Khong co sach trung voi ma sach can tim.\n");
}
void sapxep(cuonsach s[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(s[j].namxuatban<s[i].namxuatban){	 		
				cuonsach tam=s[j];
				s[j]=s[i];
				s[i]=tam;
			}
		}
	}
}
void menu(cuonsach s[]){
	system("cls");
	int luachon,n=0;
	while(true){
	system("cls");
	printf( "=================MENU================\n");
	printf( "1. Nhap them 1 cuon sach\n");
	printf( "2. Xuat tat ca cac cuon sach\n");
	printf( "3. Tim kiem thong tin nhung cuon sach trung voi ma sach \n");
	printf( "4. Sap xep cac cuon sach theo thu tu tang dan nam xuat ban\n");
	printf( "0. Ket thuc chuong trinh!!!\n");
	printf( "=====================================\n");
	printf("Nhap vao lua chon: ");
	scanf("%d",&luachon);
	if(luachon==1){
		if(n==50) printf("Danh sach da toi da khong nhap duoc nua");
		nhap(s[n]);
		n++;
	}else if(luachon==2){
		for(int i=0;i<n;i++){
			printf("\nSach thu %d: ",i+1);
			xuat(s[i]);
		}
		system( "pause");
	}else if(luachon==3){
		char ms[150];
		int nxb;
		fflush(stdin);
		printf("Nhap ma sach can tim: ");
		gets(ms);
		timkiem(s,n,ms);
		system( "pause");
	}else if(luachon==0) break;
	else if(luachon==4) {
	sapxep(s,n);
		for(int i=0;i<n;i++){
			printf("\nSach thu %d: ",i+1);
			xuat(s[i]);
		}
	system( "pause");
	}
	else{
		printf("Ban da nhap sai.Vui long nhap lai.\n");
		system( "pause");
	}
   }
}
int main(){
	cuonsach s[50];
	menu(s);
	return 0;
}