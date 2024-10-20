#include <iostream>
#include <stdexcept>

struct SIMPUL {
    int nilai;
    SIMPUL* simpul_selanjutnya = nullptr;
};

SIMPUL* elemen_baru(int isi_data) {
    SIMPUL* baru = new SIMPUL;

    baru->nilai = isi_data;
    baru->simpul_selanjutnya;

    return baru;
}

// Pemanis untuk membuat daftar/elemen kosong
std::nullptr_t elemen_baru_kosong() {
    return nullptr;
}

// Fungsi ini KHUSUS menambah elemen baru, bukan elemen yang sudah ada
void tambah_baru_di_awal(SIMPUL* &kepala, int isi_data_baru) {
    SIMPUL* awal_baru = elemen_baru(isi_data_baru);
    if (awal_baru == nullptr) {
        throw std::runtime_error("Gagal mengalokasikan elemen");
    }

    awal_baru->simpul_selanjutnya = kepala;
    kepala = awal_baru;
}

// Fungsi ini KHUSUS menambah elemen baru, bukan elemen yang sudah ada
void tambah_baru_di_akhir(SIMPUL* &kepala, int isi_data_baru) {
    SIMPUL* akhir_baru = elemen_baru(isi_data_baru);
    if (akhir_baru == nullptr) {
        throw std::runtime_error("Gagal mengalokasikan elemen");
    }

    if (kepala == nullptr) {
        kepala = akhir_baru;
    } else {
        SIMPUL* ekor = kepala;
        while (ekor->simpul_selanjutnya != nullptr) {
            ekor = ekor->simpul_selanjutnya;
        }

        ekor->simpul_selanjutnya = akhir_baru;
    }
}

void hapus_pada(SIMPUL* &kepala, int nilai) {
    SIMPUL* target = kepala;
    
    if (kepala == nullptr) {
        std::cout << "Daftar kosong." << '\n';
        return;
    } else {
        while (target->simpul_selanjutnya != nullptr) {
            if (target->simpul_selanjutnya->nilai == nilai) {
                SIMPUL* target_ditemukan = target->simpul_selanjutnya;
                target->simpul_selanjutnya = target_ditemukan->simpul_selanjutnya;
                delete target_ditemukan;
                return;
            }
            target = target->simpul_selanjutnya;
        }
        std::cout << nilai << " tidak ditemukan." << "\n";
    }
}

void cari_elemen(SIMPUL* &kepala, int nilai) {
    SIMPUL* target = kepala;
    
    if (kepala == nullptr) {
        std::cout << "Daftar kosong." << '\n';
        return;
    } else {
        while (target->simpul_selanjutnya != nullptr) {
            if (target->simpul_selanjutnya->nilai == nilai) {
                std::cout << "Simpul dengan nilai " << nilai << " ditemukan." << '\n';
                return;
            }
            target = target->simpul_selanjutnya;
        }
        std::cout << nilai << " tidak ditemukan." << "\n";
    }
}

int jumlah_elemen_daftar(SIMPUL* daftar_eksis) {
    SIMPUL* posisi_traversal = daftar_eksis;
    int jumlah = 0;
    
    if (daftar_eksis == nullptr) {
        return jumlah;
    } else {
        while (posisi_traversal != nullptr) {
            jumlah = jumlah + 1;
            posisi_traversal = posisi_traversal->simpul_selanjutnya;
        }
    }

    return jumlah;
}

void cetak_daftar(SIMPUL* daftar_eksis) {
    SIMPUL* posisi_traversal = daftar_eksis;
    while (posisi_traversal != nullptr) {
        std::cout << posisi_traversal->nilai << " -> ";
        posisi_traversal = posisi_traversal->simpul_selanjutnya;
    }

    std::cout << "nullptr";
    std::cout << '\n';
}

int main() {
    SIMPUL* jawaban_1 = elemen_baru_kosong();
    tambah_baru_di_awal(jawaban_1, 10);
    tambah_baru_di_akhir(jawaban_1, 20);
    tambah_baru_di_awal(jawaban_1, 5);
    cetak_daftar(jawaban_1);

    std::cout << '\n';

    SIMPUL* jawaban_2 = elemen_baru_kosong();
    tambah_baru_di_awal(jawaban_2, 10);
    tambah_baru_di_akhir(jawaban_2, 20);
    tambah_baru_di_awal(jawaban_2, 5);
    hapus_pada(jawaban_2, 10);
    cetak_daftar(jawaban_2);

    std::cout << '\n';

    SIMPUL* jawaban_3 = elemen_baru_kosong();
    tambah_baru_di_awal(jawaban_3, 10);
    tambah_baru_di_akhir(jawaban_3, 20);
    tambah_baru_di_awal(jawaban_3, 5);
    cari_elemen(jawaban_3, 20);
    std::cout << "Panjang daftar berantai: " << jumlah_elemen_daftar(jawaban_2)
              << '\n';
 
    return 0;
}
