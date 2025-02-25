#include <iostream>
#include <cstdio> 

using namespace std;

int main() {
    // Variables to store the price of items, subtotal, amount paid, and change
    double harga, subtotal = 0.0, uangDibayar, kembalian;
    char input[10]; // Array to store user input

    // Infinite loop to continuously accept item prices
    while (true) {
        cout << "Masukkan harga barang (atau ketik 'selesai' untuk menghentikan): ";
        scanf("%s", input); // Read user input as a string

        // Check if the user wants to finish inputting prices
        if (strcmp(input, "selesai") == 0) {
            break; // Exit the loop if the user types 'selesai'
        }

        // Convert the input string to a double and add it to the subtotal
        harga = atof(input);
        subtotal += harga; // Update the subtotal with the new price
    }

    // Print the subtotal of all items
    printf("Subtotal: %.2f\n", subtotal);

    // Prompt the user to enter the amount paid
    printf("Masukkan uang yang dibayarkan: ");
    scanf("%lf", &uangDibayar); // Read the amount paid

    // Calculate the change to be returned
    kembalian = uangDibayar - subtotal;

    // Print the total price, amount paid, and change
    printf("Total harga: %.2f\n", subtotal);
    printf("Uang yang dibayarkan: %.2f\n", uangDibayar);
    printf("Kembalian: %.2f\n", kembalian);

    return 0; // End of the program
}
