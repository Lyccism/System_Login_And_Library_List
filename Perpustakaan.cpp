#include <iostream>
#include <string>
#include <vector>

class buku {
    private:
    int id;
    std::string judul;
    std::string pengarang;
    int Tahun;
    bool tersedia;

    public:
    
    buku() {
        id = 0;
        judul = "";
        pengarang = "";
        Tahun = 0;
        tersedia = true;
    }

    buku(int idbuku, std::string judulbuku, std::string pengarangbuku, int Tahunbuku) {
        this->id = idbuku;
        this->judul = judulbuku;
        this->pengarang = pengarangbuku;
        this->Tahun = Tahunbuku;
        this->tersedia = true;
    }

    int getId() {
        return id;
    }

    std::string getJudul() {
        return judul;
    }

    std::string getPengarang() {
        return pengarang;
    }

    int getTahun() {
        return Tahun;
    }

    bool isTersedia() {
        return tersedia;
    }

    void setTersedia(bool status) {
        tersedia = status;
    }

    void tampilkanInfo() {
        std::cout << "ID Buku: " << id << '\n';
        std::cout << "Judul Buku: " << judul << '\n';
        std::cout << "Pengarang Buku: " << pengarang << '\n';
        std::cout << "Tahun Terbit: " << Tahun << '\n';
        std::cout << "Status: " << (tersedia ? "Tersedia" : "Dipinjam") << '\n';
    }
};

class user {
    private:
    std::string username;
    std::string password;
    std::string role;

    public:
    user() {
        username = "";
        password = "";
        role = "";
    }

    user(std::string user, std::string pass, std::string userRole) {
        this->username = user;
        this->password = pass;
        this->role = userRole;
    }

    std::string getUsername() {
        return username;
    }

    std::string getPassword() {
        return password;
    }

    std::string getRole() {
        return role;
    }

    bool cekLogin(std::string user, std::string pass) {
        return (username == user && password == pass);
    }

    void tampilkanInfo() {
        std::cout << "Username: " << username << '\n';
        std::cout << "Role: " << role << '\n';
    }
};

// Fungsi untuk cek apakah username sudah ada
bool usernameSudahAda(std::vector<user>& users, std::string username) {
    for (size_t i = 0; i < users.size(); i++) {  // <- PERBAIKAN DI SINI (baris 107)
        if (users[i].getUsername() == username) {
            return true;
        }
    }
    return false;
}

int main() {
   std::cout << "Selamat datang di sistem perpustakaan sederhana" << '\n';

   buku buku1(1, "Pemrograman C++", "Budi santoso", 2002);
   buku buku2(2, "Data Struktur", "Andi Wijaya", 2005);
   buku buku3(3, "Algoritma dan Pemrograman", "Siti Aminah", 2010);
   buku buku4(4, "Basis Data", "Rina Kurnia", 2015);
   buku buku5(5, "Jaringan Komputer", "Dewi Lestari", 2018);

   // Inisialisasi user awal
   std::vector<user> users;
   users.push_back(user("admin", "admin123", "administrator"));

   int pinjamId;
   do {
    std::cout << "\nDaftar Buku yang Tersedia:" << '\n';
    std::cout << "==============================" << '\n';
    std::cout << "1. " << buku1.getJudul() << " oleh " << buku1.getPengarang() << " (Tahun: " << buku1.getTahun() << ")\n";
    std::cout << "2. " << buku2.getJudul() << " oleh " << buku2.getPengarang() << " (Tahun: " << buku2.getTahun() << ")\n";
    std::cout << "3. " << buku3.getJudul() << " oleh " << buku3.getPengarang() << " (Tahun: " << buku3.getTahun() << ")\n";
    std::cout << "4. " << buku4.getJudul() << " oleh " << buku4.getPengarang() << " (Tahun: " << buku4.getTahun() << ")\n";
    std::cout << "5. " << buku5.getJudul() << " oleh " << buku5.getPengarang() << " (Tahun: " << buku5.getTahun() << ")\n";
    std::cout << "==============================" << '\n';
    std::cout << "Masukkan ID Buku yang ingin dipinjam: ";
    std::cin >> pinjamId;

    if (std::cin.fail()) {
        std::cout << "Input tidak valid. Harap masukkan angka untuk ID Buku." << '\n';
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        continue;
    }

    if (pinjamId < 1 || pinjamId > 5) {
        std::cout << "ID Buku tidak valid. Harap masukkan ID antara 1 hingga 5." << '\n';
        continue;
    }
    
    bool bukuTersedia = false;
    if (pinjamId == 1) {
        bukuTersedia = buku1.isTersedia();
        if (!bukuTersedia) {
            std::cout << "Maaf, buku ini sedang dipinjam." << '\n';
        }
    } else if (pinjamId == 2) {
        bukuTersedia = buku2.isTersedia();
        if (!bukuTersedia) {
            std::cout << "Maaf, buku ini sedang dipinjam." << '\n';
        }
    } else if (pinjamId == 3) {
        bukuTersedia = buku3.isTersedia();
        if (!bukuTersedia) {
            std::cout << "Maaf, buku ini sedang dipinjam." << '\n';
        }
    } else if (pinjamId == 4) {
        bukuTersedia = buku4.isTersedia();
        if (!bukuTersedia) {
            std::cout << "Maaf, buku ini sedang dipinjam." << '\n';
        }
    } else if (pinjamId == 5) {
        bukuTersedia = buku5.isTersedia();
        if (!bukuTersedia) {
            std::cout << "Maaf, buku ini sedang dipinjam." << '\n';
        }
    }
    
    if (pinjamId >= 1 && pinjamId <= 5 && bukuTersedia) {
        break;
    }
    
   } while (true);

    std::string inputUser, inputPass;
    
    std::cout << "\n=== LOGIN / REGISTRASI ===" << '\n';
    std::cout << "1. Login" << '\n';
    std::cout << "2. Daftar (Registrasi)" << '\n';
    std::cout << "Pilih menu (1-2): ";
    
    int menuLogin;
    std::cin >> menuLogin;
    
    if (menuLogin == 2) {
        // REGISTRASI USER BARU
        std::cout << "\n=== REGISTRASI USER BARU ===" << '\n';
        std::cout << "Masukkan Username baru: ";
        std::cin >> inputUser;
        
        // Cek apakah username sudah ada
        if (usernameSudahAda(users, inputUser)) {
            std::cout << "Username '" << inputUser << "' sudah digunakan. Silakan pilih username lain." << '\n';
            return 0;
        }
        
        std::cout << "Masukkan Password baru: ";
        std::cin >> inputPass;
        
        // Tambah user baru ke vector
        users.push_back(user(inputUser, inputPass, "anggota"));
        std::cout << "Registrasi berhasil! Akun '" << inputUser << "' telah dibuat." << '\n';
        std::cout << "Role: anggota" << '\n';
    } else {
        // LOGIN BIASA
        std::cout << "\n=== LOGIN ===" << '\n';
        std::cout << "Masukkan Username: ";
        std::cin >> inputUser;
        std::cout << "Masukkan Password: ";
        std::cin >> inputPass;
    }
    
    // CEK LOGIN DARI SEMUA USER DI VECTOR
    bool loginBerhasil = false;
    user* userLogin = nullptr;
    
    for (size_t i = 0; i < users.size(); i++) {  // <- PERBAIKAN DI SINI (baris 229)
        if (users[i].cekLogin(inputUser, inputPass)) {
            loginBerhasil = true;
            userLogin = &users[i];
            break;
        }
    }
    
    if (loginBerhasil && userLogin != nullptr) {
        std::cout << "\nLogin berhasil! Selamat datang, " << userLogin->getUsername() << '\n';
        std::cout << "Role: " << userLogin->getRole() << '\n';
        
        // Proses peminjaman buku
        if (pinjamId == 1) {
            buku1.setTersedia(false);
            std::cout << "Anda berhasil meminjam buku: " << buku1.getJudul() << '\n';
        } else if (pinjamId == 2) {
            buku2.setTersedia(false);
            std::cout << "Anda berhasil meminjam buku: " << buku2.getJudul() << '\n';
        } else if (pinjamId == 3) {
            buku3.setTersedia(false);
            std::cout << "Anda berhasil meminjam buku: " << buku3.getJudul() << '\n';
        } else if (pinjamId == 4) {
            buku4.setTersedia(false);
            std::cout << "Anda berhasil meminjam buku: " << buku4.getJudul() << '\n';
        } else if (pinjamId == 5) {
            buku5.setTersedia(false);
            std::cout << "Anda berhasil meminjam buku: " << buku5.getJudul() << '\n';
        }
    } else {
        std::cout << "Login gagal! Username atau password salah." << '\n';
    }
    
    // Tampilkan semua user yang terdaftar (untuk debugging)
    std::cout << "\n=== Daftar User Terdaftar ===" << '\n';
    for (size_t i = 0; i < users.size(); i++) {  // <- PERBAIKAN DI SINI (baris 264)
        std::cout << i+1 << ". " << users[i].getUsername() << " (" << users[i].getRole() << ")" << '\n';
    }
    
    return 0;
}