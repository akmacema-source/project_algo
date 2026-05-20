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