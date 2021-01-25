#pragma once
#include <fstream>
#include "KarakterDizisi.h"
#include <string>
#include <iostream>


class Dosya {

	private:
		KarakterDizisi Okunan;
		KarakterDizisi DosyaAdi;
		fstream OkunacakDosya;

	public:
		Dosya(KarakterDizisi dosyaAdi);
		KarakterDizisi Oku();

};