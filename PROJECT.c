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
struct Kamar {
    int nomor;
    int harga;
    int jumlah_inap;
    bool kosong;
    char nama_penginap[MAX_NAMA_LENGTH];
};

typedef struct User User;
struct Kamar kamar[MAX_KAMAR];

void gotoxy(int x, int y){
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    }

void tampil_kamar(struct Kamar kamar[]) {
    printf("\n=== DAFTAR KAMAR ===\n");
    printf("Nomor\tStatus\tPenginap\n");

    int i;
    for (i = 0; i < MAX_KAMAR; i++) {
        if (kamar[i].kosong) {
            printf(" %-6d%-16s%-s\n", kamar[i].nomor, " Kosong", "-");
        } else {
            printf(" %-6d%-9s%-s\n", kamar[i].nomor, " Isi", kamar[i].nama_penginap);
        }
    }
    system("pause > null");
    system("cls");
}

void pemesanan(){
	if(cek_kamar(kamar) == 1){
    	char nama[MAX_NAMA_LENGTH];
    	int i, pilih_kamar, harga_kamar, jumlah_inap;
		printf("\nKamar Tersedia!\n");
    	printf("Nama Penginap : ");
    	fflush(stdin);gets(nama);fflush(stdin); printf("\n");

    	printf(" .:: Daftar Kamar ::. \n");
    	for (i = 0; i < MAX_KAMAR; i++ ){
    		if(kamar[i].kosong) {
    			printf("%d. Kamar %d (Tersedia) \n", i+1, kamar[i].nomor);
			} else {
				printf("%d. Kamar %d (Tidak Tersedia) \n", i+1, kamar[i].nomor);
			}
		}
		printf("Pilih No Kamar (1-10) : ");
		scanf("%d", &pilih_kamar);
		// cek ketersediaan
		while(kamar[pilih_kamar-1].kosong == false){
			printf("\n ! Kamar tersebut tidak tersedia ! \n");
			printf("Pilih No Kamar (1-10) : ");
			scanf("%d", &pilih_kamar);
		}
		printf("Jumlah Inap (hari) : ");
		scanf("%d", &jumlah_inap);

		strcpy(kamar[pilih_kamar-1].nama_penginap, nama);
		kamar[pilih_kamar-1].kosong = false;
		kamar[pilih_kamar-1].jumlah_inap = jumlah_inap;

    	printf("\nTotal Harga Kamar %d, Jumlah Inap %d hari = Rp %d ", kamar[pilih_kamar-1].nomor, kamar[pilih_kamar-1].jumlah_inap, (kamar[pilih_kamar-1].harga * kamar[pilih_kamar-1].jumlah_inap));
    	printf("\n-------------------\n");
    	printf("Berhasil tambah data!");


	} else {
		printf("Kamar tidak ada yang tersedia!");
	}
}

void view_total(){
	int i, total = 0;
	printf(" .:: Daftar Kamar dan Total Harga Keseluruhan::. \n");
	for (i = 0; i < MAX_KAMAR; i++ ){
		printf("| No | Nomor Kamar | Nama Pelanggan | Harga per Malam | Jumlah Inap | Subtotal |\n");
	    printf("|----|-------------|----------------|-----------------|-------------|----------|\n");
	    for (i = 0; i < MAX_KAMAR; i++) {
	        printf("| %2d | %11d | %-14s | %15d | %11d | %8d |\n", i+1, kamar[i].nomor, kamar[i].nama_penginap, kamar[i].harga, kamar[i].jumlah_inap, (kamar[i].harga *kamar[i].jumlah_inap));
	   		total += (kamar[i].harga *kamar[i].jumlah_inap);
	    }
	}

	printf("Total Harga Keseluruhan : %d \n", total);
}

int cek_kamar(struct Kamar kamar[]){
	int i, find = 0;
    for (i = 0; i < MAX_KAMAR; i++) {
        if (kamar[i].kosong) {
            find = 1;
        }
    }
    return find;
}

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

        if (login_berhasil) {
            printf("\n=== MENU HOTEL ===\n");
            printf("1. Logout\n");
            printf("2. Tampil Kamar (101-110)\n");
            printf("3. Tambah Nama/Penginap & Pemesanan\n");
            printf("4. Total dan Tampil Harga Keseluruhan\n");

        } else {
            printf("\nSelamat Datang silahkan Login/Register\n");
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
                    developer();
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
