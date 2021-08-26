#include <stdio.h>

typedef struct Date
{
    int d, m, y;
} date;

int isLeapYear(int y)
{
    if (y % 400 == 0)
        return 1;
    if (y % 4 == 0 && y % 100 != 0)
        return 1;
    return 0;
}

// return 0 neu ngay loi, -1 la thang
int formatter(date t)
{
    if (t.m < 0 || t.m > 12)
        return -1;

    if (t.d < 0 || t.d > 31)
        return 0;

    switch (t.m)
    {
    case 2:
        if ((isLeapYear(t.y) && t.d > 29) || (!isLeapYear(t.y) && t.d > 28))
            return 0;
    case 4:
    case 6:
    case 9:
    case 11:
        if (t.d > 30)
            return 0;
    default:
        break;
    }

    return 1;
}

date Nhap()
{
    date value;
    printf("nhap thong tin ngay ( ngay/thang/nam ): ");
    scanf("%d%d%d", &value.d, &value.m, &value.y);

    while (formatter(value) == -1)
    {
        printf("Nhap thang khong hop le! vui long nhap lai: ");
        scanf("%d", &value.m);
    }

    while (formatter(value) == 0)
    {
        printf("\nNhap ngay khong hop le! Vui long nhap lai: ");
        scanf("%d", &value.d);
    }

    printf("Nhap thong tin hoan tat!\n");
    return value;
}

void getXuat(date t)
{
    printf("%d-%d-%d", t.d, t.m, t.y);
}

int getDayOfMonth(date t)
{
    switch (t.m)
    {
    case 2:
        if (isLeapYear(t.y))
            return 29;
        return 28;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        return 31;
    }
}

int getPivot(date t)
{
    if (t.m < 3)
    {
        t.y--;
        t.m += 12;
    }

    return 365 * t.y + t.y / 4 - t.y / 100 + t.y / 400 + (153 * t.m - 457) / 5 + t.d - 306;
}

int countDay(date pre, date next)
{
    return getPivot(next) - getPivot(pre);
}

int getDayOfWeek(date t)
{
    if (t.m < 3)
    {
        t.y--;
        t.m += 12;
    }

    int y = t.y % 100, // 2 chu cai dau cua Y
        c = t.y / 100; // 2 chu cai cuoi cua Y

    //chu nhat tra ve 1 ,thu 7 ve 0
    return (13 * (t.m + 1) / 5 + y / 4 + c / 4 + t.d + y - 2 * c) % 7;
}

date dayNext(date t)
{
    t.d++;
    if (formatter(t) == 0)
    {
        t.d = 1;
        t.m++;
    }

    if (formatter(t) == -1)
    {
        t.m = 1;
        t.y++;
    }
    return t;
}

int countWeek(date pre, date next)
{
    for (; getDayOfWeek(pre) != 2; pre = dayNext(pre))
        ;
    for (; getDayOfWeek(next) != 2; next = dayNext(next))
        ;

    return countDay(pre, next) / 7;
}

void amLich(int nam)
{
    printf("Nam am lich cua nam %d la: ", nam);
    switch (nam % 10)
    {
        case 0: printf("Canh"); break;
        case 1: printf("Tan"); break;
        case 2: printf("Nham"); break;
        case 3: printf("Quy");   break;
        case 4: printf("Giap"); break;
        case 5: printf("At");   break;
        case 6: printf("Binh"); break;
        case 7: printf("Dinh"); break;
        case 8: printf("Mau"); break;
        case 9: printf("Ky");   break;
    }

    printf(" ");

    switch (nam % 12)
    {
        case 0: printf("Than"); break;
        case 1: printf("Dau"); break;
        case 2: printf("Tuat"); break;
        case 3: printf("Hoi"); break;
        case 4: printf("Ty"); break;
        case 5: printf("Suu"); break;
        case 6: printf("Dan"); break;
        case 7: printf("Mao"); break;
        case 8: printf("Thin"); break;
        case 9: printf("Ty"); break;
        case 10: printf("Ngo"); break;
        case 11: printf("Mui"); break;
    }
    printf("\n");
}

int main()
{
    date d1 = Nhap(), d2 = Nhap();
    
    date begin;
    begin.d = begin.m = 1;
    begin.y = d1.y;

    printf("%d", countWeek(begin, d1));

    amLich(d1.y);
    amLich(d2.y);
    // int key = -1;
    // printf("=== Nhap lua chon cua ban ===\n");
    // printf("\nNhan 0 de thoat");
    // printf("\nNhan 1 de hien thi so ngay trong khoang hai ngay");
    // printf("\nNhan 2 de hien thi so tuan cua hai nam vua nhap");
    // printf("\nNhan 3 de nhap lai ngay thang");
    // printf("\nlua chon cua ban la : ");
    // scanf("%d", &key);

    // switch (key)
    // {
    // case 1:
    //     printf("So ngay giua hai ngay la: %d\n", countDay(d1, d2));
    //     break;
    // case 2:
    //     printf("So tuan cua hai nam la: %d\n", countWeek(d1, d2));
    //     break;
    // case 3:
    // {
    //     int t;
    //     printf("Nhap ngay muon doi (1 la ngay dau thu nhat, 2 la ngay thu hai): ");
    //     scanf("%d", &t);
    //     if (t == 1)
    //         d1 = Nhap();
    //     else if (t == 2)
    //         d2 = Nhap();
    //     else
    //         printf("So ngay nhap khong hop le\n");
    //     break;
    // }
    // }
}