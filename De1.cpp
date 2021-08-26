#include<stdio.h>
#include<stdbool.h>
#include<math.h>
bool ktsnt(int soA) // hàm bool tra v? true/false
{
	if (soA < 2) // N?u so A nho hon 2
	{
		return false;// tra v? false
	}
	else if (soA > 2)// N?u so A lon hon 2
	{
		if (soA % 2 == 0)  // Xét xem A có chia h?t cho 2 kh?ng?
		{
			return false;// Nu chia het, return false.
		}
		for (int i = 3; i < sqrt((float)soA); i += 2)  // xét tính 3 d?n can b?c 2 cua so A
		{
			if (soA % i == 0)  // neu A chia het cho mot so nào d? trong doan này
			{
				return false;// tra v? k?t qua sai
			}
		}
	}
	return true;// sau t?t ca c?c ch? tr?n, n? m? kh?ng sai th? cu?i c?ng n? d?ng 
}
void one(int *&a, int n) {
	//nhap n so nguyen
	for (int i = 0; i < n; i++)
	{
		printf("Nhap a[%d]:", i);
		scanf("%d", &a[i]);
	}
	//xuat n so nguyen
	for (int i = 0; i < n; i++){
		printf("a[%d]=%d \n", i,a[i]);
	}
	printf("\n");
}

void two(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		// 2 s? li?n k? nhau
		int m = a[i];
		int n = a[i + 1];
		if (m > 0 && n > 0) {
			// công th?c tính u?c chung l?n nh?t
			while (m != n)
			{
				if (m > n) {
					m = m - n;
				}
				else {
					n -= m;
				}
			}
			//di?u ki?n c?a 2 s? nguyên t? cùng nhau
			if (m == 1) {
				printf("%d, %d la 2 so nguyen to cung nhau\n", a[i], a[i + 1]);
			}
		}
	}
}
bool ktscp(int n) {
	int i = 0;
	while (i * i <= n) {
		if (i * i == n) {
			return true;
		}
		i++;
	}
	return false;
}
void three(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		if (ktscp(a[i]) == true)
			printf("%d la so chinh phuong tai vi tri so %d \n",a[i], i);
	}
}

// ct tính giai th?a d? quy
//5! =5*4*3*2*1 ... = 120
int giaiThua(int n)
{
	if (n == 1)
		return 1;
	return n * giaiThua(n - 1);
}
bool ktgt(int a) {
	int i = 1;
	//a = 120 , i = 5
	while (a >= giaiThua(i))
	{
		// s? là giai th?a c?a m?t s?
		if (a == giaiThua(i))
			return true;
		i++;
	}
	return false;
}
void four(int a[], int n) {
	for (int i = 0; i < n; i++)
	{
		//a[0] = 120
		if (ktgt(a[i]))
			printf("a[%d] tai vi tri so %d", a[i], i);
	}
}
int main() {
	int* a, n;
	printf("Nhap n:");
	do
	{
		scanf("%d", &n);
	} while (n <= 0);
	a = new int[n];
	int menu = 100;
	while (menu != 0)
	{

		printf("*******************************************************\n");
		printf("**    CHUONG TRINH KIEM TRA THONG TIN   **\n");
		printf("**      1. Nhap vao day so nguyen       **\n");
		printf("**      2. Cap so nguyen to ke nhau     **\n");
		printf("**      3. Cac so chinh phuong			**\n");
		printf("**      4. Giai thua cua so da nhap la	**\n");
		printf("**      0. Thoat						**\n");
		printf("******************************************\n");
		printf("**         Nhap lua chon cua ban		**\n");
		scanf("%d", &menu);
		switch (menu)
		{
		case 1:one(a, n);
			break;
		case 2:two(a, n);
			break;
		case 3:three(a, n);
			break;
		case 4:four(a, n);
			break;
		default:
			printf("Khong hop le!");
			break;
		}
	}
}
