#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
 
 
struct SinhVien{
    char ten[50];
    char gioitinh[5];
    int tuoi;
    int MSSV;
    float diemtoan, diemly, diemhoa, diemanhvan;
    float diemtrungbinh;
};
 void nhap(SinhVien &sv);
void nhapN(SinhVien a[], int n);
void xuat(SinhVien sv);
void xuatN(SinhVien a[], int n);
void tinhdiemtrungbinh(SinhVien &sv);
void sapxep(SinhVien a[], int n);
void xeploai(SinhVien a);
void xeploaiN(SinhVien a[], int n);
void xuatFile(SinhVien a[], int n, char fileName[]);
void tinhDTB(SinhVien &sv)
{
    sv.diemtrungbinh = (sv.diemhoa + sv.diemly + sv.diemtoan + sv.diemanhvan)/4;    
}
void nhap(SinhVien &sv){
	printf("\nNhap MSSV: ");
	scanf("%d", &sv.MSSV);
    printf("\nNhap ho va ten: "); 
	fflush(stdin); 
	gets(sv.ten);
    printf("\nNhap gioi tinh: "); 
	gets(sv.gioitinh);
    printf("\nNhap tuoi: "); 
	scanf("%d", &sv.tuoi);
    printf("\nNhap diem cac mon: ");
    printf("\nMon Toan: "); 
	scanf("%f", &sv.diemtoan);
    printf("\nMon Ly: "); 
	scanf("%f", &sv.diemly);
    printf("\nMon Hoa: "); 
	scanf("%f", &sv.diemhoa);
	printf("\nMon Anh Van: "); 
	scanf("%f", &sv.diemanhvan);
    tinhDTB(sv);
}
 void nhapN(SinhVien a[], int n){
    for(int i = 0; i< n; ++i){
        printf("\nSinh vien thu %d:", i+1);
        nhap(a[i]);
    }
}
 
void xuat(SinhVien sv){
	printf("\nMSSV: %d", sv.MSSV);
    printf("\nHo ten sinh vien: %s", sv.ten);
    printf("\nGioi tinh: %s", sv.gioitinh);
    printf("\nTuoi: %d", sv.tuoi);
    printf("\nDiem Toan: %.2f", sv.diemtoan);
    printf("\nDiem Ly: %.2f", sv.diemly);
    printf("\nDiem Hoa: %.2f", sv.diemhoa);
    printf("\nDiem Anh Van: %.2f", sv.diemanhvan);
    printf("\nDiem trung binh: %.2f\n", sv.diemtrungbinh);
}
 void xuatN(SinhVien a[], int n){
    for(int i = 0;i < n;++i){
        printf("\nThong tin sinh vien thu %d:", i+1);
        xuat(a[i]);
    }
}
 void sapxep(SinhVien a[], int n){
    SinhVien d;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(a[i].diemtrungbinh > a[j].diemtrungbinh){
                d = a[i];
                a[i] = a[j];
                a[j] = d;
            }
        }
    }
}
void xeploai(SinhVien sv){
    if(sv.diemtrungbinh >= 8) 
	printf("Gioi");
    else if(sv.diemtrungbinh >= 6.5) 
	printf("Kha");
    else if(sv.diemtrungbinh >= 4)
	printf("Trung binh");
    else 
	printf("Yeu");
}
 void xeploaiN(SinhVien a[], int n){
    for(int i = 0;i < n;++i){
        printf("\nXep loai cua SV thu %d la: ", i+1);
        xeploai(a[i]);
    }
}
void xuatFile(SinhVien a[], int n, char fileName[])
{
    FILE * fp;
    fp = fopen (fileName,"w");
    fprintf(fp, "%20s%5s%5s%10s%10s%10s%10s%10s\n", "Ho Ten","Gioitinh", "Tuoi", "DToan", "DLy", "DHoa", "Danhvan", "DTB");
    for(int i = 0;i < n;i++){
        fprintf(fp, "%20s%5s%5d%10f%10f%10f%10f%10f\n", a[i].ten, a[i].gioitinh, a[i].tuoi, a[i].diemtoan, a[i].diemly, a[i].diemhoa, a[i].diemanhvan, a[i].diemtrungbinh);
    }
    fclose (fp);
}

int main(){
    int c;
    char fileName[] = "DSSV.txt";
    int n;
    bool daNhap = false;
    do{
        printf("\nNhap so luong sinh vien: "); scanf("%d", &n);
    }while(n <= 0);
    SinhVien a[n];
    while(true){
        system("cls");
        printf("        MENU QUAN LY SINH VIEN            \n");
        printf("chon 1. Nhap thong tin sinh vien     \n");
        printf("chon 2. In thong tin sinh vien       \n");
        printf("chon 3. Sap xep sinh vien theo DTB   \n");
        printf("chon 4. Xep loai sinh vien           \n");
        printf("chon 5. Xuat file danh sach sinh vien\n");
        printf("chon 6. Thoat                        \n");  
        printf("       moi ban nhap lua chon        \n");               
        scanf("%d",&c);
        switch(c){
            case 1:
                printf("\nBan da chon nhap thong tin sinh vien!\n");
                nhapN(a, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon in thong tin sinh vien!\n");
                    xuatN(a, n);
                }else{
                    printf("\nNhap thong tin sinh vien truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap xep sinh vien theo DTB!\n");
                    sapxep(a, n);
                    xuatN(a, n);
                }else{
                    printf("\nNhap thong tin sinh vien truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 4:
                if(daNhap){
                    printf("\nBan da chon thoat xep loai sinh vien!\n");
                    xeploaiN(a, n);
                }else{
                    printf("\nNhap thong tin sinh vien truoc!!!!");
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 5:
                if(daNhap){
                    printf("\nBan da chon xuat danh sach sinh vien!");
                    xuatFile(a, n, fileName);
                }else{
                    printf("\nNhap thong tin sinh vien truoc!!!!");
                }
                printf("\nXuat danh sach  thanh cong vao file %s!", fileName);
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 6:
                printf("\nBan da chon thoat chuong trinh!");
                getch();
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
}
 

