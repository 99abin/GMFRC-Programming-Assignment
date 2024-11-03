#include <iostream>
#include <cstdio>

using namespace std;

struct Mahasiswa {
    char namaDepan[50];
    char namaBelakang[50];
    char niu[20];
    int usia;
};

int main() {
    Mahasiswa mhs; 

    printf("Masukkan nama depan mahasiswa: ");
    scanf("%s", mhs.namaDepan);

    printf("Masukkan nama belakang mahasiswa: ");
    scanf("%s", mhs.namaBelakang);

    printf("Masukkan NIU mahasiswa: ");
    scanf("%s", mhs.niu);

    printf("Masukkan usia mahasiswa: ");
    scanf("%d", &mhs.usia);

    printf("%s %s %s %d\n", mhs.namaDepan, mhs.namaBelakang, mhs.niu, mhs.usia);

    return 0;
}
