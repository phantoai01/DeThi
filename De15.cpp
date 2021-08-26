#include <iostream>

using namespace std;

bool isFirstTime = true;
int n, k, m;

void cauA(int n, int k, int m)
{
	cout << "n: "<< n << "\nk: "<< k <<"\nm: "<< m << endl;
	cout << endl;
}

int cauB1(int n)
{
	int nGiaiThua = 1;
	int store = n;
	while(store > 0)
	{
		nGiaiThua = nGiaiThua * store;
		store--;
	}
	
	return nGiaiThua;
	
}

int cauB2(int n, int k, int k1)
{
	if(n == k ) return 1;			
	return n/(k + k1);
}

int ktr(int n)
{
	for(int i = 2; i < n/2; i++)
	{
		if(n % i == 0)	return 1;
	}
	
	return 0;
}

void cauC(int n)
{	
	int test = ktr(n);
	if(test == 0) cout << n << endl;
	else
	while(n != 1) 
	{
		for(int i = 2; i < 8; i++)
		{
			if(n % i == 0)
			{	
				n = n/i;
				cout << i << " ";
				break;
			}
		}
	}
	

}

void cauD(int n, int m)
{
	if(n > 0)
	{
		int sd = n % m;
		n = n / m;
		cauD(n, m);
		cout << sd;
	}
}


int main()
{	
	if(isFirstTime)
	{
		cout << "Nhap n > 0: ";
		cin >> n;
		if(n <=0 )
		{
			cout << "Nhap lai n: ";
			cin >>n;
		}
		cout << "Nhap 0<= k <=n: ";
		cin >> k;
		if(k < 0 || k > n)
		{
			cout <<"Nhap lai k: ";
			cin >> k;
		}
		cout << "2 <= m <=10: ";
		cin >> m;
		if(m < 2 || m > 10)
		{
			cout <<"Nhap lai m: ";
			cin >> m;
		}
		
		if(isFirstTime)	isFirstTime = false;
	}
		
	
	
	int choice;
	cout << "Moi chon chuc nang: \n";
	cout << "1. In ra so.\n" << "2. Tinh n! va to hop chap k cua. n\n" << "3. Phan tich n thanh cac so nguyen to.\n" << "4. Doi n co so 10 sang co so m.\n" << "Bam 0 de thoat.\n";
	cin >> choice;
	if(choice < 0 || choice > 4)
	{
		cout << "Moi chon lai: ";
		cin >> choice;
	}
	else 
	{
		if(choice == 0) cout << "Thoat!\n";
		else 
		{
			if(choice == 1)
			{
				cauA(n, k ,m);
				main();
			}
			if(choice == 2)
			{
				int nGiaiThua = cauB1(n);
				cout << n <<"!: "<<nGiaiThua<< endl;
				int kGiaiThua = cauB1(k);
				int k1GiaiThua = cauB1(n-k);
				int toHop = cauB2(nGiaiThua, kGiaiThua, k1GiaiThua);
				cout << "To hop: " << toHop <<endl;
				cout << endl;
				main();
			}
			if(choice == 3)
			{
				cout << n << " = ";
				cauC(n);
				cout << endl;
				main();
			}
			if(choice == 4)
			{
				cauD(n, m);
				cout << endl;
				main();
			}
		}
	
	}
	
	return 0;
}
