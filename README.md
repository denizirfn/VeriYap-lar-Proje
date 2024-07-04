Bir kargo şirketi, müşterilerinin kargolarını etkili bir şekilde takip etmelerini ve gönderi 
bilgilerine hızlıca erişmelerini sağlamak istemektedir. Uygulamada olacak işlemler:
1. Kargo Bilgilerini Depolama: 
Her bir kargonun takip numarası, gönderici, alıcı ve teslimat durumu gibi bilgileri içeren bir 
veri yapısı oluşturun.

2. Takip Numarası Oluşturma ve Hashleme:
Her yeni kargo için benzersiz bir takip numarası bulunmaktadır. Gelen takip numarasına göre 
hash tablosuna ekleme işlemi aşağıdaki gibi olacaktır.
HashIndex1: TakipNo % TABLO_BOYUTU
 HashIndex2: 7 - (TakipNo % 7)
 Hashing İşlemi:
2.1. Takip numarasını(takipNo) tablonun boyutuna göre mod alarak indeks bulun
(HashIndex1). Eğer hash tablosunda bulunan indeks boşsa, ekleme işlemini 
gerçekleştirin.
2.2. Çakışma varsa aşağıdaki formülü çakışma olmayana kadar kontrol edin. İlk çakışma 
olmayan indekse ekleme işlemini gerçekleştirin. Tüm denemeler sonucunda boş yer 
bulunamıyorsa kullanıcıyı tablo dolu şeklinde bilgilendirin.
Double Hashing : (HashIndex1+ deneme * HashIndex2) % TABLO_BOYUTU

3. Kargoları toplu bir şekilde sisteme girme:
Text dosyasına toplu bir şekilde kargo bilgilerini kaydedin. Uygulamada kargoları text
dosyasından okuyarak Hash tablosuna kaydetme yapınız. 

4. Kullanıcı tarafından kargo girişi:
Kargo bilgileri text dosyasından girildikten sonra kullanıcı tarafından da girilebilir olması 
gerekmektedir.
Eğer tablo doluysa tablo dolu uyarısı vermesi gerekmektedir. Örneğin 54 takip nolu kargo 
eklenmek istendiğinde eklenebileceği indekslerin hepsi dolu olduğundan ekrana dolu uyarı 
vermektedir.

5. Kargo Takip Durum:
Müşterilerin kargo takip numaralarını kullanarak gönderilerini takip etmelerine olanak tanıyan 
bir sorgu sistemi ekleyin. Bu sistemde girilen takip numarasını Hash tablosunda kaç adımda 
bulduğu bilgisi ve kargo bilgileri yer alacaktır.

6. Kargo Teslim Etme işlemi (Hash tablosundan silme): 
Kullanıcıya kargo teslim seçeneği sunarak, girilen kargo takip numarasına ait kargonun Hash 
tablosundan silme işlemini gerçekleştirin.

7. Kargoları Listele (Hash tablosundaki bilgileri listeleme):
Hash tablosundaki tüm kargoların kaç adımda bulunduğu ve kargolara ait bilgileri listeleme
