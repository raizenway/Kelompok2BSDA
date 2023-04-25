/*  AUTHOR      : Kelompok 2
    NAMA        : SpHimpunan.h
    DESKRIPSI   : Header untuk struktur data himpunan
    TANGGAL     : 16 APRIL 2023
=======================================================================================================================*/
#ifndef SPHIMPUNAN_H
#define SPHIMPUNAN_H
#include <stdio.h>
#include <stdbool.h>
/*============================ STRUKTUR DATA ============================*/
typedef struct subset *alamatsub;
typedef struct subset{
    char nama_sub[10];
    char member_sub[61];
    char id_sub[10];
    alamatsub next_sub;
}elmtsubset;

typedef struct superset* alamatsuper;
typedef struct superset{
    char nama_super[10];
    char member_sp[61];
    char id_member[10];
    alamatsuper next_sp;
}elmtsuper;

typedef struct{
    alamatsuper first_super;
}superset_list;

typedef struct {
    alamatsub first_sub;
}subset_list;

/*============================ METHOD ============================*/
void create_super (superset_list *S);
void create_sub (subset_list *H1);
bool IsSuperEmpty (superset_list S);
bool IsSubEmpty (subset_list H1);
bool IsExistSuper(superset_list S, char nama_mhs[], char NIM[]);
bool IsExistSub(subset_list H1, char nama_mhs[], char NIM[]);
bool IsSuperEmpty(superset_list S);
bool IsSubEmpty(subset_list H1);
bool IsFull();
void add_membersuper(superset_list *S, char nama_mhs[], char NIM[]);
void add_membersub(subset_list *H1, char nama_mhs[], char NIM[]);
void Seleksi_MemberSuper(superset_list *S);
void del_membersuper(superset_list *S, char nama_mhs[], char NIM[]);
void del_membersub(subset_list *H1, char nama_mhs[], char NIM[]);
void Penghentian_Studi(superset_list *S, char nama_mhs[], char NIM[]);
void irisan(superset_list S, subset_list H1 );
void gabungan(superset_list S, subset_list H1 ); 
void komplemen(superset_list S, subset_list H1 );
void selisih(superset_list S, subset_list H1 );
void append_history(superset_list S, subset_list H1 );
void write_cur(superset_list S, subset_list H1);
void write_guide();
void display_cur();
void display_menu();
void display_search(superset_list S, subset_list H1, char nama_mhs[], char NIM[]);
void display_guide();
void display_histori();
void menu_addsub(subset_list* DKM, subset_list* MUSKING, subset_list* BADMINTON, subset_list* BASKET, subset_list* VOLI, subset_list* POLBAN_CHESS, subset_list* JFP, subset_list* ROBOTIK, subset_list* FELLAS, subset_list* FUTSAL);
int ListUKM();
int OpsiUKM();
void addnama(char* nama_mhs);
void addnim(char* NIM);
void ekstraklist(subset_list* H, subset_list DKM, subset_list MUSKING, subset_list BADMINTON, subset_list BASKET, subset_list VOLI, subset_list POLBAN_CHESS, subset_list JFP, subset_list ROBOTIK, subset_list FELLAS, subset_list FUTSAL);

#endif /* SPHIMPUNAN_H */