#include "Dosya.h"



Dosya::Dosya(KarakterDizisi dosyaAdi)
{
	
	this->DosyaAdi = dosyaAdi;

}

KarakterDizisi Dosya::Oku() {
	
	this->OkunacakDosya.open(this->DosyaAdi.Al(), ios::in);
	if (!this->OkunacakDosya) {
		cout << "#Hata#" << endl;
	}
	else {
	 
		this->OkunacakDosya.unsetf(std::ios_base::skipws);//alt sat�r g�r
	
		unsigned char anlikOkunan;
		int suanki=0;
		int onceki=0;
		while (1) {
			this->OkunacakDosya >> anlikOkunan;

			if (this->OkunacakDosya.eof()) {
				break;
			}
			
			suanki = (int)anlikOkunan;
			if (suanki == 195 || suanki == 196 ||suanki==197||suanki==158||suanki==159|| suanki==135|| suanki == 177 || suanki == 176  || suanki==167||suanki==182  || suanki == 156 || suanki==150 || suanki==188) {
				//�,�,�,�,�,�,�,�,�,�,�,�
				
				
				if (onceki == 196 && suanki == 177) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 196 && suanki == 176) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 195 && suanki == 182) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 195 && suanki == 150) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 195 && suanki == 188) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 195 && suanki == 156) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 195 && suanki == 167) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 195 && suanki == 135) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 197 && suanki == 159) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 197 && suanki == 158) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 196 && suanki == 159) {
					this->Okunan = this->Okunan + '�';
				}
				if (onceki == 196 && suanki == 158) {
					this->Okunan = this->Okunan + '�';
				}
			}
			else {
				this->Okunan = this->Okunan + (unsigned char)anlikOkunan;
			}
			
			
			onceki = suanki;
			//� =196 177
		}
		 
	}

	this->OkunacakDosya.close();

	return this->Okunan;

}
