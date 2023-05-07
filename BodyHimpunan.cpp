/*  File        : BodyHimpunan.cpp 															 
    Deskripsi   : Body prototype ADT aplikasi himpunan untuk pendataan UKM di Polban (NRLL) 
    Author      : Kelompok 2B												                
    Tanggal     : 16 APRIL 2023															  
===================================================================================================*/
#include <limits.h>
#include <malloc.h>
#include "SpHimpunan.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>

/********** BODY SUB PROGRAM ***********/

//pembentukan list superset
void create_super (superset_list *S){
    S->first_super = NULL;
}

//pembentukan list subset-1
void create_sub (subset_list *H1){
    H1->first_sub = NULL;
}

//mengecek apakah superset kosong
bool IsSuperEmpty (superset_list S){
    return (S.first_super == NULL);
}

//mengecek apakah subset-1 kosong
bool IsSubEmpty (subset_list H1){
    return (H1.first_sub == NULL);
}

// Memeriksa apakah mahasiswa dengan nama dan NIM yang diberikan sudah terdaftar dalam list super
bool IsExistSuper(superset_list S, char nama_mhs[], char NIM[]) {
    alamatsuper P;
	P = S.first_super;
    while (P != NULL) {
        if (strcmp(P->member_sp, nama_mhs) == 0 && strcmp(P->id_member, NIM) == 0) {
            return true;
        }
        P = P->next_sp;
    }
    return false;
}

bool IsExistSub(subset_list H1, char nama_mhs[], char NIM[]){
    alamatsub P;
    P = H1.first_sub;
    while (P != NULL) {
        if (strcmp(P->member_sub, nama_mhs) == 0 && strcmp(P->id_sub, NIM) == 0) {
            return true;
        }
        P = P->next_sub;
    }
    return false;
}

//mengecek apakah proses alokasi berhasil atau gagal karena memori yang kurang
bool IsFull() {
    alamatsuper bantu;
    bantu = (alamatsuper) malloc (sizeof(elmtsuper));
    
    if (bantu != NULL) {
        return false;
    } else { 
		return true;
	}
}

// Meminta input dari pengguna dan menambahkan mahasiswa ke dalam superset_list
void add_membersuper(superset_list *S, char nama_mhs[], char NIM[]) {
    alamatsuper P;
    P = (alamatsuper) malloc(sizeof(elmtsuper));
    strcpy(P->member_sp, nama_mhs);
    strcpy(P->id_member, NIM);
    P->next_sp = NULL;

    //Mengecek apakah memori penuh
    if(IsFull()){
        printf("Memori penuh!\n");
    }
    else{
    // Mengecek apakah daftar kosong
    if (IsSuperEmpty(*S)) {
        // Jika daftar kosong, maka node baru akan menjadi head
        S->first_super = P;
        S->first_super->next_sp = NULL;
    }
    else {
        // Menambahkan node baru ke akhir list
        alamatsuper last;
		last = S->first_super;
        while (last->next_sp != NULL) {
            last = last->next_sp;
        }
        last->next_sp = P;
        last->next_sp->next_sp = NULL;
    }
    }
    
}
/* Menambah member subset*/
void add_membersub(subset_list *H1, char nama_mhs[], char NIM[], char UKM[]){
    
    alamatsub P;
    P = (alamatsub) malloc(sizeof(elmtsubset));
    strcpy(P->member_sub, nama_mhs);
    strcpy(P->id_sub, NIM); 
    strcpy(P->nama_sub, UKM);
    P->next_sub = NULL;
    //Mengecek apakah memori penuh
    if(IsFull()){
        printf("Memori penuh!\n");
    }
    else{
    // Mengecek apakah daftar kosong
    if (IsSubEmpty(*H1)) {
        // Jika daftar kosong, maka node baru akan menjadi head
        H1->first_sub = P;
        H1->first_sub->next_sub = NULL;
    }
    else {
        // Menambahkan node baru ke akhir list
        alamatsub last;
		last = H1->first_sub;
        while (last->next_sub != NULL) {
            last = last->next_sub;
        }
        last->next_sub = P;
        last->next_sub->next_sub = NULL;
    }
    }

}
   

void display_cur(superset_list S){
    alamatsuper P;
    P = S.first_super;
    while(P != NULL){
        printf("%s ", P->member_sp);
        printf("%s\n", P->id_member);
        P = P->next_sp;
    }
    system("pause");
}

int ListUKM(){

        printf("| Pilih salah satu UKM di bawah:\t|\n");
        printf("| [1] DKM \t\t\t\t|\n");
        printf("| [2] KEWIRAUSAHAAN \t\t\t|\n");
        printf("| [3] BADMINTON \t\t\t|\n");
        printf("| [4] BASKET \t\t\t\t|\n");
        printf("| [5] VOLI \t\t\t\t|\n");
        printf("| [6] POLBAN CHESS \t\t\t|\n");
        printf("| [7] JFP \t\t\t\t|\n");
        printf("| [8] ROBOTIK \t\t\t\t|\n");
        printf("| [9] FELLAS \t\t\t\t|\n");
        printf("| [10] USF \t\t\t\t|\n");
        printf("=========================================\n");
        
        int opsi;
        printf("Opsi: ");
        scanf("%d", &opsi);
        while ((opsi < 1)||(opsi > 10))
        {   
            printf("\nOpsi tidak valid\n");
            printf("Opsi: ");
            scanf("%d", &opsi);
        }

        return opsi;
}   

void MenuBuatHimpunan(superset_list* POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF){
    int opsi;
    system("cls");
        printf("=========================================\n");
        printf("|\t[1] Buat Himpunan\t\t|\n");
        printf("=========================================\n");
        printf("| Menu: \t\t\t\t|\n");
        printf("| [1] Tambah Mahasiswa POLBAN \t\t|\n");
        printf("| [2] Tambah Anggota UKM POLBAN \t|\n");
        printf("| [99] Back \t\t\t\t|\n");
        printf("=========================================\n");
    scanf("%d", &opsi);
    switch (opsi){
        case 1:
            Seleksi_MemberSuper(POLBAN);
            break;
        case 2: MenuAddSub(*POLBAN, DKM, KEWIRAUSAHAAN, BADMINTON, BASKET, VOLI, POLBAN_CHESS, JFP, ROBOTIK, FELLAS, USF);
            break;
        case 99 :
            break;
    }
}

void Seleksi_MemberSuper(superset_list *S)
/*  AUTHOR      : Banteng Harisantoso
    IS          : Sudah terbentuk list superset
    FS          : Menampilkan pesan berhasil atau gagal menambahkan mahasiswa ke dalam list POLBAN
    DESKRIPSI   : Prosedur untuk masuk ke menu penambahan mahasiswa dengan syarat-syarat POLBAN,
                  pengguna akan diarahkan ke switch, jika memilih 1 berturut-turut maka calon mahasiswa dapat menjadi mahasiswa
                  POLBAN. Namun, jika mahasiswa tidak lolos salah satu persyaratan maka calon mahasiswa belum bisa menjadi
                  mahasiswa POLBAN
=======================================================================================================================*/
{
    char nama_mhs[61];
    int jumlah;
    int opsi = 0;
    bool syarat = true;
    do
    {
        system("cls");
        printf("=========================================\n");
        printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
        printf("=========================================\n");
        printf("| Berapa banyak calon mahasiswa \t|\n");
        printf("| yang ingin didata? \t\t\t|\n");
        printf("=========================================\n");
        printf("Jumlah : ");
        scanf("%d", &jumlah);
        if((jumlah <=0)||(jumlah>=100)){
            printf("\nJumlah tidak valid, minimal 1 mahasiswa dan maksimal 100 mahasiswa persesi!\n");
        }
    } while ((jumlah <= 0)||(jumlah>=100));
    
    
    for(int i=0;i<jumlah;i++){
    system("cls");
    printf("=========================================\n");
    printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
    printf("=========================================\n");
    printf("| Masukkan nama calon mahasiswa \t|\n");
    printf("=========================================\n");
    addnama(nama_mhs);
    while(syarat){
            system("cls");
            printf("=========================================\n");
            printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
            printf("=========================================\n");
            printf("| Apakah calon mahasiswa tersebut lolos\t|\n");
            printf("| seleksi SNMPTN/SBMPTN atau SNMPN/\t|\n");
            printf("| SBMPN atau Ujian Mandiri?\t\t|\n");
            printf("| 1. Ya 2. Tidak\t\t\t|\n");
            printf("=========================================\n");
            printf("Opsi: "); scanf("%d", &opsi);
            switch (opsi)
            {
            case 1 :
                while(syarat){
                system("cls");
                printf("=========================================\n");
                printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
                printf("=========================================\n");
                printf("| Apakah calon mahasiswa tersebut lolos\t|\n");
                printf("| seleksi berkas administrasi?\t\t|\n");
                printf("| 1. Ya 2. Tidak\t\t\t|\n");
                printf("=========================================\n");
                printf("Opsi: "); scanf("%d", &opsi);    
                    switch (opsi)
                    {
                    case 1:
                        while(syarat){
                        system("cls");
                        printf("=========================================\n");
                        printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
                        printf("=========================================\n");
                        printf("| Apakah calon mahasiswa tersebut sudah\t|\n");
                        printf("| melunasi pembayaran UKT awal?/\t|\n");
                        printf("| 1. Ya 2. Tidak\t\t\t|\n");
                        printf("=========================================\n");
                        printf("Opsi: "); scanf("%d", &opsi);
                            switch (opsi)
                            {
                            case 1 :
                                char NIM[10];
                                system("cls");
                                printf("=========================================\n");
                                printf("|\t[1] Tambah Mahasiswa POLBAN\t|\n");
                                printf("=========================================\n");
                                printf("| Mahasiswa lolos persyaratan POLBAN! \t|\n");
                                printf("| Masukkan NIM mahasiswa tersebut\t|\n");
                                printf("=========================================\n");
                                addnim(NIM);
                                if(IsExistSuper(*S, nama_mhs, NIM)){
                                   printf("\n\nMahasiswa tersebut sudah terdaftar di POLBAN!");
                                   system("pause");
                                }
                                else{
                                    add_membersuper(S, nama_mhs, NIM);
                                    system("cls");
                                    printf("Calon mahasiswa telah resmi menjadi mahasiswa POLBAN\t\t\n");
                                    printf("=========================================\n");
                                    printf("|\t INFORMASI MAHASISWA \t\t|\n");
                                    printf("=========================================\n");
                                    printf(" Nama\t\t: %.*s.\n", 20, nama_mhs);
                                    printf(" NIM\t\t: %s\n\n", NIM);
                                    WritePOLBAN(nama_mhs, NIM);
                                    system("pause");
                                }
                                syarat = false;
                                break;

                            case 2 :
                            printf("\nMahasiswa belum memenuhi persyaratan!");
                            system("pause");
                            syarat = false;
                            break;

                            default:
                                printf("\nMasukkan opsi yang valid!");
                                system("pause");
                            }
                        }
                    break;
                    case 2 :
                        printf("\nMahasiswa belum memenuhi persyaratan!");
                        system("pause");
                        syarat = false;
                        break;
                    default:
                        printf("\nMasukkan opsi yang valid!");
                        system("pause");
                    }
                }

            break;
            case 2 :
               printf("\nMahasiswa belum memenuhi persyaratan!\n");
               system("pause");
               syarat = false;
               break;
            default:
                printf("\nMasukkan opsi yang valid!\n");
                system("pause");
            }

    }
    syarat = true;
    }
    
}

void MenuAddSub(superset_list POLBAN, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF)
/*  AUTHOR      : Banteng Harisantoso
    IS          : Sudah terbentuk list subset
    FS          : Menampilkan pesan berhasil atau gagal menambahkan mahasiswa ke dalam himp
    DESKRIPSI   : Prosedur untuk masuk ke menu penambahan mahasiswa ke pilihan UKM
=======================================================================================================================*/
{
system("cls");
char nama_mhs[61];
char NIM[10];
bool valid = false;
int jumlah = 0;

while(!valid){
    
    printf("============================ Menu Pendataan Anggota UKM ===================================\n");
    int opsi = ListUKM();
    if(opsi==1){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan DKM: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*DKM, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan DKM!\n\n");
            } 
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(DKM, nama_mhs, NIM, "DKM");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan DKM!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;        
        break;
    }else if(opsi==2){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan KEWIRAUSAHAAN: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*KEWIRAUSAHAAN, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan KEWIRAUSAHAAN!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(KEWIRAUSAHAAN, nama_mhs, NIM, "KEWIRAUSAHAAN");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan KEWIRAUSAHAAN!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==3){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan BADMINTON: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*BADMINTON, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan BADMINTON!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(BADMINTON, nama_mhs, NIM, "BADMINTON");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan BADMINTON!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==4){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan BASKET: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*BASKET, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan BASKET!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(BASKET, nama_mhs, NIM, "BASKET");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan BASKET!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break; 
    }else if(opsi==5){
       printf("Masukkan jumlah mahasiswa yang akan bergabung dengan VOLI: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*VOLI, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan VOLI!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(VOLI, nama_mhs, NIM, "VOLI");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan VOLI!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break; 
    }else if(opsi==6){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan POLBAN CHESS: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*POLBAN_CHESS, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan POLBAN CHESS!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(POLBAN_CHESS, nama_mhs, NIM, "POLBAN_CHESS");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan POLBAN CHESS!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }            
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==7){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan JFP: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*JFP, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan JFP!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(JFP, nama_mhs, NIM, "JFP");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan JFP!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }   
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==8){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan ROBOTIK: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*ROBOTIK, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan ROBOTIK!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(ROBOTIK, nama_mhs, NIM, "ROBOTIK");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan ROBOTIK!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break;
    }else if(opsi==9){
       printf("Masukkan jumlah mahasiswa yang akan bergabung dengan FELLAS: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*FELLAS, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan FELLAS!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(FELLAS, nama_mhs, NIM, "FELLAS");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan FELLAS!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break; 
    }else if(opsi==10){
        printf("Masukkan jumlah mahasiswa yang akan bergabung dengan USF: ");
        scanf("%d", &jumlah);
        for(int i = 0; i < jumlah; i++){
            addnama(nama_mhs);
            addnim(NIM);
            if(IsExistSub(*USF, nama_mhs, NIM)){
                printf("\nMahasiswa sudah bergabung dengan USF!\n\n");
            }
            else if(IsExistSuper(POLBAN, nama_mhs, NIM)){
                add_membersub(USF, nama_mhs, NIM, "USF");
                printf("\n%s ", nama_mhs);
                printf("berhasil bergabung dengan USF!\n\n");
                WriteUKM(opsi, nama_mhs, NIM);
            }
            else{
                printf("\nTidak ada mahasiswa tersebut!\n");
            }
        }
        valid = true;
        break; 
    }
    }
    system("pause");
}

void addnama(char* nama_mhs){
    bool valid = false;
    while(!valid){
        
        printf("Masukkan nama mahasiswa\t: ");
        scanf(" %[^\n]", nama_mhs);
        getchar();
        if(strlen(nama_mhs) > 60){
            printf("Nama mahasiswa terlalu panjang!\n");
        }
        else{
            valid = true;
        }
    }

}


void addnim(char* NIM){
    bool valid = false;

    while(!valid){
        printf("Masukkan NIM\t\t: ");
        //fgets(NIM, 9, stdin);
        scanf("%s", NIM);
        getchar();
        if(strlen(NIM) > 9){
            printf("NIM terlalu panjang!\n");
        }
        else{
            valid = true;
        }
    }

}

void del_membersuper(superset_list *S, char nama_mhs[], char NIM[]){
    /*  AUTHOR  : Bob Manuel
    IS          : List superset sudah terbentuk dan memiliki isi sebagai anggota superset
    FS          : List yang berisi nama dan NIM yang ingin dihapus berhasil dihapus
    DESKRIPSI   : Prosedur untuk mencari mahasiswa pada superset maupun subset.
                  Pengguna akan diarahkan untuk menginput nama dan NIM dari mahasiswa yang ingin dicari.
                  Jika nama dan NIM ditemukan maka modul akan mengembalikan nilai true, 
                  sebaliknya jika nama dan NIM tidak ditemukan maka akan mengembalikan nilai false
    =======================================================================================================================*/
    //Kamus Lokal
    alamatsuper bantu, hapus, next;
    bantu = S->first_super;

    if(IsExistSuper(*S, nama_mhs, NIM)){
        while((bantu->next_sp->member_sp != nama_mhs) || (bantu != NULL)){
            bantu= bantu->next_sp; 
            if(bantu->next_sp->member_sp == nama_mhs){
                hapus = bantu->next_sp;
                next = hapus->next_sp;
                bantu->next_sp = next;
                printf("Mahasiswa bernama %s sudah berhasil dihapus", &hapus->member_sp);
                free(hapus);
            } 
        }
    } else {
        printf("Mahasiswa tidak ditemukan");
    }
    
}

void del_membersub(subset_list *H1, char nama_mhs[], char NIM[]) {
    alamatsub bantu, hapus, next;
    bantu = H1->first_sub;

    if(IsExistSub(*H1, nama_mhs, NIM)){
        while((bantu->next_sub->member_sub != nama_mhs) || (bantu != NULL)){
           bantu = bantu->next_sub;
           if(bantu->next_sub->member_sub == nama_mhs){
            
           }
        }
    }
}

void Penghentian_Studi(superset_list *S, char nama_mhs[], char NIM[]){
    int jumlah;
    char jawaban[5]; // variabel untuk menyimpan jawaban

    printf("Berapa banyak mahasiswa yang ingin dihapus?\n");
    scanf("%d", &jumlah);
    while((jumlah == 0)||(jumlah<0)){
        printf("Jumlah tidak valid! Silahkan masukkan jumlah yang valid.\n");
        scanf("%d", &jumlah);
    }

    for(int i=0;i<jumlah;i++){
        system("cls");
        printf("Silahkan masukkan nama mahasiswa yang ingin dihapus.\n");
        scanf("%s", &nama_mhs);

        printf("Silahkan masukkan NIM mahasiswa tersebut!\n");
        printf("NIM\t:");
        scanf("%s", &NIM);
        if(IsExistSuper(*S, nama_mhs, NIM)){
            printf("JSilakan jawab dengan ya atau tidak.\n");
            // pertanyaan 1
            printf("Apakah mahasiswa dua semester berturut-turut lulus percobaan sampai dengan semester IV untuk mahasiswa Program Diploma III dan semester VI untuk mahasiswa Program Diploma IV?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 2
            printf("Apakah Indeks Prestasi (IP) mahasiswa berada di antara 1,70 dan 2,00 dan jumlah SKS nilai D lebih dari 7 SKS?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 3
            printf("Apakah nilai IP mahasiswa di bawah 1,70?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 4
            printf("Apakah mahasiswa tidak memenuhi syarat kelulusan pada semester VI untuk mahasiswa Program Diploma III dan pada semester VIII untuk mahasiswa Program Diploma IV, setelah diberi kesempatan mengulang satu kali?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 5
            printf("Apakah mahasiswa mempunyai nilai E pada semester I sampai dengan IV untuk mahasiswa Program Diploma III dan semester I sampai IV?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 6
            printf("Apakah mahasiswa melewati batas studi yang telah ditetapkan dalam Pasal 18 Ayat 1 dan 2?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }

            // pertanyaan 7
            printf("Apakah mahasiswa memiliki status ketidakhadiran yang tidak diperbolehkan, sebagaimana diatur dalam Pasal 22?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            } 

            // pertanyaan 8
            printf("Apakah mahasiswa terlibat dalam perbuatan kriminal yang dinyatakan oleh pihak berwajib?\n");
            scanf("%s", jawaban);
            if (strcmp(jawaban, "ya") == 0) {
                del_membersuper(S, nama_mhs, NIM);
                printf("Mahasiswa %s", nama_mhs, "telah dihapus dari daftar anggota POLBAN.\n");
                return;
            }
            
            else if (strcmp(jawaban, "tidak") == 0) {
                // jawaban tidak, lanjut ke pertanyaan berikutnya
            } else {
                printf("Jawaban tidak valid, silakan jawab dengan ya atau tidak.\n");
                return;
            }


        }

    }
}

void CopyList(subset_list* H, subset_list SC){
    alamatsub bantu;
    bantu = SC.first_sub;

    while(bantu != NULL){
        add_membersub(H, bantu->member_sub, bantu->id_sub, bantu->nama_sub);
        bantu = bantu->next_sub;
    }
}

void EkstrakList(subset_list* H, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF)
{
    create_sub(H);
    bool valid = false;

    while(!valid){
        int opsi = ListUKM();
        if(opsi==1){
            CopyList(H, DKM);
            valid = true;
        }else if(opsi==2){
            CopyList(H, KEWIRAUSAHAAN);
            valid = true;
        }else if(opsi==3){
            CopyList(H, BADMINTON);
            valid = true;
        }else if(opsi==4){
            CopyList(H, BASKET);
            valid = true;
        }else if(opsi==5){
            CopyList(H, VOLI);
            valid = true;
        }else if(opsi==6){
            CopyList(H, POLBAN_CHESS);
            valid = true;
        }else if(opsi==7){
            CopyList(H, JFP);
            valid = true;
        }else if(opsi==8){
            CopyList(H, ROBOTIK);
            valid = true;
        }else if(opsi==9){
            CopyList(H, FELLAS);
            valid = true;
        }else if(opsi==10){
            CopyList(H, USF);
            valid = true;
        }
    }
}

void MenuOperasi(superset_list S, subset_list* H1, subset_list* H2, subset_list DKM, subset_list KEWIRAUSAHAAN, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list USF){
    int opsi = 0;
    bool valid = false;
    
    system("cls");
        printf("=========================================\n");
        printf("|\t[2] Operasi Himpunan\t\t|\n");
        printf("=========================================\n");
        printf("| Saat ini program hanya dapat\t\t|\n| mengkalkulasikan dua himpunan\t\t|\n");
        printf("| \t\t\t\t\t|\n");
        printf("| UKM 1: \t\t\t\t|\n");
        EkstrakList(H1, DKM,  KEWIRAUSAHAAN,  BADMINTON,  BASKET,  VOLI,  POLBAN_CHESS,  JFP,  ROBOTIK,  FELLAS,  USF);
        system("cls");
        printf("=========================================\n");
        printf("|\t[2] Operasi Himpunan\t\t|\n");
        printf("=========================================\n");
        printf("| UKM 2: \t\t\t\t|\n");
        EkstrakList(H2, DKM,  KEWIRAUSAHAAN,  BADMINTON,  BASKET,  VOLI,  POLBAN_CHESS,  JFP,  ROBOTIK,  FELLAS,  USF);
    
    system("cls");
    printf("UKM 1 : %s\n", H1->first_sub->nama_sub);
    printf("UKM 2 : %s\n\n", H2->first_sub->nama_sub);
    printf("Silahkan pilih operasi di bawah:\n");
    printf("1. Irisan\n");
    printf("2. Gabungan\n");
    printf("3. Selisih\n");
    printf("4. Komplemen\n");
    scanf("%d", &opsi);

    while(!valid){
        switch (opsi)
        {
        case 1 :
            printf("Irisan(Super, H1, H2) 'contoh: %s dan %s'\n", H1->first_sub->member_sub, H2->first_sub->member_sub);
            irisan(*H1, *H2);
            valid = true; break;
        case 2 :
            printf("Gabungan(Super, H1, H2)'contoh: %s dan %s'\n", H1->first_sub->member_sub, H2->first_sub->member_sub);
            gabungan(*H1, *H2);
            valid = true;break;
        case 3 :
            printf("Selisih(Super, H1, H2)'contoh: %s dan %s'\n", H1->first_sub->member_sub, H2->first_sub->member_sub);
            selisih(*H1, *H2);
            valid = true;break;        
        case 4 :
            printf("Komplemen(Super, H1, H2)'contoh: %s dan %s'\n", H1->first_sub->member_sub, H2->first_sub->member_sub);
            valid = true;break;
        default:
            printf("Masukkan opsi yang valid!");
            system("pause");
            break;
        }
    }
    system("pause");
}

void irisan(subset_list H1, subset_list H2){
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : List subset1 dan subset2 sudah terbentuk, serta memiliki isi anggota-anggota subset1 dan subset2.
    FS          : Menampilkan irisan atau anggota-anggota yang sama pada kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan anggota yang sama dari kedua himpunan yang diinputkan.
                  Jika salah satu atau kedua himpunan kosong, maka akan menampilkan pesan bahwa tidak terdapat irisan karena terdapat himpunan yang kosong.
                  Jika ditemukan anggota yang sama, maka anggota tersebut akan ditampilkan ke layar.
                  Jika tidak ditemukan anggota yang sama, maka akan menampilkan pesan bahwa tidak terdapat anggota yang sama di kedua himpunan.
    =======================================================================================================================*/
    // Kamus Data
    alamatsub P;
    alamatsub Q;
    bool found = false;
    if(IsSubEmpty(H1) || IsSubEmpty(H2)) {
        printf("Tidak terdapat irisan, karena terdapat himpunan UKM yang kosong.\n");
    } else {
        printf("Irisan dari kedua himpunan UKM adalah:\n");
        // Traverse subset_list H1
        P = H1.first_sub;
        while ( P != NULL ) {
            // Traverse subset_list H2
            Q = H2.first_sub;
            while (Q != NULL) {
                // Jika ada anggota yang sama di kedua himpunan UKM, maka print anggota tersebut
                if (strcmp(P->member_sub, Q->member_sub) == 0 && strcmp(P->id_sub, Q->id_sub) == 0) {
                    printf("%s - %s\n", P->member_sub, P->id_sub);
                    found = true;
                    break;
                }
                Q = Q->next_sub;
            }
            P = P->next_sub;
        }
        // Jika tidak ada irisan, tampilkan pesan.
        if (!found) {
            printf("Tidak terdapat anggota yang sama di kedua UKM.\n");
        }
    }
}

void gabungan(subset_list H1, subset_list H2) {
/*  AUTHOR      : Salsabil Khoirunisa
    IS          : List subset1 dan subset2 sudah terbentuk, serta memiliki isi anggota-anggota subset1 dan subset2.
    FS          : Menampilkan hasil gabungan kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan gabungan dari kedua himpunan yang diinputkan.
                  Jika terdapat anggota yang sama diantara kedua list, maka akan ditampilkan satu kali saja.
                  Hasil gabungan akan ditampung dalam sebuah list baru.
    =======================================================================================================================*/

    // Membuat list baru untuk menampung gabungan dari subset1 dan subset2.
    subset_list HasilGabungan;
    create_sub(&HasilGabungan);

    // Kamus Data
    alamatsub P;

    // Menambahkan semua anggota subset1 ke list HasilGabungan.
    P =  H1.first_sub;
    while (P != NULL) {
        add_membersub(&HasilGabungan, P->member_sub, P->id_sub, "Gabungan");
        P = P->next_sub;
    }

    // Menambahkan semua anggota subset2 ke list HasilGabungan.
    // Jika ada anggota yang sudah terdapat dalam list, tidak akan ditambahkan lagi.
    P = H2.first_sub;
    while (P != NULL) {
        if(!IsExistSub(HasilGabungan, P->member_sub, P->id_sub)) {
            add_membersub(&HasilGabungan, P->member_sub, P->id_sub, "Gabungan");
        }
        P = P->next_sub;
    }

    // Menampilkan semua anggota himpunan gabungan.
    P = HasilGabungan.first_sub;
    printf("Himpunan Gabungan : \n");
    while (P != NULL) {
        printf("%s - %s\n", P->member_sub, P->id_sub);
        P = P->next_sub;
    }

}

void  selisih(subset_list H1, subset_list H2) {
/*  AUTHOR      : Bob Manuel
    IS          : List subset1 dan subset2 sudah terbentuk, ada kemungkinan jika subset kosong.
    FS          : Menampilkan irisan atau anggota-anggota yang sama pada kedua himpunan yang diinputkan.
    DESKRIPSI   : Prosedur untuk menampilkan anggota hasil dari operasi selisih antara 2 subset
                  Jika salah satu atau kedua subset kosong, maka akan menampilkan pesan bahwa tidak terdapat hasil operasi selisih karena terdapat himpunan yang kosong.
    =======================================================================================================================*/
    // Kamus Data
    alamatsub p,q;
    char* irisan[20];
    char* bantup[20];
    char* bantuq[20];
    int i = 0;
    int j = 0;
    int k = 0;
    int np = 0;
    int nq = 0;

    if(IsSubEmpty(H1) && IsSubEmpty(H2)){
        printf("Operasi selisih tidak bisa digunakan karena kedua UKM tidak memiliki satupun anggota");
    } else {
        p = H1.first_sub;
        while (p != NULL){
            bantup[j] = p->member_sub;
            q = H2.first_sub;
            while (q != NULL){
                bantuq[k] = q->member_sub;
                if (strcmp(p->member_sub, q->member_sub) == 0 && strcmp(p->id_sub, q->id_sub) == 0) {
                    irisan[i] = p->member_sub;
                }
            q = q->next_sub;
            nq = nq + 1;
            }
        p = p->next_sub;
        np = np + 1;
        }
    }

    printf("Selisih UKM-1 terhadap UKM-2 adalah : ");
    for (int i = 0; i <= np; i++){
        int j = 0;
        if(strcmp(bantup[i], irisan[j]) == 0){
            bantup[i] = NULL;
            j++;
        }
    }

    for (int i = 0; i <= np; i++){
        printf("%s", bantup[i]);
    }

    printf("Selisih UKM-2 terhadap UKM-1 adalah : ");
    for (int i = 0; i <= np; i++){
        int j = 0;
        if(strcmp(bantuq[i], irisan[j]) == 0){
            bantuq[i] = NULL;
            j++;
        }
    }

    for (int i = 0; i <= np; i++){
        printf("%s", bantuq[i]);
    }
}

void display_menu() {
        system("cls");
    	printf("=========================================\n");
        printf("|    Kalkulator Himpunan UKM POLBAN     |\n");
        printf("=========================================\n");
        printf("| Menu: \t\t\t\t|\n");
        printf("| [1] Buat Himpunan \t\t\t|\n");
        printf("| [2] Operasi Himpunan \t\t\t|\n");
        printf("| [3] Edit Daftar Himpunan \t\t|\n");
        printf("| [4] Cari Anggota Himpunan \t\t|\n");
        printf("| [5] Tampilkan Daftar Himpunan \t|\n");
        printf("| [99] Exit \t\t\t\t|\n");
        printf("=========================================\n");

}

void WritePOLBAN(char nama_mhs[], char NIM[]){
    FILE *fp = fopen("POLBAN.txt", "a+");

    if(fp == NULL){
        printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
    }

    fprintf(fp, "%s\n", nama_mhs);
    fprintf(fp, "%s\n", NIM);

    fclose(fp);

    printf("Berhasil ditambahkan ke database POLBAN!\n");
}

void WriteUKM(int opsi, char nama_mhs[], char NIM[]){
    
    if(opsi == 1){
        FILE *fp = fopen("DKM.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database DKM!\n");
    } else if(opsi == 2){
        FILE *fp = fopen("KEWIRAUSAHAAN.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database KEWIRAUSAHAAN!\n");
    } else if(opsi == 3){
        FILE *fp = fopen("BADMINTON.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database BADMINTON!\n");
    } else if(opsi == 4){
        FILE *fp = fopen("BASKET.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database BASKET!\n");
    } else if(opsi == 5){
        FILE *fp = fopen("VOLI.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database VOLI!\n");
    } else if(opsi == 6){
        FILE *fp = fopen("POLBAN_CHESS.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database POLBAN_CHESS!\n");
    } else if(opsi == 7){
        FILE *fp = fopen("JFP.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database JFP!\n");
    } else if(opsi == 8){
        FILE *fp = fopen("ROBOTIK.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database ROBOTIK!\n");
    } else if(opsi == 9){
        FILE *fp = fopen("FELLAS.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database FELLAS!\n");
    } else if(opsi == 10){
        FILE *fp = fopen("USF.txt", "a+");

        if(fp == NULL){
            printf("\nFile tidak bisa dibuka atau tidak ditemukan!\n");
        }

        fprintf(fp, "%s\n", nama_mhs);
        fprintf(fp, "%s\n", NIM);

        fclose(fp);
        printf("Berhasil ditambahkan ke database USF!\n");
    }
     
}

void EkstrakPOLBAN(superset_list* S){
    int i = 0;
    FILE* fp = fopen("POLBAN.txt", "r");

    if(fp == NULL){
        printf("\nDatabase belum dibuat!\n");
    }

    char nama[61];
    char nim[10];
    char buffer[100];

    while(fgets(buffer, sizeof(buffer), fp)){
        //Token agar tidak mengambil new line
        char* token = strtok(buffer, "\n");
        strcpy(nama, buffer); 
        fgets(buffer, sizeof(buffer), fp);
        sscanf(buffer, "%9[^\n]", nim);
        
        if(!IsExistSuper(*S, nama, nim)){ 
            add_membersuper(S, nama, nim);
            i++;
        }
    }
    if(i > 0){
        printf("Berhasil mengekstrak database!");
    } else{
        printf("Tidak ada data yang dapat diekstrak!");
    }
           
    system("pause");

    fclose(fp);
}

void EkstrakUKM(superset_list S, subset_list* DKM, subset_list* KEWIRAUSAHAAN, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* USF){
    bool valid = false;
    
    while(!valid){
        int opsi = ListUKM();
        if(opsi==1){
            strcpy(DKM->first_sub->nama_sub, "DKM");
            CopyFromFile(S, DKM);
            valid = true;
        }else if(opsi==2){
            strcpy(KEWIRAUSAHAAN->first_sub->nama_sub, "KEWIRAUSAHAAN");
            CopyFromFile(S, KEWIRAUSAHAAN);
            valid = true;
        }else if(opsi==3){
            strcpy(BADMINTON->first_sub->nama_sub, "BADMINTON");
            CopyFromFile(S, BADMINTON);
            valid = true;
        }else if(opsi==4){
            strcpy(BASKET->first_sub->nama_sub, "BASKET");
            CopyFromFile(S, BASKET);
            valid = true;
        }else if(opsi==5){
            strcpy(VOLI->first_sub->nama_sub, "VOLI");
            CopyFromFile(S, VOLI);
            valid = true;
        }else if(opsi==6){
            strcpy(POLBAN_CHESS->first_sub->nama_sub, "POLBAN_CHESS");
            CopyFromFile(S, POLBAN_CHESS);
            valid = true;
        }else if(opsi==7){
            strcpy(JFP->first_sub->nama_sub, "JFP");
            CopyFromFile(S, JFP);
            valid = true;
        }else if(opsi==8){
            strcpy(ROBOTIK->first_sub->nama_sub, "ROBOTIK");
            CopyFromFile(S, ROBOTIK);
            valid = true;
        }else if(opsi==9){
            strcpy(FELLAS->first_sub->nama_sub, "FELLAS");
            CopyFromFile(S, FELLAS);
            valid = true;
        }else if(opsi==10){
            strcpy(USF->first_sub->nama_sub, "USF");
            CopyFromFile(S, USF);
            valid = true;
        }
    }
}

void CopyFromFile(superset_list S, subset_list* H){
    char nama_file[100];
    char nama[61];
    char nim[10];
    char buffer[100];
    alamatsub UKM;
    int i = 0;

    UKM = H->first_sub;
    sprintf(nama_file, "%s.txt", UKM->nama_sub);
    FILE* fp = fopen(nama_file, "r");


    if(fp == NULL){
        printf("\nDatabase belum dibuat!\n");
    }


    while(fgets(buffer, sizeof(buffer), fp)){
        //Token agar tidak mengambil new line
        char* token = strtok(buffer, "\n");
        strcpy(nama, buffer);
        fgets(buffer, sizeof(buffer), fp);
        sscanf(buffer, "%9[^\n]", nim);
        
        if(IsExistSuper(S, nama, nim)){
            if(!IsExistSub(*H, nama, nim)){ 
            add_membersub(H, nama, nim, UKM->nama_sub);
            i++;
        }
        }
    }
    if(i > 0){
        printf("Berhasil mengekstrak database!");
    } else{
        printf("Tidak ada data yang dapat diekstrak!");
    } 
    system("pause");
    fclose(fp); 
}