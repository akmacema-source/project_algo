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

void tampilTindakan()
{
    cout << "\n==========================================" << endl;
    cout << "       DAFTAR TINDAKAN & BIAYA            " << endl;
    cout << "==========================================" << endl;
    for (int i = 0; i < totalTindakan; i++)
        cout << "  " << (i+1) << ". " << daftarTindakan[i].nama
             << " - Rp " << daftarTindakan[i].biaya << endl;
    cout << "==========================================" << endl;
}
 
int getBiayaTindakan(char tindakan[50])
{
    for (int i = 0; i < totalTindakan; i++)
        if (strcasecmp(daftarTindakan[i].nama, tindakan) == 0)
            return daftarTindakan[i].biaya;
    return 0;
}

void cekJadwalDokter()
{
    cout << "\n==========================================" << endl;
    cout << "       JADWAL PRAKTEK KLINIK GIGI         " << endl;
    cout << "==========================================" << endl;
    cout << "  Dokter  : drg. Rahma Aulia, Sp.KG       " << endl;
    cout << "  Senin   : 09.00 - 13.00                 " << endl;
    cout << "  Selasa  : 09.00 - 13.00                 " << endl;
    cout << "  Rabu    : 14.00 - 18.00                 " << endl;
    cout << "  Kamis   : 09.00 - 13.00                 " << endl;
    cout << "  Jumat   : 14.00 - 18.00                 " << endl;
    cout << "  Sabtu   : 09.00 - 14.00                 " << endl;
    cout << "  Minggu  : Libur                         " << endl;
    cout << "==========================================" << endl;
}

void input()
{
    int jumlahInput;
    cout << "\n Masukkan jumlah data pasien : ";
    cin  >> jumlahInput;
 
    for (int i = 0; i < jumlahInput; i++)
    {
        NB = new pasien;
        cout << "\n Data ke-" << dataBaru + 1 << endl;
 
        cin.ignore();
        cout << " Masukkan Nama          : ";
        cin.getline(kry.nama, sizeof(kry.nama));
        strcpy(NB->nama, kry.nama);
 
        do
        {
            adanik = 1;
            cout << " Masukkan NIK           : ";
            cin  >> kry.NIK;
            NB->NIK = kry.NIK;
            bantu = awal;
            while (bantu != NULL)
            {
                if (kry.NIK == bantu->NIK)
                {
                    cout << " NIK tidak boleh sama!" << endl;
                    adanik = 0;
                    break;
                }
                bantu = bantu->kanan;
            }
        } while (adanik == 0);

        cin.ignore();
        cout << " Masukkan Keluhan       : ";
        cin.getline(kry.keluhan, sizeof(kry.keluhan));
        strcpy(NB->keluhan, kry.keluhan);
 
        tampilTindakan();
        do
        {
            adajabatan = 1;
            cout << " Masukkan Tindakan      : ";
            cin.getline(kry.tindakan, sizeof(kry.tindakan));
            strcpy(NB->tindakan, kry.tindakan);
 
            int cekBiaya = getBiayaTindakan(kry.tindakan);
            if (cekBiaya == 0)
            {
                cout << " Tindakan tidak valid! Pilih dari daftar di atas." << endl;
                adajabatan = 0;
            }
            else
                NB->biaya = cekBiaya;
        } while (adajabatan == 0);

        cout << " Masukkan Tanggal Temu  : ";
        cin.getline(kry.tanggalTemu, sizeof(kry.tanggalTemu));
        strcpy(NB->tanggalTemu, kry.tanggalTemu);
 
        cout << " Masukkan Jadwal Jam    : ";
        cin.getline(kry.jadwalTemu, sizeof(kry.jadwalTemu));
        strcpy(NB->jadwalTemu, kry.jadwalTemu);
 
        NB->kanan = NULL;
        NB->kiri  = NULL;
 
                if (listKosong())
        {
            awal  = NB;
            akhir = NB;
        }
        else
        {
            akhir->kanan = NB;
            NB->kiri     = akhir;
            akhir        = NB;
        }
        dataBaru++;
    }
    cout << "\n Data pasien berhasil ditambahkan!" << endl;
}

void output()
{
    if (listKosong())
    {
        cout << "\n Belum ada data pasien!" << endl;
        return;
    }
    bantu  = awal;
    int no = 1;
    int totalPendapatan = 0;
 
    cout << "\n==========================================" << endl;
    cout << "       DATA PASIEN KLINIK GIGI            " << endl;
    cout << "==========================================" << endl;
 while (bantu != NULL)
    {
        cout << " Data ke-" << no << endl;
        cout << "  Nama Pasien  : " << bantu->nama       << endl;
        cout << "  NIK          : " << bantu->NIK        << endl;
        cout << "  Keluhan      : " << bantu->keluhan    << endl;
        cout << "  Tindakan     : " << bantu->tindakan   << endl;
        cout << "  Tanggal Temu : " << bantu->tanggalTemu<< endl;
        cout << "  Jam Temu     : " << bantu->jadwalTemu << endl;
        cout << "  Biaya        : Rp " << bantu->biaya   << endl;
        cout << "------------------------------------------" << endl;
        totalPendapatan += bantu->biaya;
        bantu = bantu->kanan;
        no++;
    }
    cout << " Total Pasien      : " << dataBaru          << endl;
    cout << " Total Pendapatan  : Rp " << totalPendapatan<< endl;
    cout << "==========================================" << endl;
}