#include <iostream>

struct MAHASISWA {
	char nama[10];
	char nim[10];
};

struct NODE {
	struct MAHASISWA data;
	NODE *next;
};

NODE *head;
NODE *tail;

void init() {
	head = nullptr;
	tail = nullptr;
}

bool daftar_ternyata_kosong() {
	return head == nullptr;
}

void sisip_paling_depan(const struct MAHASISWA& data) {
	NODE *baru = new NODE;
	baru->data = data;
	baru->next = nullptr;

	if (daftar_ternyata_kosong()) {
		head = baru;
		tail = baru;
	} else {
		baru->next = head;
		head = baru;
	}
}

void sisip_paling_belakang(const struct MAHASISWA& data) {
	NODE *baru = new NODE;
	baru->data = data;
	baru->next = nullptr;

	if (daftar_ternyata_kosong()) {
		head = baru;
		tail = baru;
	} else {
		tail->next = baru;
		tail = baru;
	}
}

int jumlah_elemen_daftar() {
	NODE *c = head;
	int jumlah = 0;

	while (c->next != nullptr) {
		jumlah = jumlah + 1;
		c = c->next;
	}
	

	return jumlah;
}

void hapus_paling_depan() {
	if (daftar_ternyata_kosong()) {
		std::cout << "Daftarnya kosong" << std::endl;
	} else {
		NODE *elemen_target = head;
		head = head->next;

		delete elemen_target;

		if (head == nullptr) {
			tail = nullptr;
		}
	}
}

void hapus_paling_belakang() {
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
	} else {
		NODE *elemen_terakhir_baru = head;

		while (elemen_terakhir_baru->next != tail) {
			elemen_terakhir_baru = elemen_terakhir_baru->next;
		}
		
		delete tail;
		tail = elemen_terakhir_baru;
		tail->next = nullptr;
	}
}

void tampilkan_daftar() {
	if (daftar_ternyata_kosong()) {
		std::cout << "Daftarnya kosong" << std::endl;
	} else {
		NODE *elms = head;
		
		while (elms != nullptr) {
			std::cout << elms->data.nama << "+" << elms->data.nim << " => ";
			elms = elms->next;
		}
	}

	std::cout << '\n';
}

void hapus_daftar() {
	NODE *c = head;

	while (c != nullptr) {
		NODE *target = c;
		c = c->next;
		delete target;
	}

	head = nullptr;
	tail = nullptr;

	std::cout << '\n';
	std::cout << "Berhasil dihapus" << std::endl;
}

// Main function
int main() {
    head = nullptr;
	tail = nullptr;
    
    struct MAHASISWA m1 = {"Alice", "123456"};
    struct MAHASISWA m2 = {"Bob", "654321"};
    struct MAHASISWA m3 = {"Charlie", "112233"};

	sisip_paling_depan(m1);
	tampilkan_daftar();
	sisip_paling_belakang(m2);
	tampilkan_daftar();
	sisip_paling_depan(m3);
	tampilkan_daftar();
	
	hapus_paling_depan();
	tampilkan_daftar();
	hapus_paling_belakang();
	tampilkan_daftar();

    hapus_daftar();
    
    return 0;
}
