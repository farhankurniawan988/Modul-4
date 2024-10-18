#include <iostream>

struct NODE {
    int data; 
    NODE* next;
};

// Fungsi alokasi (buat elemen)
NODE* alok(int isi_data) {
    NODE* elemen_terakhir_baru = new(NODE);
	
	if (elemen_terakhir_baru != nullptr) {
		elemen_terakhir_baru->data = isi_data; 
    	elemen_terakhir_baru->next = nullptr;
	} 
	
    return elemen_terakhir_baru;
}

// Fungsi dealokasi (hapus) elemen
void dealok(NODE* NODE) {
    delete NODE;
}

// Cek apakah isi daftar kosong
bool isi_ternyata_kosong(NODE* head) {
    return head == nullptr;
}

// Sisip di awal daftar
void sisip_di_awal(NODE* &head, int isi_nilai) {
    NODE* elemen_terawal_baru = alok(isi_nilai);

    if (elemen_terawal_baru != nullptr) {
        elemen_terawal_baru->next = head;
        head = elemen_terawal_baru;
    }
}

// Sisip di akhir daftar
void sisip_di_akhir(NODE* &head, int value) {
    NODE* elemen_terakhir_baru = alok(value);

    if (elemen_terakhir_baru != nullptr) {
        if (isi_ternyata_kosong(head)) {
            head = elemen_terakhir_baru;      
        } else {
            NODE* elemen_terakhir = head;

            while (elemen_terakhir->next != nullptr) {
                elemen_terakhir = elemen_terakhir->next;
            }

            elemen_terakhir->next = elemen_terakhir_baru;
        }
    }
}

// Menampilkan semua elemen
void cetak_daftar(NODE* head) {
    if (isi_ternyata_kosong(head)) {
        std::cout << "Daftar kosong" << std::endl;
    } else {
        NODE* elemen = head;

        while (elemen != nullptr) {
            std::cout << elemen->data << " => ";
            elemen = elemen->next; 
		}
		std::cout << "NULL";
        std::cout << std::endl;
    }
}

// Menghitung jumlah semua elemen dalam daftar
int jumlah_elemen(NODE* head) {
    int jumlah = 0;
    NODE* elemen = head;

    while (elemen != nullptr) {
        jumlah = jumlah + 1;
        elemen = elemen->next;
    }

    return jumlah; 
}

// Menghapus semua elemen dalam daftar
void hapus_semua_elemen(NODE* &head) {
    while (head != nullptr) {
        NODE* elemen = head;
        head = head->next;
        dealok(elemen);
    }
}

int main() {
    // Daftar kosong
    NODE* head = nullptr;

    // Menambahkan elemen
    sisip_di_awal(head, 10);
    sisip_di_akhir(head, 20);
    sisip_di_akhir(head, 30);

    // Menampilkan isi daftar
    std::cout << "Isi daftar: ";
    cetak_daftar(head);

    // Menampilkan jumlah elemen
    std::cout << "Jumlah elemen: " << jumlah_elemen(head) << std::endl;

    // Menghapus semua elemen
    hapus_semua_elemen(head);

    // Menampilkan isi daftar setelah penghapusan
    std::cout << "Isi daftar setelah penghapusan: ";
    cetak_daftar(head);

    return 0;
}
