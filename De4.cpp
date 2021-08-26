#include <iostream>
#include <stdio.h>
#include<string.h>
#include<conio.h>
#include <stdbool.h>

int main() {
	
char S[100];   // chuoi nhap vao
char ch ;  // khai bao bien ch
int chonMenu();
char menu(char S[], char ch);
char hienthichuoinhap(char s[]);///// Ham cau a
char solanxuathien (char s[], char ch); /// Ham cau b


char TimKyTuTrongChuoi(char s[],char s2); /////////////////////Ham tim vi tri xuat hien

int remove_extra_whitespaces(char* input, char* output); ////////////////////ham cat khoang trang
char output[0x255] = "NO_OUTPUT_YET";


int WordCount(char str[], int length) ;///////////////Ham dem so tu
 


int timViTri(char* str, int* length); // ham tim vi tri tu dai nhat trong xau
void hienThiTu(char *str, int pos, int length); // ham hien thi tu
bool khoangTrang(char c); // kiem tra ki tu co phai khoang trang hay khong


// Câu 1: nhap vao chuoi ky tu
printf("1: Nhap vao chuoi ky tu S : ");                           
fgets(S, sizeof(S), stdin);  // ham nay co the nhap khoang trang


printf("2: Nhap vao 1 ky tu ch: ");   // nhap vao ky tu ch
scanf("%c", &ch);

printf("\n");
    printf("----------------------------------------MENU: ---------------------------------------- \n\n");
    printf("                          1. Hien thi chuoi vua nhap \n");
    printf("                          2. So lan xuat hien ky tu \n");
    printf("                          3. Bo ky tu khoang trang \n");
    printf("                          4. Dem so tu co trong chuoi \n");
    printf("                          0. Thoat\n\n");
 while(1){
		
        int cn = chonMenu();
        int length = strlen(S) - 1; //////////////Khai bao bien cho cau C dem so tu
        int len = 0;  /////////////////////////KHai bao bien cho cau D tim tu dai nhat
		int pos = timViTri(S, &len); ////////////////////////khai bao bien cho cau D tim tu dai nhat
        
        if(cn !=0 && cn !=1 && cn !=2 && cn !=3 && cn !=4) // chon khac 012345 thi khong hop le
        {
        	printf("\nLua chon khong hop le. Xin kiem tra lai !");
        	system("pause");
        	system("cls");
        }
        else if( cn ==0 && cn ==1 && cn ==2 && cn ==3 && cn ==4)
        continue;
        switch(cn){
            case 1:
				menu(S,ch);////////////////////////////////////////menu(S,ch); bo ham menu(S,ch) khong cho chay
                hienthichuoinhap(S); /////////////////goi ham cau a
                break;
            case 2:
				menu(S,ch);
                solanxuathien(S,ch); ///////////////////Cau b goi ham so lan xuat hien
                 TimKyTuTrongChuoi(S,ch);  ///////////////////////////////Cau b Goi ham tim vi tri xuat hien
                break;
            case 3:
				menu(S,ch);
				 remove_extra_whitespaces(S,output);  ///////////////goi ham xoa khoang trang
				 printf("\n");
   				 printf("Cau c: Chuoi ban dau la: %s \n Chuoi sau khi xoa la: %s\n", S, output);
                break;
            case 4:
				menu(S,ch);
   				 S[length] = '\0';
   				 printf("\n");
   				 printf("Cau d: So tu trong chuoi S la:  \"%s\" la %d \n", S, WordCount(S, length));
   			    			
				hienThiTu(S, pos, len);
				break;
				
            case 0:     ///////////////////bam phim 0 thi thoat chuong trinh
                exit(0);
                break;
		}
		}

    }

////////////////////////////////////////////////Ham tao menu chuong trinh
char menu(char S[], char ch){
	system("cls");

	printf("\n");
    printf("----------------------------------------MENU: ---------------------------------------- \n\n");
    printf("                          1. Hien thi chuoi vua nhap \n");
    printf("                          2. So lan xuat hien ky tu \n");
    printf("                          3. Bo ky tu khoang trang \n");
    printf("                          4. Dem so tu co trong chuoi \n");
    printf("                          0. Thoat\n\n");
	printf("1: Nhap vao chuoi ky tu S : %s", S);   
	printf("2: Nhap vao 1 ky tu ch: %c", ch);
}

int chonMenu(){
	
 	printf("\n");
    printf("                       Moi ban lua chon so tu [0 den 4]: ");
    int cn;
    scanf("%d",&cn);
    return cn;
}

////////////////////////////////////Ham Cau a: Hien thi chuoi ky tu vua nhap 

char hienthichuoinhap(char s[]) {
printf("\n");
printf(" Cau a: Chuoi ky tu do là:  %s \n ", s ); // hien thi ra chuoi ky tu ch
}


char solanxuathien (char S[], char ch) {
int count = 0;   
int dem=0;
int i=0;

   while(S[i] != '\0') {            // kiem tra chuoi co rong khong
      if(S[i] == ch)                // duyet chuoi ky tu ,kiem tra ky tu ch co trong chuoi khong
         count++;                  // tang bien dem
      i++;                        // mot lan duyet mot chu trong chuoi

   }

 if(count > 0) {
 		printf("\n");
        printf("Cau b: Ky tu %c xuat hien %d lan trong chuoi %s  \n", ch, count, S);
        	printf(" %c  \n",  dem);
	
		 }  ///// hien thi thong bao so lan xuat hien cua ky tu ch      
        
        else {
        	printf("\n");
        printf("Cau b: Ky tu %c khong co mat trong chuoi %s \n", ch, S);  //// nguoc lai neu khong co thi thong bao khong co ky tu ch
   }
   
   
   
    
}

/////////////////////////////////////// hàm xóa khoang trang //////////////////////////////////////////////////////////////

int remove_extra_whitespaces(char* input, char* output)
{
    int inputIndex = 0;
    int outputIndex = 0;
    while(input[inputIndex] != '\0')
    {
        output[outputIndex] = input[inputIndex];

        if(input[inputIndex] == ' ')
        {
            while(input[inputIndex + 1] == ' ')
            {
                // skip over any extra spaces
                inputIndex++;
            }
        }

        outputIndex++;
        inputIndex++;
    }

    // null-terminate output
    output[outputIndex] = '\0';
}
 
char TimKyTuTrongChuoi(char s[],char s2)              /////////////////////////Ham tim vi tri xuat hien

{
    int i;
    int dem=0;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]==s2)
            {
                printf("Ky tu %c xuat hien o vi tri vi tri thu: %d\n",s[i],i);
                dem++;
            }
    }
         if(dem==0)
            {
                printf("Ky tu muon tim khong co trong chuoi!");
            }

}


int WordCount(char str[], int length) ///////////////////////////////////Ham den so tu trong chuoi
{
    int word = (str[0] != ' ');
    for (int i = 0; i < length - 1; i++)
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
        {
            word++;
        }
    }
    return word;
}

//////////////////////////////////////Tim tu dai nhat

bool khoangTrang(char c) {
	return c == ' ' || c == '\t' || c == '\n';
}

void hienThiTu(char *str, int pos, int length) {
	printf("Tu dai nhat:");
	int i;
	for(i = pos; i < pos + length; i++) {

		printf("%c", str[i]);
	}

}

int timViTri(char* str, int* length) {
	int len = 0;
	int lenMax = 0;
	int pos = 0;
	int posCurrent = 0;
	int size = strlen(str);
	int i;
	for(i = 0; i< size; i++) {
		if(!khoangTrang(str[i])) { 
			posCurrent = i - len;
			len++;
		} else {
			if(len > lenMax) {
				lenMax = len;
				pos = posCurrent;
				
			}
			len = 0;
		}
	}
	
	*length = lenMax;
	return pos;
}