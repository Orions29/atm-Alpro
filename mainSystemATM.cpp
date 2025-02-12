#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib> // untuk menggunakan system("cls")
#include <ctime>   // untuk mengatur seed pada fungsi rand()
#include <thread>  // untuk menggunakan fungsi multithreading cnth sleep_for
#include <chrono>  // untuk menangani waktu dengan tepat sangat penting karena untuk penggunaan sleep_for yang membutuhkan parameter bertipe durasi
using namespace std;
// >> Struct Init
// NOTE Dimasukkan ke Multifile
// Struct untuk Histori
struct histori
{
      int idTrans;
      int nominal;
      int noRektuj;
      string deskripsi;
};
// Struct Untuk data nasabah
struct nasabah
{
      int noRek;
      string pass;
      string nama;
      int saldo;
      int jumlahTrans;
      histori historiNasabah[100];
};
// >> Global Var Init
bool mainMenuLoop = true, loginStat = false, adminStat = false;
int indexNasabah = -1;
// Inisialisasi Global Array (Wajib Ada)
nasabah dataNasabah[100]; // menyimpan 100 data 100 nasabah
int jumlahNasabah = 0;    // Total Jumlah Data yang dimiliki
// >> Decklare Funtion
// Error handling Func (Overload)
void inputHandling(string question, string &var, short lineOr); // Untuk String
void inputHandling(string question, int &var);                  // untuk int
void inputHandling(string question, float &var);                // untuk float
void inputHandling(string question, short &var);                // untuk short
// Init Data Nasabah
void inisialisasiData();
// CRUD Funct Data Nasabah
void tampilDataNasabah();
void inputNasabah();
void delNasabah();
// Main Feature
void login();
void cekSaldo();
void setorSaldo();
void tarikSaldo();
void transferRekening();
void riwayatTransaksi();
// Pause Function
void Pause();
// Function untuk Pause
void SlowType(const string &kata, int delay);
void DeleteText(int count, int delay);
// Execution Funct
int main()
{
      short opt;
      // Identitas Pembuat
      cout << "\n<Selamat Datang di ATM Program ATM> \nKarya: "
           << " \t\n1. Zaka Ahmad Ghofari             (123240144)"
           << " \t\n2. Dimas Hafid Fathoni            (123240159)"
           << " \t\n3. Erlan Rifqi Davin Darmawan     (123240173)"
           << " \t\n4. Jauza Ilham Mahardika Putra    (123240174)"
           << " \t\n5. Rio Meidi Ataurrahman          (123240175)\n\n";
      // Inisialisasi Data awal
      inisialisasiData();
      // Login Masuk Rekening
      do
      {
            loginStat = false;
            login();
            do
            {
                  if (adminStat == true)
                  {
                        system("cls");
                        cout << "\t\t <<Menu Admin>>\n\n";
                        cout << "1> Input Nasabah\n\n";
                        cout << "2> Delete Nasabah\n\n";
                        cout << "3> Tampil Nasabah\n\n";
                        inputHandling("\n Admin Mau Yang Mana?: ", opt);
                        switch (opt)
                        {
                        case 1:
                              Pause();
                              inputNasabah();
                              break;
                        case 2:
                              Pause();
                              delNasabah();
                              break;
                        case 3:
                              Pause();
                              tampilDataNasabah();
                              break;
                        default:
                              cout << "\nTerimakasih telah menggunakan ATM ini Mas Admin\n";
                              Pause();
                              mainMenuLoop = false;
                        }
                  }
                  else
                  {
                        // Penampil Menu Utama
                        system("cls");
                        cout << "\t\t <<Menu ATM>>\n";
                        cout << left << setw(25) << "1> Cek Saldo" << right << setw(25) << "Tarik Tunai <4\n\n";
                        cout << left << setw(25) << "2> Deposit Saldo" << right << setw(25) << "Riwayat Transaksi <5\n\n";
                        cout << left << setw(25) << "3> Transfer Rekening" << right << setw(25) << "Exit <6\n\n";
                        // Input User
                        inputHandling("\nNasabah Mau Yang Mana?: ", opt);
                        switch (opt)
                        {
                        case 1:
                              Pause();
                              cekSaldo();
                              break;
                        case 2:
                              Pause();
                              setorSaldo();
                              break;
                        case 3:
                              Pause();
                              transferRekening();
                              break;
                        case 4:
                              Pause();
                              tarikSaldo();
                              break;
                        case 5:
                              Pause();
                              riwayatTransaksi();
                              break;
                        case 6:
                              cout << "\nTerimakasih telah menggunakan ATM ini\n";
                              Pause();
                              mainMenuLoop = false;
                              loginStat = false;
                              break;
                        default:
                              cout << "[Input Error] - Pilihan yang Anda masukkan salah\n";
                        }
                  }
            } while (mainMenuLoop == true);
      } while (loginStat == false);
      return 0;
}
// >> Desc Function
// Error Handling Funct
// Overloading Funct untuk Error Handling Pengguna
void inputHandling(string question, string &var, short lineOr)
{
      bool statLoop = false;
      do
      {
            cout << question;
            // Jika 1 maka Spasi dianggap kesalahan
            if (lineOr == 1)
            {
                  cin >> var;
            }
            // Jika 2 maka spasi akan dibaca
            else if (lineOr == 2)
            {
                  cin.ignore(30, '\n'); // Mengabaikan Input
                  getline(cin, var);
            }
            if (cin.fail())
            {
                  cin.clear();          // Menghapus Semua Fail Flag
                  cin.ignore(30, '\n'); // Mengabaikan Input
                  cout << "\n[ERROR CIN,not str] -" << "Input Tidak Sesuai\n";
                  statLoop = true;
            }
            else
            {
                  statLoop = false;
            }
      } while (statLoop == true);
};
// Untuk Variabel Integer
void inputHandling(string question, int &var)
{
      bool statLoop = false;
      do
      {
            cout << question;
            cin >> var;
            if (cin.fail())
            {
                  cin.clear();          // Menghapus Semua Fail Flag
                  cin.ignore(30, '\n'); // Mengabaikan Input
                  cout << "\n[ERROR CIN,not int] -" << "Input Tidak Sesuai\n";
                  statLoop = true;
            }
            else
            {
                  statLoop = false;
            }
      } while (statLoop == true);
};
// Untuk Variabel FLoat
void inputHandling(string question, float &var)
{
      cout << question;
      bool statLoop = false;
      do
      {
            cin >> var;
            if (cin.fail())
            {
                  cin.clear();          // Menghapus Semua Fail Flag
                  cin.ignore(30, '\n'); // Mengabaikan Input
                  cout << "\n[ERROR CIN,not float] -" << "Input Tidak Sesuai\n";
                  statLoop = true;
            }
            else
            {
                  statLoop = false;
            }
      } while (statLoop == true);
};
// Untuk Short Short
void inputHandling(string question, short &var)
{
      cout << question;
      bool statLoop = false;
      do
      {
            cin >> var;
            if (cin.fail())
            {
                  cin.clear();          // Menghapus Semua Fail Flag
                  cin.ignore(30, '\n'); // Mengabaikan Input
                  cout << "\n[ERROR CIN,not shortInt] -" << "Input Tidak Sesuai\n";
                  statLoop = true;
            }
            else
            {
                  statLoop = false;
            }
      } while (statLoop == true);
};
// Data Init Function
void inisialisasiData()
{
      dataNasabah[jumlahNasabah++] =
          {459777345, "admin", "Sosok Asli Admin", 9999999, 0, {}}; // Sosok Asli Admin
      dataNasabah[jumlahNasabah++] =
          {23240144, "admin123", "Zaka Ahmad Ghofari", 2500000, 12,
           {// biar spasi
            {51, 50000, 87654326, "Qris"},
            {61, 900000, 87654327, "Top Up Dana"},
            {71, 200000, 87654318, "Virtual Acc"},
            {52, 400000, 87654328, "Qris"},
            {62, 75000, 87654353, "Top UP Dana"},
            {72, 800000, 87654328, "Virtual Acc"},
            {73, 960000, 87654330, "Virtual Acc"},
            {53, 115000, 87654402, "Qris"},
            {63, 120000, 87654560, "Top Up Dana"},
            {64, 980000, 87654975, "Top Up Gopay"},
            {90, 650000, 87650642, "Transfer"},
            {74, 850000, 87654340, "Transfer Saldo"}}};
      dataNasabah[jumlahNasabah++] =
          {23240159, "admin321", "Dimas Hafid Fathoni", 6500000, 12,
           {// biar spasi
            {51, 50000, 87654326, "Qris"},
            {61, 900000, 87654327, "Top Up Dana"},
            {71, 200000, 87654318, "Virtual Acc"},
            {52, 400000, 87654328, "Qris"},
            {62, 75000, 87654353, "Top UP Dana"},
            {72, 800000, 87654328, "Virtual Acc"},
            {73, 960000, 87654330, "Virtual Acc"},
            {53, 115000, 87654402, "Qris"},
            {63, 120000, 87654560, "Top Up Dana"},
            {64, 980000, 87654975, "Top Up Gopay"},
            {90, 650000, 87650642, "Transfer"},
            {74, 850000, 87654340, "Virtual Acc"}}};
      dataNasabah[jumlahNasabah++] =
          {23240173, "admin3221", "Erlan Rifqi Davin D", 5000000, 12,
           {// biar spasi
            {51, 50000, 87654326, "Qris"},
            {61, 900000, 87654327, "Top Up Dana"},
            {71, 200000, 87654318, "Virtual Acc"},
            {52, 400000, 87654328, "Qris"},
            {62, 75000, 87654353, "Top UP Dana"},
            {72, 800000, 87654328, "Virtual Acc"},
            {73, 960000, 87654330, "Virtual Acc"},
            {53, 115000, 87654402, "Qris"},
            {63, 120000, 87654560, "Top Up Dana"},
            {64, 980000, 87654975, "Top Up Gopay"},
            {90, 650000, 87650642, "Transfer"},
            {74, 850000, 87654340, "Virtual Acc"}}};
      dataNasabah[jumlahNasabah++] =
          {23240174, "admin3214", "Jauza Ilham Mahardika P", 10000000, 12,
           {// biar spasi
            {51, 50000, 87654326, "Qris"},
            {61, 900000, 87654327, "Top Up Dana"},
            {71, 200000, 87654318, "Virtual Acc"},
            {52, 400000, 87654328, "Qris"},
            {62, 75000, 87654353, "Top UP Dana"},
            {72, 800000, 87654328, "Virtual Acc"},
            {73, 960000, 87654330, "Virtual Acc"},
            {53, 115000, 87654402, "Qris"},
            {63, 120000, 87654560, "Top Up Dana"},
            {64, 980000, 87654975, "Top Up Gopay"},
            {90, 650000, 87650642, "Transfer"},
            {74, 850000, 87654340, "Virtual Acc"}}};
      dataNasabah[jumlahNasabah++] =
          {23240175, "admin3215", "Rio Meidi A", 9000000, 12,
           {// biar spasi
            {51, 50000, 87654326, "Qris"},
            {61, 900000, 87654327, "Top Up Dana"},
            {71, 200000, 87654318, "Virtual Acc"},
            {52, 400000, 87654328, "Qris"},
            {62, 75000, 87654353, "Top UP Dana"},
            {72, 800000, 87654328, "Virtual Acc"},
            {73, 960000, 87654330, "Virtual Acc"},
            {53, 115000, 87654402, "Qris"},
            {63, 120000, 87654560, "Top Up Dana"},
            {64, 980000, 87654975, "Top Up Gopay"},
            {90, 650000, 87650642, "Transfer"},
            {74, 850000, 87654340, "Virtual Acc"}}};
      dataNasabah[jumlahNasabah++] =
          {23240111, "admin123", "Test Empty Set", 0, 0, {
                                                             // biar spasi
                                                         }};
      // Kalau Kurang silahkan di tambah sendiri
}
// CRUD Funct
// Fungsi Untuk Menampilkan Data Nasabah dengan parameter nomor rekening
void tampilDataNasabah()
{
      system("cls");
      bool find = false;
      int noRekIn = 0;
      cout << "\n\t>- Menu Tampil Data Nasabah -<\n\n";
      Pause();
      inputHandling("Berapa Nomor Rekeningnya?: ", noRekIn);
      for (int i = 0; i <= jumlahNasabah; i++)
      {
            if (noRekIn == dataNasabah[i].noRek)
            {
                  find = true;
                  cout << "\n\t<Lihat Data Dan Histori>\n"
                       << endl;
                  cout << "Nasabah:" << endl;
                  cout << "\n Data Nasabah:" << endl;
                  cout << "No Rek  : " << dataNasabah[i].noRek << endl;
                  cout << "Nama    : " << dataNasabah[i].nama << endl;
                  cout << "Saldo   : " << dataNasabah[i].saldo << endl;
                  cout << "\nHistori Transaksi:" << endl;
                  if (dataNasabah[i].historiNasabah[0].idTrans > 0)
                  {
                        for (int j = 0; j < dataNasabah[i].jumlahTrans; ++j)
                        {
                              cout << "Nomor     : " << j + 1 << endl;
                              cout << "ID Trans  : " << dataNasabah[i].historiNasabah[j].idTrans << endl;
                              cout << "Nominal   : " << dataNasabah[i].historiNasabah[j].nominal << endl;
                              cout << "No Rek T  : " << dataNasabah[i].historiNasabah[j].noRektuj << endl;
                              cout << "Deskripsi : " << dataNasabah[i].historiNasabah[j].deskripsi << endl;
                              cout << endl;
                        }
                  }
                  else
                  {
                        cout << "\n [Empty Set] - Belum Memiliki Riwayat Transaksi\n";
                  }
                  break;
            }
            else
            {
                  find = false;
            }
      }
      find == false ? cout << "\n [Error Tag]- Rekening Tak ditemukan\n" : cout << "\n <Data Tertampil Semua>";
      cout << "\nTekan karakter apapun untuk melanjutkan...";
      cin.ignore(1000, '\n');
      cin.get();
}
// Funct Untuk Input Nasabah
void inputNasabah()
{
      system("cls");
      Pause();
      jumlahNasabah++;
      cout << "\n\n\t>-Menu Input Nasabah Baru-<\n";
      cout << "\n\nHallo Nasabah Baru!!";
      cout << "\n Data Nasabah:" << endl;
      inputHandling("\nNo Rek  : ", dataNasabah[jumlahNasabah].noRek);
      inputHandling("\nPass    : ", dataNasabah[jumlahNasabah].pass, 1);
      inputHandling("\nNama    : ", dataNasabah[jumlahNasabah].nama, 2);
      inputHandling("\nSaldo   : ", dataNasabah[jumlahNasabah].saldo);
      dataNasabah[jumlahNasabah].jumlahTrans = 0; // Nasabah Baru Tidak Memiliki Histori Transaksi
}
// Fungsi untuk delete data nasabah
void delNasabah()
{
      cout << "\n\n\t>-Menu Delete Data Nasabah-<\n";
      system("cls");
      Pause();
      int noRekIn;
      short opt;
      bool find = true;
      do
      {
            inputHandling("Berapa Nomor Rekeningnya?: ", noRekIn);
            for (int i = 0; i <= jumlahNasabah; i++)
            {
                  if (noRekIn == dataNasabah[i].noRek)
                  {
                        find = true;
                        cout << "\nSuccess Delete Data user {" << dataNasabah[i].nama << "} ";
                        dataNasabah[i] = {
                            0,
                            "",
                            "",
                            0,
                            0,
                            {}}; // Code Pengosongan Data Nasabah
                        break;
                  }
                  else
                  {
                        find = false;
                  }
            }
            if (find == false)
            {
                  cout << "\n[Error Tag] - Input Not Found - Wah ini gaada nih gimana dong?\n";
                  inputHandling("\n(1)Ulang or (2)Kembali?: ", opt);
                  if (opt == 1)
                  {
                        find = false;
                  }
                  else
                  {
                        find = true;
                        cout << "\n Hapus No Rek <" << noRekIn << "> Dibatalkan";
                  }
            }
      } while (find == false);
      cin.ignore(1000, '\n');
      cin.get();
}
// >> Main Feature Funct Desc
// Fungsi Login
void login()
{
      int noRekIn;
      string passIn;
      int max_chance = 3;
      do
      {
            inputHandling("\nMasukkan Nomor Rekening (8 Digit)\n>> ", noRekIn);
            inputHandling("\nMasukkan Password Rekening\n>> ", passIn, 1);
            for (int i = 0; i <= jumlahNasabah; i++)
            {
                  if (noRekIn == dataNasabah[i].noRek && passIn == dataNasabah[i].pass)
                  {
                        if (dataNasabah[i].noRek == 459777345)
                        {
                              adminStat = true;
                              loginStat = true;
                        }
                        else
                        {
                              loginStat = true;
                              indexNasabah = i; // Memasukkan noRekLogin kedalam list on admin
                        }
                        break;
                  }
            }
            if (loginStat == true)
            {
                  cout << "\n<Login berhasil>\n";
                  Pause();
                  cout << "\n <= Selamat Datang " << dataNasabah[indexNasabah].nama << " =>\n\n";
                  cout << "Data Rekening :" << endl;
                  cout << setw(10) << "A.N." << setw(5) << ": " << dataNasabah[indexNasabah].nama << endl;
                  cout << setw(10) << "No.Rek" << setw(5) << " : " << dataNasabah[indexNasabah].noRek << endl;
                  Pause();
                  break;
            }
            else
            {
                  cout << "\n[Login gagal] - Kesempatan Anda tersisa " << (--max_chance) << endl;
            }
      } while (max_chance > 0);
      if (max_chance == 0)
      {
            cout << "<Kesempatan Anda habis. Program akan keluar.>";
            exit(0);
      }
}
// Fungsi Cek Saldo
void cekSaldo()
{
      short pilihan;
      do
      {
            cout << "\nSaldo Anda: \n";
            cout << "\tRp" << fixed << dataNasabah[indexNasabah].saldo << ",00" << endl;
            cout << "\n\t\t Kembali <1";
            cout << "\n\t\t Keluar  <2\n";
            inputHandling("\n>> ", pilihan);
            if (pilihan == 1)
            {
                  Pause();
                  return;
            }
            else if (pilihan == 2)
            {
                  cout << "\nTerima Kasih telah menggunakan ATM ini\n";
                  Pause();
                  exit(0);
            }
            else
            {
                  cout << "\n[ERROR] - Input tidak valid\n";
            }
      } while (pilihan != 1 && pilihan != 2);
}
// Function Setor Saldo
void setorSaldo()
{
      int jumlah;
      short pilihan;
      srand(time(0)); // mengatur seed pada rand() untuk menggunakan waktu saat ini memastikan tidak membawa seed bawaan ctime
      do
      {
            cout << "\n <= Setor Saldo =>\n\n";
            cout << "Data Rekening :" << endl;
            cout << setw(10) << "A.N." << setw(5) << ": " << dataNasabah[indexNasabah].nama << endl;
            cout << setw(10) << "No.Rek" << setw(5) << " : " << dataNasabah[indexNasabah].noRek << endl;
            cout << "Deposit" << setw(5) << ": Rp";
            inputHandling("", jumlah);
            cout << endl;
            cout << setw(15) << "Konfirmasi <1" << endl;
            cout << setw(15) << "Kembali <2" << endl;
            inputHandling("\n>> ", pilihan);
            if (pilihan == 1)
            {
                  dataNasabah[indexNasabah].saldo += jumlah;
                  dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].nominal = jumlah;
                  dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].idTrans = rand() % 90000000 + 10000000; // Nomor Id acak mengambil dari rentang 0 hingga 89999999 kemudian ditambahkan 10000000
                  dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].noRektuj = dataNasabah[indexNasabah].noRek;
                  dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].deskripsi = "Setor Saldo";
                  dataNasabah[indexNasabah].jumlahTrans++;
                  cout << "\nSystem is ";
                  SlowType("processing", 100);
                  this_thread::sleep_for(chrono::seconds(1));
                  DeleteText(20, 100);
                  SlowType("Setor Tunai berhasil", 100);
                  cout << endl;
                  this_thread::sleep_for(chrono::seconds(1));
                  system("cls");
                  return;
            }
            else if (pilihan == 2)
            {
                  cout << "\nSetoran dibatalkan\n";
                  Pause();
                  return;
            }
            else
            {
                  cout << "\n[ERROR] - Input tidak valid\n";
            }
      } while (pilihan != 1 && pilihan != 2);
}
// Function Tarik Saldo
void tarikSaldo()
{
      int jumlah;
      short pilihan;
      srand(time(0)); // mengatur seed pada rand() untuk menggunakan waktu saat ini memastikan tidak membawa seed bawaan ctime
      do
      {
            cout << "\n <= Tarik Tunai =>\n\n";
            cout << "Data Rekening :" << endl;
            cout << setw(10) << "A.N." << setw(5) << ": " << dataNasabah[indexNasabah].nama << endl;
            cout << setw(10) << "No.Rek" << setw(5) << " : " << dataNasabah[indexNasabah].noRek << endl;
            cout << "Nominal" << setw(5) << ": Rp";
            inputHandling("", jumlah);
            cout << endl;
            cout << setw(15) << "Konfirmasi <1" << endl;
            cout << setw(15) << "Kembali <2" << endl;
            inputHandling("\n>> ", pilihan);

            if (pilihan == 1)
            {
                  if (dataNasabah[indexNasabah].saldo < jumlah)
                  {
                        cout << "\nSystem is ";
                        SlowType("processing", 100);
                        this_thread::sleep_for(chrono::seconds(1));
                        DeleteText(20, 100);
                        SlowType("Tarik Tunai Gagal Saldo tidak Mencukupi", 300);
                        cout << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                        system("cls");
                        return;
                  }
                  else
                  {
                        dataNasabah[indexNasabah].saldo -= jumlah;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].nominal = -jumlah;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].idTrans = rand() % 90000000 + 10000000; // Nomor Id acak mengambil dari rentang 0 hingga 89999999 kemudian ditambahkan 10000000
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].noRektuj = dataNasabah[indexNasabah].noRek;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].deskripsi = "Tarik Saldo";
                        dataNasabah[indexNasabah].jumlahTrans++;
                        cout << "\nSystem is ";
                        SlowType("processing", 100);
                        this_thread::sleep_for(chrono::seconds(1));
                        DeleteText(20, 100);
                        SlowType("Tarik Tunai berhasil", 100);
                        cout << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                        system("cls");
                        return;
                  }
            }
            else if (pilihan == 2)
            {
                  cout << "\nTarik Tunai dibatalkan\n";
                  Pause();
                  return;
            }
            else
            {
                  cout << "\n[ERROR] - Input tidak valid\n";
            }
      } while (pilihan != 1 && pilihan != 2);
}
// Function Transfer Rekening
void transferRekening()
{
      int rekening_tujuan, jumlah, indexFound;
      short pilihan;
      bool find = false;
      srand(time(0)); // mengatur seed pada rand() untuk menggunakan waktu saat ini memastikan tidak membawa seed bawaan ctime
      do
      {
            do
            {
                  inputHandling("\nMasukkan Nomor Rekening tujuan (8 digit) : ", rekening_tujuan);
                  for (int i = 0; i < jumlahNasabah; i++)
                  {
                        if (dataNasabah[i].noRek == rekening_tujuan)
                        {
                              find = true;
                              indexFound = i;
                              break;
                        }
                        else
                              find = false;
                  }
                  if (find == true)
                  {
                        cout << "\n <= Transfer Deposito =>\n\n";
                        cout << "Data Rekening :" << endl;
                        cout << setw(40) << "A.N." << setw(5) << " : " << dataNasabah[indexFound].nama << endl;
                        cout << setw(40) << "No.Rek" << setw(5) << " : " << dataNasabah[indexFound].noRek << endl;
                  }
                  else
                  {
                        cout << "\nNomor Rekening yang Anda Masukkan tidak valid\n";
                  }
            } while (find == false);
            cout << "Nominal" << setw(5) << ": Rp";
            inputHandling("", jumlah);
            cout << endl;
            cout << setw(15) << "Konfirmasi <1" << endl;
            cout << setw(15) << "Kembali <2" << endl;
            inputHandling("\n>> ", pilihan);
            if (pilihan == 1)
            {
                  if (dataNasabah[indexNasabah].saldo < jumlah)
                  {
                        cout << "\nSystem is ";
                        SlowType("processing", 100);
                        this_thread::sleep_for(chrono::seconds(1));
                        DeleteText(20, 100);
                        SlowType("Transfer Gagal Saldo tidak Mencukupi", 300);
                        cout << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                        system("cls");
                        return;
                  }
                  else
                  {
                        // Update Data Nasabah Pengirim
                        dataNasabah[indexNasabah].saldo -= jumlah;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].nominal = -jumlah;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].idTrans = rand() % 90000000 + 10000000; // Nomor Id acak mengambil dari rentang 0 hingga 89999999 kemudian ditambahkan 10000000
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].noRektuj = dataNasabah[indexNasabah].noRek;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].deskripsi = "Transfer Saldo";
                        dataNasabah[indexNasabah].jumlahTrans++;
                        // Update Data Nasabah Penerima
                        dataNasabah[indexFound].saldo += jumlah;
                        dataNasabah[indexFound].historiNasabah[dataNasabah[indexFound].jumlahTrans].nominal = jumlah;
                        dataNasabah[indexFound].historiNasabah[dataNasabah[indexFound].jumlahTrans].idTrans = rand() % 90000000 + 10000000; // Nomor Id acak mengambil dari rentang 0 hingga 89999999 kemudian ditambahkan 10000000
                        dataNasabah[indexFound].historiNasabah[dataNasabah[indexFound].jumlahTrans].noRektuj = dataNasabah[indexFound].noRek;
                        dataNasabah[indexFound].historiNasabah[dataNasabah[indexFound].jumlahTrans].deskripsi = "Menerima Saldo";
                        dataNasabah[indexFound].jumlahTrans++;
                        cout << "\nSystem is ";
                        SlowType("processing", 100);
                        this_thread::sleep_for(chrono::seconds(1));
                        DeleteText(20, 100);
                        SlowType("Trasnfer berhasil", 100);
                        cout << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                        system("cls");
                        return;
                  }
            }
            else if (pilihan == 2)
            {
                  cout << "\n[Transfer dibatalkan]\n";
                  Pause();
                  return;
            }
            else
            {
                  cout << "\n[ERROR] - Input tidak valid\n";
            }
      } while (pilihan != 1 && pilihan != 2);
}
// Function Riwayat Transaksi
void riwayatTransaksi()
{
      const int transHal = 5;
      int halaman = 0, totalHal = (dataNasabah[indexNasabah].jumlahTrans) / transHal; // Menghitung Jumlah Halaman
      dataNasabah[indexNasabah].jumlahTrans % transHal != 0 ? totalHal++ : totalHal;
      short pilihan;
      bool exit = false;
      if (dataNasabah[indexNasabah].jumlahTrans == 0)
      {
            cout << "[Empty Set] - Riwayat transaksi anda belum ada\n";
            Pause();
            return;
      }
      do
      {
            system("cls");
            cout << "<= Riwayat Transaksi =>\n";
            cout << "Page (" << halaman + 1 << "/" << totalHal << ")\n";
            cout << left << "| " << setw(3) << "No." << " | " << setw(15) << "Id Transaksi" << " | " << setw(20) << "Nominal" << " | " << setw(15) << "Rekening Tujuan" << " | " << setw(15) << "Deskripsi" << " |" << endl;
            cout << setfill('+') << setw(84) << "+" << endl
                 << setfill(' ');
            for (int i = halaman * transHal; i < (halaman * transHal) + transHal; i++)
            {
                  cout << right << "| " << setw(3) << i + 1 << " | " << setw(15) << dataNasabah[indexNasabah].historiNasabah[i].idTrans << " | Rp" << setw(15) << dataNasabah[indexNasabah].historiNasabah[i].nominal << ",00" << " | " << setw(15) << dataNasabah[indexNasabah].historiNasabah[i].noRektuj << " | " << setw(15) << dataNasabah[indexNasabah].historiNasabah[i].deskripsi << " |" << endl;
            }
            cout << setfill('+') << setw(84) << "+" << endl
                 << setfill(' ') << endl;
            cout << setw(84) << "Next Page     1<\n";
            cout << setw(84) << "Previous Page 2<\n";
            cout << setw(84) << "Kembali        3<\n";
            inputHandling("\n>> ", pilihan);
            if (pilihan == 1)
            {
                  if (halaman + 1 < totalHal)
                  {
                        halaman++;
                  }
            }
            else if (pilihan == 2)
            {
                  if (halaman > 0)
                  {
                        halaman--;
                  }
            }
            else if (pilihan == 3)
            {
                  exit = true;
            }
            else
            {
                  cout << "[ERROR INPUT] - pilihan yang Anda masukkan salah\n";
                  Pause();
            }
      } while (exit == false);
      Pause();
}
// Function pause dilengkapi cls
void Pause()
{
      cout << "\nSystem is ";
      SlowType("processing", 100);                // menggunakan fungsi slowtype() mengetik dengan delay 100 milidetik setiap karakter
      this_thread::sleep_for(chrono::seconds(1)); // memberikan jeda selama 1 detik menggunakan sleep_for dari library thread
      DeleteText(10, 100);                        // menghapus 10 karakter dengan delay 100 milidetik
      SlowType("completed", 100);                 // mengetik dengan delay 100 milidetik setiap karakter
      cout << endl;
      this_thread::sleep_for(chrono::seconds(1)); // memberikan jeda selama 1 detik menggunakan sleep_for dari library thread
      system("cls");
}
// Animasi untuk pause
void SlowType(const string &kata, int delay) // menampilkan kata satu per satu dengan jeda waktu
{
      for (char c : kata) // membaca setiap karakter yang diinginkan
      {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(delay));
      }
}
void DeleteText(int count, int delay) // menghapus karakter satu per satu dengan jeda waktu
{
      for (int i = 0; i < count; ++i)
      {
            cout << "\b \b" << flush;
            this_thread::sleep_for(chrono::milliseconds(delay)); // memberikan jeda pada penghapusan kata
      }
}
