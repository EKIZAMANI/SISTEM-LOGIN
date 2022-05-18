#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int banyakArgumen, char *argumen[]){

    // variabel untuk menampung username dan password
    char login[20];

    // jika banyak argumen 1, maka akan dilakukan registrasi akun
    if(banyakArgumen == 1){
        FILE *reg1 = fopen("login.bin", "wb");
        printf("----------------------------\n");
        printf("  Registrasi Pembuatan akun \n");
        printf("----------------------------\n");
        printf("Masukkan username dan password mengikuti format berikut !\n");
        printf("username@password : ");
        scanf("%s", login);
        fwrite(&login, sizeof(login), 1, reg1);
        printf("Cara Penggunaan : ./FileProgramUtaman username password\n");
        fclose(reg1);
    }

    // jika banyak argumen tidak 3 dan 1, makan program akan memberitahu user
    // cara login yang benar.
    if (banyakArgumen != 3 && banyakArgumen != 1){
        printf("Gagal login !\n");
        printf("Cara Penggunaan : ./FileProgramUtaman username password\n");
    }

    // jika banyakArgummen 3, maka akan dijalankan login 
    if (banyakArgumen == 3){
        char userInput[10], passInput[10];
        strcpy(userInput, argumen[1]);
        strcpy(passInput, argumen[2]);

        FILE *reg2;

        if((reg2 = fopen ("login.bin", "rb")) == NULL){
            printf("Gagal membukan file !\n");
            return EXIT_FAILURE;
        }

        char akun[20];
        fread(akun,  sizeof(char), sizeof(akun)/sizeof(char), reg2);

        fclose(reg2);

        char *string[3];
        char username[20], password[20];
        int ctrl = 0;

        string[0] = strtok(akun, "@");
        while (string[ctrl++] != NULL){
            string[ctrl] = strtok(NULL, "@");
        }

        strcpy(username, string[0]);
        strcpy(password, string[1]);

        if ( ( strcmp(userInput, username) == 0) && (strcmp(passInput, password) == 0) ){
            printf("Selamat anda berhasil login !\n");
        }

        fclose(reg2);
    } 

return 0;
}
