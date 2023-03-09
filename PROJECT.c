#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#define MAX_KAMAR 15
#define MAX_NAMA_LENGTH 50
#define MAX_USERS 2
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20

struct User {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
};

int main() {
    system("cls");
    User users[MAX_USERS];
    int user_count = 0;
    int i;

    for (i = 0; i < MAX_KAMAR; i++){
        kamar[i].nomor = 100 + (i+1);
        kamar[i].kosong = true;
        kamar[i].harga = 300000;
        kamar[i].jumlah_inap = 0;
    }

    int pilihan_menu;
    bool login_berhasil = false; // default : false
    char username_terlogin[MAX_USERNAME_LENGTH];

    do {
             //gotoxy(100,25);
        printf("\n=== MENU UTAMA ===\n");
        if (login_berhasil) {
            printf("1. Logout\n");
            printf("2. Tampil Kamar (101-110)\n");
            printf("3. Tambah Nama/Penginap & Pemesanan\n");
            printf("4. Total dan Tampil Harga Keseluruhan\n");

        } else {
            printf("1. Login\n");
            printf("2. Register\n");
        }

        printf("0. Keluar\n");
        printf("Pilih menu: ");
        fflush(stdin);
        scanf("%d", &pilihan_menu);

        switch (pilihan_menu) {

           case 1:
                system("cls");
                if (login_berhasil) {
                    printf("Anda berhasil logout\n");
                    system("pause > null");
                    system("cls");
                    login_berhasil = false;
                    strcpy(username_terlogin, "");
                } else {
                    char username[MAX_USERNAME_LENGTH];
                    char password[MAX_PASSWORD_LENGTH];
                    printf("\n=== LOGIN ===\n");
                    printf("Username: ");
                    scanf("%s", username);
                    printf("Password: ");
                    i = 0;
                while (1) {
                char c = getch();
                    if (c == '\r') {
                password[i] = '\0';
                break;
                    } else if (c == '\b') {
                    if (i > 0) {
                    i--;
                    printf("\b \b");
                    }
                } else {
                password[i] = c;
                i++;
                printf("*");
                    }
                }
                printf("\n");
					int i;
                    bool user_ditemukan = false;
                    for (i = 0; i < user_count; i++) {
                        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
                            user_ditemukan = true;
                            break;
                        }
                    }
                    if (user_ditemukan) {
                        printf("Login berhasil\n");
                        system("pause > null");
                        system("cls");
                        login_berhasil = true;
                        strcpy(username_terlogin, username);
                    } else {
                        printf("Maaf, username atau password salah\n");
                        system("pause > null");
                        system("cls");
                    }
                }
                break;
            case 2:
                system("cls");
                if (login_berhasil) {

                    tampil_kamar(kamar);

                    system("pause > null");
                    system("cls");
                }
				else {
                    char username[MAX_USERNAME_LENGTH];
                    char password[MAX_PASSWORD_LENGTH];
                    printf("\n=== REGISTER ===\n");
                    printf("Username: ");
                    scanf("%s", username);
                    printf("Password: ");
                    scanf("%s", password);
                    if (user_count == MAX_USERS) {
                        printf("Maaf, sudah mencapai batas jumlah user\n");
                        system("pause > null");
                        system("cls");
                    } else {
                        bool user_ada = false;
                        int i;
                        for (i = 0; i < user_count; i++) {
                            if (strcmp(users[i].username, username) == 0) {
                                user_ada = true;
                                break;
                            }
                        }
                        if (user_ada) {
                            printf("Maaf, username sudah terdaftar\n");
                            system("pause > null");
                            system("cls");
                        } else {
                            strcpy(users[user_count].username, username);
                            strcpy(users[user_count].password, password);
                            user_count++;
                            printf("Registrasi berhasil\n");
                            system("pause > null");
                            system("cls");
                        }
                    }
                }
                break;

			case 3:
                system("cls");
                if (login_berhasil) {


					pemesanan();

                    system("pause > null");
                    system("cls");
                }
				else {
                    char username[MAX_USERNAME_LENGTH];
                    char password[MAX_PASSWORD_LENGTH];
                    printf("\n=== REGISTER ===\n");
                    printf("Username: ");
                    scanf("%s", username);
                    printf("Password: ");
                    scanf("%s", password);
                    if (user_count == MAX_USERS) {
                        printf("Maaf, sudah mencapai batas jumlah user\n");
                        system("pause > null");
                        system("cls");
                    } else {
                        bool user_ada = false;
                        int i;
                        for (i = 0; i < user_count; i++) {
                            if (strcmp(users[i].username, username) == 0) {
                                user_ada = true;
                                break;
                            }
                        }
                        if (user_ada) {
                            printf("Maaf, username sudah terdaftar\n");
                            system("pause > null");
                            system("cls");
                        } else {
                            strcpy(users[user_count].username, username);
                            strcpy(users[user_count].password, password);
                            user_count++;
                            printf("Registrasi berhasil\n");
                            system("pause > null");
                            system("cls");
                        }
                    }
                }
                break;

            case 4:
                system("cls");
                if (login_berhasil) {

                	view_total();

                    system("pause > null");
                    system("cls");
                }
				else {
                    char username[MAX_USERNAME_LENGTH];
                    char password[MAX_PASSWORD_LENGTH];
                    printf("\n=== REGISTER ===\n");
                    printf("Username: ");
                    scanf("%s", username);
                    printf("Password: ");
                    scanf("%s", password);
                    if (user_count == MAX_USERS) {
                        printf("Maaf, sudah mencapai batas jumlah user\n");
                        system("pause > null");
                        system("cls");
                    } else {
                        bool user_ada = false;
                        int i;
                        for (i = 0; i < user_count; i++) {
                            if (strcmp(users[i].username, username) == 0) {
                                user_ada = true;
                                break;
                            }
                        }
                        if (user_ada) {
                            printf("Maaf, username sudah terdaftar\n");
                            system("pause > null");
                            system("cls");
                        } else {
                            strcpy(users[user_count].username, username);
                            strcpy(users[user_count].password, password);
                            user_count++;
                            printf("Registrasi berhasil\n");
                            system("pause > null");
                            system("cls");
                        }
                    }
                }
                break;

            case 0:
                system ("cls");
            	printf("\n---Developer : ");
            	printf("\n Agustian Mahardika 672022177\n Dinda Ayu Ramadhani 672022285\n Lintang Satrio Gutomo 672022286\n Julios Gibral Ragananta 672022291\n Syahdan Satria Putra 672022311");
            	printf("\n wTerimakasih sudah menggunakan program ini!\n");
            	break;

            default:
                printf("Maaf, pilihan menu tidak tersedia\n");
                system("pause > null");
                system("cls");
                break;
        }
    } while (pilihan_menu != 0);

    return 0;
}
