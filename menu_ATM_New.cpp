#include <iostream>
#include <iomanip> //
#include <cstdlib> // untuk menggunakan system("cls")
#include <ctime> // untuk mengatur seed pada fungsi rand()
#include <thread> // untuk menggunakan fungsi multithreading cnth sleep_for
#include <chrono> // untuk menangani waktu dengan tepat sangat penting karena untuk penggunaan sleep_for yang membutuhkan parameter bertipe durasi
using namespace std;

// >> Struct Init
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
bool mainMenuLoop = false;
bool loginStat = false;
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
// Main Feature
void login();
void cekSaldo();
void setorSaldo();
void tarikSaldo();
void transferDeposito();
void riwayatTransaksi(int transaksi[], string deskripsi[], int idTransaksi[], int indexTransaksi);
void Pause();
// Function untuk Pause
void SlowType(const string &kata, int delay);
void DeleteText(int count, int delay);
// Execution Funct
int main()
{
      int saldo = 0;
      int transaksi[100];
      int idTransaksi[100];
      int indexTransaksi = 0;
      string deskripsi[100];
      int opt;
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
      login();
      do
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
                  transferDeposito();
                  break;
            case 4:
                  Pause();
                  tarikSaldo();
                  break;
            // case 5:
            //       Pause();
            //       riwayatTransaksi(transaksi, deskripsi, idTransaksi, indexTransaksi);
            //       break;
            case 6:
                  cout << "\nTerimakasih telah menggunakan ATM ini\n";
                  Pause();
                  indexNasabah = -1;
                  mainMenuLoop = true;
                  break;
            default:
                  cout << "Pilihan yang Anda masukkan salah\n";
            }
      } while (!mainMenuLoop);

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
                  getline(cin, var);
            }
            if (cin.fail())
            {
                  cin.clear();          // Menghapus Semua Fail Flag
                  cin.ignore(30, '\n'); // Mengabaikan Input
                  cout << "\n[Error Tag] -" << "Walah Mas Nginput apa njenengan\n";
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
                  cout << "\n[Error Tag] -" << "Walah Mas Nginput apa njenengan\n";
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
                  cout << "\n[Error Tag] -" << "Walah Mas Nginput apa njenengan\n";
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
                  cout << "\n[Error Tag] -" << "Walah Mas Nginput apa njenengan\n";
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
          {12345678, "admin", "Rio Meidi A", 2000000, 3,
           {// Inisialisasi langsung historiNasabah
            {1, 500000, 87654321, "makan"},
            {2, 300000, 87654322, "Woy"},
            {3, 200000, 87654323, "Hiyahiya"}}};
      dataNasabah[jumlahNasabah++] =
          {12215678, "admin", "Tony Antonio", 7000000, 3,
           {// biar spasi
            {1, 500000, 87654321, "makan"},
            {2, 300000, 87654322, "Woy"},
            {3, 200000, 87654323, "Hiyahiya"}}};
      // Kalau Kurang silahkan di tambah sendiri
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
                        loginStat = true;
                        indexNasabah = i; // Memasukkan noRekLogin kedalam list on admin
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
                  cout << "\nLogin gagal. Kesempatan Anda tersisa " << (--max_chance) << endl;
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
                  cout << "\nInput tidak valid\n";
            }
      } while (pilihan != 1 && pilihan != 2);
}
// Function Setor Saldo
void setorSaldo()
{
      int jumlah;
      short pilihan;
      srand(time(0)); //mengatur seed pada rand() untuk menggunakan waktu saat ini memastikan tidak membawa seed bawaan ctime
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
            cout << setw(15) << "keluar <2" << endl;
            inputHandling("\n>> ", pilihan);

            if (pilihan == 1)
            {
                  dataNasabah[indexNasabah].saldo += jumlah;
                  dataNasabah[indexNasabah].jumlahTrans++;
                  dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].nominal = jumlah;
                  dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].idTrans = rand() % 90000000 + 10000000; // Nomor Id acak mengambil dari rentang 0 hingga 89999999 kemudian ditambahkan 10000000
                  dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].noRektuj = dataNasabah[indexNasabah].noRek;
                  dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].deskripsi = "Setor Saldo";
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
                  cout << "\nInput tidak valid\n";
            }
      } while (pilihan != 1 && pilihan != 2);
}
// Function Tarik Saldo
void tarikSaldo()
{
      int jumlah;
      short pilihan;
      srand(time(0)); //mengatur seed pada rand() untuk menggunakan waktu saat ini memastikan tidak membawa seed bawaan ctime
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
            cout << setw(15) << "keluar <2" << endl;
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
                        dataNasabah[indexNasabah].jumlahTrans++;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].nominal = jumlah;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].idTrans = rand() % 90000000 + 10000000; // Nomor Id acak mengambil dari rentang 0 hingga 89999999 kemudian ditambahkan 10000000
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].noRektuj = dataNasabah[indexNasabah].noRek;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].deskripsi = "Tarik Saldo";
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
                  cout << "\nInput tidak valid\n";
            }
      } while (pilihan != 1 && pilihan != 2);
}
// Function Transfer Rekening
void transferDeposito()
{
      int rekening_tujuan, jumlah, indexFound;
      short pilihan;
      bool find = false;
      srand(time(0)); //mengatur seed pada rand() untuk menggunakan waktu saat ini memastikan tidak membawa seed bawaan ctime
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
                        cout << setw(10) << "A.N." << setw(5) << " : " << dataNasabah[indexFound].nama << endl;
                        cout << setw(10) << "No.Rek" << setw(5) << " : " << dataNasabah[indexFound].noRek << endl;
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
            cout << setw(15) << "keluar <2" << endl;
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
                        dataNasabah[indexNasabah].jumlahTrans++;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].nominal = 0 - jumlah;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].idTrans = rand() % 90000000 + 10000000; // Nomor Id acak mengambil dari rentang 0 hingga 89999999 kemudian ditambahkan 10000000
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].noRektuj = dataNasabah[indexNasabah].noRek;
                        dataNasabah[indexNasabah].historiNasabah[dataNasabah[indexNasabah].jumlahTrans].deskripsi = "Tarik Saldo";
                        // Update Data Nasabah Penerima
                        dataNasabah[indexFound].jumlahTrans++;
                        dataNasabah[indexFound].saldo += jumlah;
                        dataNasabah[indexFound].historiNasabah[dataNasabah[indexFound].jumlahTrans].nominal = jumlah;
                        dataNasabah[indexFound].historiNasabah[dataNasabah[indexFound].jumlahTrans].idTrans = rand() % 90000000 + 10000000; // Nomor Id acak mengambil dari rentang 0 hingga 89999999 kemudian ditambahkan 10000000
                        dataNasabah[indexFound].historiNasabah[dataNasabah[indexFound].jumlahTrans].noRektuj = dataNasabah[indexFound].noRek;
                        dataNasabah[indexFound].historiNasabah[dataNasabah[indexFound].jumlahTrans].deskripsi = "Menerima Saldo";
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
                  cout << "\nTransfer dibatalkan\n";
                  Pause();
                  return;
            }
            else
            {
                  cout << "\nInput tidak valid\n";
            }
      } while (pilihan != 1 && pilihan != 2);
}
// Function Riwayat Transaksi
void riwayatTransaksi(int transaksi[], string deskripsi[], int idTransaksi[], int indexTransaksi)
{
      const int transHal = 5;
      int halaman = 0;
      int totalHal = (indexTransaksi + transHal - 1) / transHal;
      int pilihan;
      bool exit = false;
      if (indexTransaksi == 0)
      {
            cout << "Riwayat transaksi anda belum ada\n";
            Pause();
            return;
      }
      do
      {
            system("cls");
            cout << "<= Riwayat Transaksi =>\n";
            cout << "Page (" << halaman + 1 << "/" << totalHal << ")\n";
            cout << "|No | Id Transaksi | Nominal         | Tujuan           |\n";
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            for (int i = halaman * transHal; i < min(indexTransaksi, (halaman + 1) * transHal); i++)
            {
                  string nominalTrans = (transaksi[i] > 0 ? "+" : "-") + to_string(abs(transaksi[i]));
                  string tujuan = deskripsi[i];
                  cout << "|" << setw(3) << i + 1 << " | " << setw(10) << idTransaksi[i] << " | Rp" << setw(15) << nominalTrans + ",00" << " | " << setw(15) << tujuan << " |\n";
            }
            cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
            cout << "\n                                       Next Page     1<\n";
            cout << "                                       Previous Page 2<\n";
            cout << "                                       Keluar        3<\n";
            inputHandling("\n>> ", pilihan);

            if (pilihan == 1)
            {
                  halaman = (halaman + 1) % totalHal;
            }
            else if (pilihan == 2)
            {
                  halaman = (halaman - 1) % totalHal;
            }
            else if (pilihan == 3)
            {
                  exit = true;
            }
            else
            {
                  cout << "pilihan yang Anda masukkan salah\n";
                  Pause();
            }
      } while (!exit);
      Pause();
}
// Function pause dilengkapi cls
void Pause()
{
      cout << "\nSystem is ";
      SlowType("processing", 100); //menggunakan fungsi slowtype() mengetik dengan delay 100 milidetik setiap karakter
      this_thread::sleep_for(chrono::seconds(1)); // memberikan jeda selama 1 detik menggunakan sleep_for dari library thread
      DeleteText(10, 100); // menghapus 10 karakter dengan delay 100 milidetik
      SlowType("completed", 100); //mengetik dengan delay 100 milidetik setiap karakter
      cout << endl;
      this_thread::sleep_for(chrono::seconds(1)); // memberikan jeda selama 1 detik menggunakan sleep_for dari library thread
      system("cls");
}
// Animasi untuk pause
void SlowType(const string &kata, int delay) //menampilkan kata satu per satu dengan jeda waktu
{
      for (char c : kata) // membaca setiap karakter yang diinginkan
      {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(delay));
      }
}
void DeleteText(int count, int delay) //menghapus karakter satu per satu dengan jeda waktu
{
      for (int i = 0; i < count; ++i)
      {
            cout << "\b \b" << flush;
            this_thread::sleep_for(chrono::milliseconds(delay)); // memberikan jeda pada penghapusan kata
      }
}
