/* File        : mainNRSL.cpp 															  */
/* Deskripsi   : Driver / main program untuk ADT Non Restricted Single Linked/Linear List */
/* Dibuat oleh : Ade Chandra Nugraha													  */
/* Tanggal     : 25-10-2001 															  */
/* Diupdate oleh : Santi Sundari, 6-4-2011, hanya tdd operasi2 dasar 					  */

#include "spnrsll.h"
#include "BodyNRSL.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

int main() {
	superset_list S;
	create_super (&S);
//    create_super(superset_list (*S));
    int choice, opsi, operasi;
    char nama_mhs[20]; 
	char NIM[9];

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
                        Seleksi_MemberSuper(&S);
                        break;
                    case 2:
                        break;
                    case 3:
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

            default:
                printf("Pilihan tidak valid. Silahkan masukkan angka 1-7.\n");
        }

        printf("\n");
    } while (choice != 7);

	system("pause");
    return 0;
    
}
