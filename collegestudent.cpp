#include <iostream>
#include <cstdio>

using namespace std;

// Structure to represent a student (Mahasiswa)
struct Mahasiswa {
    char namaDepan[50];   // Array to store the first name of the student
    char namaBelakang[50]; // Array to store the last name of the student
    char niu[20];         // Array to store the NIU (Nomor Induk Universitas) of the student
    int usia;             // Variable to store the age of the student
};

int main() {
    Mahasiswa mhs; // Create an instance of the Mahasiswa structure

    // Prompt the user to enter the first name of the student
    printf("Masukkan nama depan mahasiswa: ");
    scanf("%s", mhs.namaDepan); // Read the first name

    // Prompt the user to enter the last name of the student
    printf("Masukkan nama belakang mahasiswa: ");
    scanf("%s", mhs.namaBelakang); // Read the last name

    // Prompt the user to enter the NIU of the student
    printf("Masukkan NIU mahasiswa: ");
    scanf("%s", mhs.niu); // Read the NIU

    // Prompt the user to enter the age of the student
    printf("Masukkan usia mahasiswa: ");
    scanf("%d", &mhs.usia); // Read the age

    // Print the details of the student
    printf("%s %s %s %d\n", mhs.namaDepan, mhs.namaBelakang, mhs.niu, mhs.usia);

    return 0; // End of the program
}
