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
typedef struct subset1 *alamatsub1;
typedef struct subset1{
    char nama_sb1[10];
    char member_sb1[20];
    char id_sb1[10];
    alamatsub1 next_sb1;
}elmtsubset1;

typedef struct subset2 *alamatsub2;
typedef struct subset2{
    char nama_sb2[10];
    char member_sb2[20];
    char id_sb2[10];
    alamatsub2 next_sb2;
}elmtsubset2;

typedef struct superset* alamatsuper;
typedef struct superset{
    char nama_super[10];
    char member_sp[20];
    char id_member[10];
    alamatsuper next_sp;
    alamatsub1 super_sub1;
    alamatsub2 super_sub2;
}elmtsuper;

typedef struct{
    alamatsuper first_super;
}superset_list;

typedef struct {
    alamatsuper first_sub1;
}subset1_list;

typedef struct {
    alamatsuper first_sub2;
}subset2_list;

/*============================ METHOD ============================*/
void create_super (superset_list *S);
void CreateSub1 (subset1_list *H1);
void Createsub2 (subset2_list *H2);
bool IsSuperEmpty (superset_list S);
bool IsSubAEmpty (subset1_list H1);
bool IsSubBEmpty (subset2_list H2);
bool IsExistSuper(superset_list S, char nama_mhs[], char NIM[]);
bool IsExistSub1(subset1_list H1, char nama_mhs[], char NIM[]);
bool IsExistSub1(subset1_list H1, char nama_mhs[], char NIM[]);
bool IsSuperEmpty(superset_list S);
bool IsSubAEmpty(subset1_list H1);
bool IsSubBEmpty(subset2_list H2);
bool IsFull();
bool IsExistSuper(superset_list S, char nama, char id);
void add_membersuper(superset_list *S, char nama_mhs[], char NIM[]);
void add_memberSubA(subset1_list *H1, char nama_mhs[], char NIM[]);
void add_memberSubB(subset2_list *H2, char nama_mhs[], char NIM[]);
void Seleksi_MemberSuper(superset_list *S);
void del_membersuper(superset_list *S, char nama_mhs[], char NIM[]);
void del_memberSubA(subset1_list *H1, char nama_mhs[], char NIM[]);
void del_memberSubB(subset2_list *H2, char nama_mhs[], char NIM[]);
void Penghentian_Studi(superset_list *S);
void irisan(superset_list S, subset1_list H1, subset2_list H2);
void gabungan(superset_list S, subset1_list H1, subset2_list H2); 
void komplemen(superset_list S, subset1_list H1, subset2_list H2);
void selisih(superset_list S, subset1_list H1, subset2_list H2);
void append_history(superset_list S, subset1_list H1, subset2_list H2);
void write_cur(superset_list S, subset1_list H1, subset2_list H2);
void write_guide();
void display_cur();
void display_menu();
void display_search(superset_list S, subset1_list H1, subset2_list H2, char nama_mhs[], char NIM[]);
void display_guide();
void display_histori();


#endif /* SPHIMPUNAN_H */