/*  File        : MainNRSL.cpp 															 
    Deskripsi   : Driver / main program aplikasi himpunan untuk pendataan UKM di Polban 
    Author      : Kelompok 2B												                
    Tanggal     : 16 APRIL 2023															  
===================================================================================================*/
#include "SpHimpunan.h"
#include "BodyHimpunan.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

int main() {
	superset_list POLBAN;
    subset_list DKM, KEWIRAUSAHAAN, BADMINTON, BASKET, VOLI;
    subset_list POLBAN_CHESS, JFP, ROBOTIK, FELLAS, FUTSAL;
    subset_list H1, H2;
    create_super(&POLBAN);
    create_sub(&DKM);
    create_sub(&KEWIRAUSAHAAN);
    create_sub(&BADMINTON);
    create_sub(&BASKET);
    create_sub(&VOLI);
    create_sub(&POLBAN_CHESS);
    create_sub(&JFP);
    create_sub(&ROBOTIK);
    create_sub(&FELLAS);
    create_sub(&FUTSAL);
    create_sub(&H1);
    create_sub(&H2);
    int choice, opsi, operasi;
    char nama_mhs[61]; 
	char NIM[10];

    do {
        display_menu();
        printf("Masukkan Pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
            	printf("| [1] Buat Himpunan |\n");
                printf("1. Masukkan Superset: \n");
                    printf("2. Masukkan Subset 1: \n");
                printf("3. Masukkan Subset 2: \n");
                scanf("%d", &opsi);
                switch (opsi){
                    case 1:
                        Seleksi_MemberSuper(&POLBAN);
                        break;
                    case 2: menu_addsub(&DKM, &KEWIRAUSAHAAN, &BADMINTON, &BASKET, &VOLI, &POLBAN_CHESS, &JFP, &ROBOTIK, &FELLAS, &FUTSAL);
                        break;
                    case 3: menu_addsub(&DKM, &KEWIRAUSAHAAN, &BADMINTON, &BASKET, &VOLI, &POLBAN_CHESS, &JFP, &ROBOTIK, &FELLAS, &FUTSAL);
                        break;
                }
                break;
            case 2:
            	printf("| [2] Operasi Himpunan |");
                // printf("1. Operasi Irisan");
                // printf("2. Operasi Gabungan");
                // printf("3. Operasi Selisih");
                // printf("4. Operasi Komplemen");
                // scanf("%d", &operasi);
                // switch (operasi){
                //     case 1:
                //        irisan();
                //         break;
                //     case 2:
                //        gabungan();
                //         break;
                //     case 3:
                //        selisih();
                //         break;
                //     case 4:
                //        komplemen();
                //         break;
                // }
                break;
            case 3:
            	printf("| [3] Edit Daftar Himpunan |");
                printf("1. Edit Superset: ");
                printf("2. Edit Subset 1: ");
                printf("3. Edit Subset 3: ");
                scanf("%d", &opsi);
                switch (opsi){
                    case 1:
                        // add_membersuper(&S, nama_mhs, NIM);
                        break;
                    case 2:
//                        add_membersubset1(&S, nama_mhs, NIM);
                        break;
                    case 3:
//                        add_membersubset2(&S, nama_mhs, NIM);
                        break;
                }
            case 4 : break;
            case 5 : break;
        }

        printf("\n");
    } while (choice != 7);

	system("pause");
    return 0;
    
}
