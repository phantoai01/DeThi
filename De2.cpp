#include <stdio.h>
#include <math.h>

struct Point {
	double x;
	double y;
	
	void nhap(char name) {
		printf("Nhap hoanh do diem %c: ", name);
		scanf("%lf", &x);
		printf("Nhap tung do diem %c: ", name);
		scanf("%lf", &y);		
	}
	
	void in(char name) {
		printf("Toa do diem %c: %c(%lf, %lf)\n", name, name, x, y);		
	} 
	
	double khoangCach(Point p) {
		double kc = sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));
		return kc;
	}
};

struct Triangle {
	Point a;
	Point b;
	Point c;
	double ab;
	double bc;
	double ac;
	double chuVi;
	double dienTich;

	void nhap() {
		while(true) {
			a.nhap('a');
			b.nhap('b');
			c.nhap('c'); 
			ab = a.khoangCach(b);
			ac = a.khoangCach(c);
			bc = b.khoangCach(c);	
			if(ab<ac+bc && ac<ab+bc && bc<ab+ac) {
				printf("Ba dinh a, b, c la ba dinh cua mot tam giac\n");
				chuVi = ab + ac + bc;
				double nuaChuVi = chuVi/2;
				dienTich = sqrt(nuaChuVi*(nuaChuVi-ab)*(nuaChuVi-ac)*(nuaChuVi-bc));
				break;
			}
			else printf("Khong thoa man 3 dinh cua mot tam giac\nNhap lai!\n");
		}
	}
	
	void in() {
		printf("Toa do ba dinh cua tam giac la: \n");
		a.in('a');
		b.in('b');
		c.in('c');
	}
	
	void inCanh() {
		printf("Do dai ba canh cua tam giac la:\n");
		printf("ab = %lf\n", ab);
		printf("bc = %lf\n", bc);
		printf("ac = %lf\n", ac);
	}	
	
	void inChuvi() {
		printf("Chu vi cua tam giac la: %lf\n", chuVi);
	}
	
	void inDienTich() {
		printf("Dien tich cua tam giac la: %lf\n", dienTich);
	}
	
	void kiemTraTamGiac() {
		if(ab == ac && ab == bc)
			printf("==> La tam giac deu");
		else if(ab == ac) {
			if(ab*ab+ac*ac==bc*bc)
				printf("==> La tam giac vuong can tai dinh A");
			else printf("==> La tam giac can tai dinh A");
		}
		else if(ab == bc) {
			if(ab*ab+bc*bc==ac*ac)
				printf("==> La tam giac vuong can tai dinh B");
			else printf("==> La tam giac can tai dinh B");
		}				
		else if(ac == bc) {
			if(ac*ac+bc*bc==ab*ab)
				printf("==> La tam giac vuong can tai dinh C");
			else printf("==> La tam giac can tai dinh C");
		} 
		else if(ab*ab+ac*ac==bc*bc) 
			printf("==> La tam giac vuong tai dinh A");
		else if(ab*ab+bc*bc==ac*ac)
			printf("==> La tam giac vuong tai dinh B");
		else if(ac*ac+bc*bc==ab*ab)
			printf("==> La tam giac vuong tai dinh C");
		else printf("==> La tam giac thuong");
	}
};

int main() {
	Triangle triangle;
	triangle.nhap();
	while(true) {
		printf("\n\n\n-------------------Menu-------------------\n");
		printf("1. In ra toa do 3 dinh cua tam giac\n");
		printf("2. In ra do dai 3 canh cua tam giac\n");
		printf("3. Tinh chu vi\n");
		printf("4. Tinh dien tich\n");
		printf("5. Kiem tra loai tam giac\n");
		printf("0. Thoat chuong trinh\n");
		printf("------------------------------------------\n");
		printf("Nhap lua chon: ");
		int chon;
		scanf("%d", &chon);
		if(chon == 0) break;
		if(chon >= 1 && chon <= 5)
			switch(chon) {
				case 1: 
					triangle.in();
					break;
				case 2: 
					triangle.inCanh();
					break;
				case 3: 
					triangle.inChuvi();
					break;
				case 4: 
					triangle.inDienTich();
					break;
				case 5: 
					triangle.kiemTraTamGiac();
					break;
			}
		else printf("Nhap lai lua chon!\n");
	}
    return 0;
}