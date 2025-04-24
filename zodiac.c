#include <stdio.h>

int tinhCan(int nam) {
    int canIndex = nam % 10;
    switch (canIndex) {
        case 0: return 4; // Canh
        case 1: return 4; // Tân
        case 2: return 5; // Nhâm
        case 3: return 5; // Quý
        case 4: return 1; // Giáp
        case 5: return 1; // Ất
        case 6: return 2; // Bính
        case 7: return 2; // Đinh
        case 8: return 3; // Mậu
        case 9: return 3; // Kỷ
        default: return 0;
    }
}

int tinhChi(int nam) {
    int chiIndex = nam % 12;
    switch (chiIndex) {
        case 0: return 0; // Thân
        case 1: return 0; // Dậu
        case 2: return 2; // Tuất
        case 3: return 2; // Hợi
        case 4: return 0; // Tý
        case 5: return 0; // Sửu
        case 6: return 1; // Dần
        case 7: return 1; // Mão
        case 8: return 2; // Thìn
        case 9: return 2; // Tỵ
        case 10: return 0; // Ngọ
        case 11: return 0; // Mùi
        default: return 0;
    }
}

char* xacDinhMenh(int tong) {
    if (tong > 5) {
        tong -= 5;
    }
    
    switch (tong) {
        case 1: return "Kim";
        case 2: return "Thuy";
        case 3: return "Hoa";
        case 4: return "Tho";
        case 5: return "Moc";
        default: return "Khong xac dinh";
    }
}

int main() {
    int nam;
    scanf("%d", &nam);
    
    int can = tinhCan(nam);
    int chi = tinhChi(nam);
    int tong = can + chi;
    
    char* menh = xacDinhMenh(tong);
    
    printf("%s\n", menh);
    
    return 0;
}