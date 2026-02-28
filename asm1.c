/******************************************************************************
 * Họ và tên: [Huỳnh Việt Tiến]
 * MSSV:      [PS47459]
 * Lớp:       [CS21301]
 *****************************************************************************/

// Tạo file asm2.c và hoàn thiện nội dung Assignment từ nội dung file asm1.c


// Danh sách các chức năng trong ASM1:
// 1. Chức năng số 1: Kiểm tra số nguyên
// 2. Chức năng số 2. Tìm Ước số chung và bội số chung của 2 số 
// 3. Chức năng số 3: Chương trình tính tiền cho quán Karaoke
// 4. Chức năng số 4: Tính tiền điện 
// 5. Chức năng số 5: Chức năng đổi tiền 
// 6. Chức năng số 6: Xây dựng chức năng tính lãi suất vay ngân hàng vay trả góp 
// 7. Chức năng số 7: Xây dựng chương trình vay tiền mua xe
// 8. Chức năng số 8: Sắp xếp thông tin sinh viên
// 9. Chức năng số 9: Xây dựng game FPOLY-LOTT
// 10. Chức năng số 10: Xây dựng chương trình tính toán phân số 
// Viết chương trình C thực hiện các chức năng trên
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// ================= CHỨC NĂNG 1 =================
void kiemTraSo() {
    int x;
    printf("Nhap so nguyen x: ");
    scanf("%d", &x);

    printf("So %d la so nguyen.\n", x);

    // Kiem tra so nguyen to
    if(x < 2) {
        printf("Khong phai so nguyen to.\n");
    } else {
        int laNguyenTo = 1;
        for(int i = 2; i <= sqrt(x); i++) {
            if(x % i == 0) {
                laNguyenTo = 0;
                break;
            }
        }
        if(laNguyenTo) printf("La so nguyen to.\n");
        else printf("Khong phai so nguyen to.\n");
    }

    // Kiem tra so chinh phuong
    if(x >= 0) {
        int can = sqrt(x);
        if(can * can == x) printf("La so chinh phuong.\n");
        else printf("Khong phai so chinh phuong.\n");
    } else {
        printf("Khong phai so chinh phuong.\n");
    }
}

// ================= CHỨC NĂNG 2 =================
void uclnBcnn() {
    int x, y;
    printf("Nhap x: ");
    scanf("%d", &x);
    printf("Nhap y: ");
    scanf("%d", &y);

    int a = abs(x);
    int b = abs(y);

    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }

    int ucln = a;
    int bcnn = abs(x * y) / ucln;

    printf("UCLN = %d\n", ucln);
    printf("BCNN = %d\n", bcnn);
}

// ================= CHỨC NĂNG 3 =================
void tinhTienKaraoke() {
    int start, end;
    printf("Nhap gio bat dau (12-23): ");
    scanf("%d", &start);
    printf("Nhap gio ket thuc (12-23): ");
    scanf("%d", &end);

    if(start < 12 || end > 23 || start >= end) {
        printf("Gio khong hop le!\n");
        return;
    }

    int gio = end - start;
    double tien;

    if(gio <= 3)
        tien = gio * 150000;
    else
        tien = 3 * 150000 + (gio - 3) * 150000 * 0.7;

    if(start >= 14 && start <= 17)
        tien *= 0.9;

    printf("Tien can tra: %.0lf VND\n", tien);
}

// ================= CHỨC NĂNG 4 =================
void tinhTienDien() {
    int kwh;
    printf("Nhap so kWh: ");
    scanf("%d", &kwh);

    double tien = 0;

    if(kwh <= 50) tien = kwh * 1678;
    else if(kwh <= 100) tien = 50 * 1678 + (kwh - 50) * 1734;
    else if(kwh <= 200) tien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    else if(kwh <= 300) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    else if(kwh <= 400) tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    else tien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;

    printf("Tien dien: %.0lf VND\n", tien);
}

// ================= CHỨC NĂNG 5 =================
void doiTien() {
    int tien;
    printf("Nhap so tien: ");
    scanf("%d", &tien);

    int menhGia[] = {500,200,100,50,20,10,5,2,1};

    for(int i = 0; i < 9; i++) {
        int soTo = tien / menhGia[i];
        if(soTo > 0) {
            printf("%d to %d\n", soTo, menhGia[i]);
            tien %= menhGia[i];
        }
    }
}

// ================= CHỨC NĂNG 6 =================
void laiSuatVay() {
    double tienVay;
    printf("Nhap so tien vay: ");
    scanf("%lf", &tienVay);

    double gocConLai = tienVay;
    double gocThang = tienVay / 12;

    printf("Thang | Goc | Lai | Tong\n");

    for(int i = 1; i <= 12; i++) {
        double laiThang = gocConLai * 0.05;
        double tong = gocThang + laiThang;

        printf("%5d | %.0lf | %.0lf | %.0lf\n", i, gocThang, laiThang, tong);

        gocConLai -= gocThang;
    }
}

// ================= CHỨC NĂNG 7 =================
void vayMuaXe() {
    double giaXe = 500000000;
    int phanTramVay;

    printf("Nhap %% vay (VD: 80): ");
    scanf("%d", &phanTramVay);

    double tienVay = giaXe * phanTramVay / 100.0;
    double traTruoc = giaXe - tienVay;

    int thang = 24;
    double laiThang = 0.072 / 12;

    double traThang = (tienVay / thang) + (tienVay * laiThang);

    printf("Tien tra truoc: %.0lf VND\n", traTruoc);
    printf("Tien tra moi thang: %.0lf VND\n", traThang);
}

// ================= CHỨC NĂNG 8 =================
void sapXepSinhVien() {
    int n;
    printf("Nhap so sinh vien: ");
    scanf("%d", &n);

    char ten[50][50];
    float diem[50];

    for(int i = 0; i < n; i++) {
        printf("Nhap ten SV %d: ", i+1);
        scanf("%s", ten[i]);
        printf("Nhap diem: ");
        scanf("%f", &diem[i]);
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(diem[i] < diem[j]) {
                float tmp = diem[i];
                diem[i] = diem[j];
                diem[j] = tmp;

                char t[50];
                strcpy(t, ten[i]);
                strcpy(ten[i], ten[j]);
                strcpy(ten[j], t);
            }
        }
    }

    printf("Danh sach sinh vien:\n");
    for(int i = 0; i < n; i++) {
        printf("%s - %.2f - ", ten[i], diem[i]);
        if(diem[i] >= 9) printf("Xuat sac\n");
        else if(diem[i] >= 8) printf("Gioi\n");
        else if(diem[i] >= 6.5) printf("Kha\n");
        else if(diem[i] >= 5) printf("Trung binh\n");
        else printf("Yeu\n");
    }
}

// ================= CHỨC NĂNG 9 =================
void fpolyLott() {
    srand(time(NULL));
    int a = rand() % 15 + 1;
    int b;

    do {
        b = rand() % 15 + 1;
    } while(b == a);

    int x, y;
    printf("Nhap so thu 1 (1-15): ");
    scanf("%d", &x);
    printf("Nhap so thu 2 (1-15): ");
    scanf("%d", &y);

    int dem = 0;
    if(x == a || x == b) dem++;
    if(y == a || y == b) dem++;

    printf("So he thong: %d %d\n", a, b);

    if(dem == 0) printf("Chuc ban may man lan sau!\n");
    else if(dem == 1) printf("Chuc mung ban trung giai nhi!\n");
    else printf("Chuc mung ban trung giai nhat!\n");
}

// ================= CHỨC NĂNG 10 =================
int ucln(int a, int b){
    while(b != 0){
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void tinhPhanSo() {
    int a,b,c,d;
    printf("Nhap phan so 1 (a b): ");
    scanf("%d%d", &a, &b);
    printf("Nhap phan so 2 (c d): ");
    scanf("%d%d", &c, &d);

    if(b == 0 || d == 0){
        printf("Mau so khong duoc bang 0!\n");
        return;
    }

    int tu = a*d + b*c;
    int mau = b*d;
    int u = ucln(abs(tu), abs(mau));
    printf("Tong = %d/%d\n", tu/u, mau/u);
}

// ================= MENU =================
int main() {
    int chon;

    do {
        printf("\n========= MENU =========\n");
        printf("1. Kiem tra so\n");
        printf("2. UCLN & BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Lai suat vay\n");
        printf("7. Vay mua xe\n");
        printf("8. Sap xep sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh phan so\n");
        printf("0. Thoat\n");
        printf("========================\n");
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        switch(chon) {
            case 1: kiemTraSo(); break;
            case 2: uclnBcnn(); break;
            case 3: tinhTienKaraoke(); break;
            case 4: tinhTienDien(); break;
            case 5: doiTien(); break;
            case 6: laiSuatVay(); break;
            case 7: vayMuaXe(); break;
            case 8: sapXepSinhVien(); break;
            case 9: fpolyLott(); break;
            case 10: tinhPhanSo(); break;
            case 0: printf("Thoat chuong trinh!\n"); break;
            default: printf("Lua chon sai!\n");
        }

    } while(chon != 0);

    return 0;
}