#include <iostream>
#include <cstdio> 

using namespace std;

int main() {
    double harga, subtotal = 0.0, uangDibayar, kembalian;
    char input[10];

    while (true) {
        cout << "Masukkan harga barang (atau ketik 'selesai' untuk menghentikan): ";
        scanf("%s", input);

        if (strcmp(input, "selesai") == 0) {
            break;
        }

        harga = atof(input);

        subtotal += harga;
    }

    printf("Subtotal: %.2f\n", subtotal);

    printf("Masukkan uang yang dibayarkan: ");
    scanf("%lf", &uangDibayar);

    kembalian = uangDibayar - subtotal;

    printf("Total harga: %.2f\n", subtotal);
    printf("Uang yang dibayarkan: %.2f\n", uangDibayar);
    printf("Kembalian: %.2f\n", kembalian);

    return 0;
}