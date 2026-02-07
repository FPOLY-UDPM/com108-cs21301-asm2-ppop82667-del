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

// ===== CHỨC NĂNG 1: KIỂM TRA SỐ =====
void chucNang1() {
    float x;
    printf("Nhap so x: ");
    scanf("%f", &x);

    // Kiểm tra số nguyên
    if (x == (int)x) {
        int n = (int)x; // ép kiểu float -> int
        printf("So %d la so nguyen.\n", n);

        // Kiểm tra số nguyên tố
        int dem = 0;
        if (n < 2) {
            printf("Khong phai so nguyen to.\n");
        } else {
            for (int i = 1; i <= n; i++) {
                if (n % i == 0) {
                    dem++;
                }
            }
            if (dem == 2) {
                printf("La so nguyen to.\n");
            } else {
                printf("Khong phai so nguyen to.\n");
            }
        }

        // Kiểm tra số chính phương
        int can = sqrt(n);
        if (can * can == n) {
            printf("La so chinh phuong.\n");
        } else {
            printf("Khong phai so chinh phuong.\n");
        }

    } else {
        printf("So %.2f khong phai la so nguyen.\n", x);
    }
}

int main() {
    int chonChucNang;

    do {
        printf("Chon chuc nang:\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. Tim Uoc so chung va boi so chung cua 2 so\n");
        printf("3. Tinh tien cho quan Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Chuc nang doi tien\n");
        printf("6. Tinh lai suat vay ngan hang vay tra gop\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep thong tin sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &chonChucNang);

        switch (chonChucNang) {
            case 1:
                printf("DA CHON CHUC NANG 1: KIEM TRA SO NGUYEN\n");
                chucNang1(); // GỌI CHỨC NĂNG 1
                break;
            case 2:
                printf("DA CHON CHUC NANG 2: TIM UOC SO CHUNG VA BOI SO CHUNG CUA 2 SO\n");
                break;
            case 3:
                printf("DA CHON CHUC NANG 3: TINH TIEN CHO QUAN KARAOKE\n");
                break;
            case 4:
                printf("DA CHON CHUC NANG 4: TINH TIEN DIEN\n");
                break;
            case 5:
                printf("DA CHON CHUC NANG 5: DOI TIEN\n");
                break;
            case 6:
                printf("DA CHON CHUC NANG 6: TINH LAI SUAT VAY NGAN HANG VAY TRA GOP\n");
                break;
            case 7:
                printf("DA CHON CHUC NANG 7: VAY TIEN MUA XE\n");
                break;
            case 8:
                printf("DA CHON CHUC NANG 8: SAP XEP THONG TIN SINH VIEN\n");
                break;
            case 9:
                printf("DA CHON CHUC NANG 9: GAME FPOLY-LOTT\n");
                break;
            case 10:
                printf("DA CHON CHUC NANG 10: TINH TOAN PHAN SO\n");
                break;
            case 0:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (chonChucNang != 0);

    return 0;
}
