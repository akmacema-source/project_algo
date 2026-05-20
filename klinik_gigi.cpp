#include <iostream>
#include <string.h>
#include <cstring>
#include <cstdlib>
using namespace std;

struct pasien
{
    char nama[50];
    char keluhan[50];
    char tindakan[50];
    char jadwalTemu[30];
    char tanggalTemu[20];
    int  NIK;
    int  biaya;
    pasien *kanan;
    pasien *kiri;
};

struct pegawai
{
    string username;
    string password;
};

struct riwayatObat
{
    char namaPasien[50];
    int  NIKPasien;
    char tindakan[50];
    char namaObat[100];
    char tanggal[20];
    riwayatObat *next;
};

pegawai akun[3] = {
    {"dokter",      "drg123"},
    {"adminklinik", "adm456"},
    {"asisten",     "ast789"}
};

pasien     *awal      = NULL;
pasien     *akhir     = NULL;
pasien     *bantu;
pasien     *hapus;
pasien     *NB;
pasien     *list;
pasien     *cek;
pasien      kry;
riwayatObat *awalObat = NULL;
 
int dataBaru   = 0;
int adanik     = 0;
int adajabatan = 0;
 
struct dataTindakan { const char *nama; int biaya; };
 
dataTindakan daftarTindakan[] = {
    {"Pembersihan Karang",  150000},
    {"Pemasangan Kawat",   3000000},
    {"Pemutihan Gigi",      500000},
    {"Tambal Gigi",         200000},
    {"Cabut Gigi",          250000},
    {"Gigi Kropos",         300000},
};
int totalTindakan = 6;

int listKosong()
{
    return (awal == NULL) ? 1 : 0;
}
