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
	 
		this->OkunacakDosya.unsetf(std::ios_base::skipws);//alt satır gör
	
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
				//ı,İ,ö,Ö,ü,Ü,ç,Ç,ş,Ş,ğ,Ğ
				
				
				if (onceki == 196 && suanki == 177) {
					this->Okunan = this->Okunan + 'ı';
				}
				if (onceki == 196 && suanki == 176) {
					this->Okunan = this->Okunan + 'İ';
				}
				if (onceki == 195 && suanki == 182) {
					this->Okunan = this->Okunan + 'ö';
				}
				if (onceki == 195 && suanki == 150) {
					this->Okunan = this->Okunan + 'Ö';
				}
				if (onceki == 195 && suanki == 188) {
					this->Okunan = this->Okunan + 'ü';
				}
				if (onceki == 195 && suanki == 156) {
					this->Okunan = this->Okunan + 'Ü';
				}
				if (onceki == 195 && suanki == 167) {
					this->Okunan = this->Okunan + 'ç';
				}
				if (onceki == 195 && suanki == 135) {
					this->Okunan = this->Okunan + 'Ç';
				}
				if (onceki == 197 && suanki == 159) {
					this->Okunan = this->Okunan + 'ş';
				}
				if (onceki == 197 && suanki == 158) {
					this->Okunan = this->Okunan + 'Ş';
				}
				if (onceki == 196 && suanki == 159) {
					this->Okunan = this->Okunan + 'ğ';
				}
				if (onceki == 196 && suanki == 158) {
					this->Okunan = this->Okunan + 'Ğ';
				}
			}
			else {
				this->Okunan = this->Okunan + (unsigned char)anlikOkunan;
			}
			
			
			onceki = suanki;
			//ı =196 177
		}
		 
	}

	this->OkunacakDosya.close();

	return this->Okunan;

}
