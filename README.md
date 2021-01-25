# Dosya
HasretÇekirdek için türkçe karakter içeren dosya okuma işlemi için eklenti


private:
		KarakterDizisi Okunan;
		KarakterDizisi DosyaAdi;
		fstream OkunacakDosya;

	public:
		Dosya(KarakterDizisi dosyaAdi);
		KarakterDizisi Oku();
