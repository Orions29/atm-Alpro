#include <iostream>
#include <iomanip>
#include <cstdlib> // untuk menggunakan system("cls")
#include <ctime> // untuk mengatur seed pada fungsi rand()
#include <thread> // untuk menggunakan fungsi multithreading
#include <chrono> // untuk menangani waktu dengan tepat
using namespace std;
// >> Global Var Init
bool mainMenuLoop = false;
// >> Struct Init
// -(OTW)
// >> Decklare Funtion
// Error handling Func (Overload)
void inputHandling(string question, string &var); // Untuk String
void inputHandling(string question, int &var);    // Untuk Integer
void inputHandling(string question, float &var);  // Untuk Float
void inputHandling(string question, short &var);  // Untuk short
// CRUD Data Nasabah
// -(OTW)
// Main Feature
void login();
void cekSaldo(int saldo);
void setorSaldo(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi);
void tarikSaldo(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi);
void transferRekening(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi);
void riwayatTransaksi(int transaksi[], string deskripsi[], int idTransaksi[], int indexTransaksi);
void Pause();

// Function untuk Pause
void SlowType(const string &kata, int delay);
void DeleteText(int count, int delay);

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
                  cekSaldo(saldo);
                  break;
            case 2:
                  Pause();
                  setorSaldo(saldo, transaksi, deskripsi, idTransaksi, indexTransaksi);
                  break;
            case 3:
                  Pause();
                  transferRekening(saldo, transaksi, deskripsi, idTransaksi, indexTransaksi);
                  break;
            case 4:
                  Pause();
                  tarikSaldo(saldo, transaksi, deskripsi, idTransaksi, indexTransaksi);
                  break;
            case 5:
                  Pause();
                  riwayatTransaksi(transaksi, deskripsi, idTransaksi, indexTransaksi);
                  break;
            case 6:
                  cout << "\nTerimakasih telah menggunakan ATM ini\n";
                  Pause();
                  mainMenuLoop = true;
                  break;
            default:
                  cout << "Pilihan yang Anda masukkan salah\n";
            }
      } while (!mainMenuLoop);
      return 0;
}
// Error Handling Funct
void inputHandling(string question, string &var)
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
// Main Feature Funct Desc
void login()
{
      int nomor_rek, password_rek;
      int correct_nmr = 12345678;
      int correct_pass = 123456;
      int max_chance = 3;
      int chance = 0;

      do
      {
            inputHandling("\nMasukkan Nomor Rekening (8 Digit)\n>> ", nomor_rek);
            inputHandling("\nMasukkan Password Rekening (6 Digit)\n>> ", password_rek);
            ;
            if (nomor_rek == correct_nmr && password_rek == correct_pass)
            {
                  cout << "Login berhasil.\n";
                  Pause();
                  return;
            }
            else
            {
                  chance++;
                  cout << "Login gagal. Kesempatan Anda tersisa " << (max_chance - chance) << endl;
            }
      } while (chance < max_chance);

      cout << "Kesempatan Anda habis. Program akan keluar.\n";
      exit(0);
}
void cekSaldo(int saldo)
{
      int pilihan;

      do
      {
            cout << "\nSaldo Anda: \n";
            cout << "\tRp" << fixed << saldo << ",00" << endl;
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
void setorSaldo(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi)
{
      string namaPem = "Admin Test";
      int noRek = 12345678;
      int jumlah;
      int pilihan;
      srand(time(0)); //mengatur seed pada rand() untuk menggunakan waktu saat ini memastikan tidak membawa seed bawaan ctime
      do
      {
            cout << "\n <= Setor Saldo =>\n\n";

            cout << "Data Rekening :" << endl;
            cout << setw(10) << "A.N." << setw(5) << ": " << namaPem << endl;
            cout << setw(10) << "No.Rek" << setw(5) << " : " << noRek << endl;

            cout << "Deposit" << setw(5) << ": Rp";
            inputHandling("", jumlah);
            cout << endl;

            cout << setw(15) << "Konfirmasi <1" << endl;
            cout << setw(15) << "keluar <2" << endl;
            inputHandling("\n>> ", pilihan);

            if (pilihan == 1)
            {
                  saldo += jumlah;
                  transaksi[indexTransaksi] = jumlah;
                  deskripsi[indexTransaksi] = "Setor Saldo";
                  idTransaksi[indexTransaksi] = rand() % 90000000 + 10000000; // Nomor Id acak mengambil dari rentang 0 hingga 89999999 kemudian ditambahkan 10000000
                  indexTransaksi++;
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
void tarikSaldo(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi)
{
      int jumlah;
      string namaPem = "Admin Test";
      int noRek = 12345678;
      int pilihan;
      srand(time(0));
      do
      {
            cout << "\n <= Tarik Tunai =>\n\n";
            cout << "Data Rekening :" << endl;
            cout << setw(10) << "A.N." << setw(5) << ": " << namaPem << endl;
            cout << setw(10) << "No.Rek" << setw(5) << " : " << noRek << endl;

            cout << "Nominal" << setw(5) << ": Rp";
            inputHandling("", jumlah);
            cout << endl;
            cout << setw(15) << "Konfirmasi <1" << endl;
            cout << setw(15) << "keluar <2" << endl;
            inputHandling("\n>> ", pilihan);

            if (pilihan == 1)
            {
                  if (saldo < jumlah)
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
                        saldo -= jumlah;
                        transaksi[indexTransaksi] = -jumlah;
                        deskripsi[indexTransaksi] = "Tarik Saldo";
                        idTransaksi[indexTransaksi] = rand() % 90000000 + 10000000;
                        indexTransaksi++;
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
void transferRekening(int &saldo, int transaksi[], string deskripsi[], int idTransaksi[], int &indexTransaksi)
{
      int rekening_tujuan;
      int jumlah;
      string namaPem = "Admin Test";
      int noRek = 12345678;
      int pilihan;
      srand(time(0));
      do
      {
            cout << "\n <= Tarik Tunai =>\n\n";
            cout << "Data Rekening :" << endl;
            cout << setw(10) << "A.N." << setw(5) << ": " << namaPem << endl;
            cout << setw(10) << "No.Rek" << setw(5) << " : " << noRek << endl;
            do
            {
                  inputHandling("\nMasukkan Nomor Rekening tujuan (8 digit) : ", rekening_tujuan);
                  if (rekening_tujuan < 10000000 || rekening_tujuan > 99999999)
                  {
                        cout << "Nomor Rekening yang Anda Masukkan tidak valid\n";
                  }
            } while (rekening_tujuan < 10000000 || rekening_tujuan > 99999999);
            cout << "Nominal" << setw(5) << ": Rp";
            inputHandling("", jumlah);
            cout << endl;
            cout << setw(15) << "Konfirmasi <1" << endl;
            cout << setw(15) << "keluar <2" << endl;
            inputHandling("\n>> ", pilihan);
            if (pilihan == 1)
            {
                  if (saldo < jumlah)
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
                        saldo -= jumlah;
                        transaksi[indexTransaksi] = -jumlah;
                        deskripsi[indexTransaksi] = "Transfer";
                        idTransaksi[indexTransaksi] = rand() % 90000000 + 10000000;
                        indexTransaksi++;
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
      SlowType("processing", 100); //mengetik dengan delay 100 milidetik setiap karakter
      this_thread::sleep_for(chrono::seconds(1)); // memberikan jeda selama 1 detik menggunakan sleep_for dari library thread 
      DeleteText(10, 100); // menghapus 10 karakter dengan delay 100 milidetik
      SlowType("completed", 100);
      cout << endl;
      this_thread::sleep_for(chrono::seconds(1));
      system("cls");
}
// Animasi untuk pause
void SlowType(const string &kata, int delay) //menampilkan kata satu per satu dengan jeda waktu
{
      for (char c : kata) // membaca setiap karakter yang diinginkan
      {
            cout << c << flush;
            this_thread::sleep_for(chrono::milliseconds(delay)); // memberikan jeda pada pengetikan kata
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
