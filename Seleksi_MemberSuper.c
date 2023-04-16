/*  AUTHOR      : Banteng Harisantoso
    IS          : Sudah terbentuk list superset
    FS          : Menampilkan pesan berhasil atau gagal menambahkan mahasiswa ke dalam himpunan
    DESKRIPSI   : Prosedur untuk masuk ke menu penambahan mahasiswa dengan syarat-syarat POLBAN
    VERSI       : 1.0
=======================================================================================================================*/
#include "SpHimpunan.h"
#include <stdbool.h>
#include <stdio.h>

void Seleksi_MemberSuper(superset_list *S){
    char nama_mhs[20];
    int opsi;
    bool syarat = true;

    system("cls");
    printf("Silahkan masukkan nama calon mahasiswa.\n");
    fgets(nama_mhs, sizeof(nama_mhs), stdin);
    while(syarat){
            printf("\n\nApakah calon mahasiswa tersebut lolos seleksi SNMPTN/SBMPTN atau SNMPN/SBMPN atau Ujian Mandiri?\n");
            printf("1. Ya\n2. Tidak\n");
            scanf("%d", &opsi);
            switch (opsi)
            {
            case 1 :
                while(syarat){
                printf("\n\nApakah calon mahasiswa tersebut lolos seleksi berkas administrasi?\n");
                printf("1. Ya\n2. Tidak\n");
                scanf("%d", &opsi);
                    switch (opsi)
                    {
                    case 1:
                        while(syarat){
                        printf("\n\nApakah calon mahasiswa tersebut sudah melunasi pembayaran UKT awal?\n");
                        printf("1. Ya\n2. Tidak\n");
                        scanf("%d", &opsi);
                            switch (opsi)
                            {
                            case 1 :
                                char NIM[10];
                                printf("Silahkan masukkan NIM mahasiswa tersebut!\n");
                                printf("NIM\t:");
                                fgets(NIM, sizeof(NIM), stdin);
                                if(isExist(*S, nama_mhs, NIM)){
                                   printf("\n\nMahasiswa tersebut sudah terdaftar di POLBAN!"); 
                                }
                                else{
                                    add_membersuper(&S, nama_mhs, NIM);
                                    alamatsuper mhs;
                                    mhs = S->first_super;

                                    printf("\n\nCalon mahasiswa telah resmi menjadi mahasiswa POLBAN!");
                                    printf("\nInformasi Mahasiswa:");
                                    printf("\nNama Mahasiswa\t: %s", mhs->member_sp);
                                    printf("\nNIM\t: %s", mhs->id_member);
                                }
                                syarat = false;
                                break;

                            case 2 :
                            printf("\nMahasiswa belum memenuhi persyaratan!");
                            break;
                            default:
                                printf("\nMasukkan opsi yang valid!");
                            }
                        }
                        
                    case 2 :
                        printf("\nMahasiswa belum memenuhi persyaratan!");
                        break;
                    default:
                        printf("\nMasukkan opsi yang valid!");
                    }
                }
                
            case 2 :
               printf("\nMahasiswa belum memenuhi persyaratan!");
               break;
            default:
                printf("\nMasukkan opsi yang valid!");
            }

    }
    
    


}
