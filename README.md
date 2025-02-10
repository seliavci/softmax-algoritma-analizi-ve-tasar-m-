Kırklareli Toplu Taşıma Hattı Planlaması


Bu proje, Kırklareli'nin üç mahallesi için en uygun toplu taşıma hattını belirlemek amacıyla Softmax algoritmasını kullanmaktadır. 
Değerlendirme, nüfus yoğunluğu, ulaşım altyapısı, maliyet analizi, çevresel etki ve sosyal fayda gibi kriterler üzerinden yapılmıştır.


Proje Açıklaması
Toplu taşıma hattı planlamasında aşağıdaki 5 kriter değerlendirilmiştir:  
- Nüfus Yoğunluğu (Daha yoğun nüfus, daha fazla ulaşım ihtiyacı demektir.)  
- Mevcut Ulaşım Altyapısı (Mahalledeki mevcut ulaşım imkanları dikkate alınmıştır.)  
- Maliyet Analizi (Yeni hat için tahmini maliyet hesaplanmıştır.)  
- Çevresel Etki (Daha az çevresel zarar veren seçenekler önceliklendirilmiştir.)  
- Sosyal Fayda (Ulaşımın mahalle halkına katkısı değerlendirilmiştir.)  

Softmax algoritması ile bu kriterlerin ağırlıkları hesaplanarak en uygun güzergah belirlenmiştir.

Softmax Algoritması ve Ağırlıklı Toplam
Bu projede kullanılan Softmax algoritması, her bir kriterin normalize edilmesini ve ağırlıklarının belirlenmesini sağlar. 
Aşağıdaki adımlar takip edilmiştir:
Veri Normalizasyonu: İlk olarak her bir mahalle için kriterlerin verileri normalize edilmiştir.
Ağırlık Hesaplama: Softmax fonksiyonu kullanılarak her bir kriterin ağırlığı hesaplanmıştır.
Ağırlıklı Toplam: Elde edilen ağırlıklar ile her kriterin toplam puanı hesaplanmış ve her mahalle için sonuçlar belirlenmiştir.
Sonuçların Karşılaştırılması: En yüksek toplam puanı alan mahalle seçilmiştir.


Kullanılan Yöntemler
Softmax Algoritması: Her kriter için ağırlıkları belirler.
Ağırlıklı Toplam Puan: En uygun güzergahı seçmek için hesaplanır.


Kullanılan Veriler 
| Mahalle          | Nüfus Yoğunluğu | Ulaşım Altyapısı | Maliyet (M TL) | Çevresel Etki | Sosyal Fayda |
|-----------------|----------------|------------------|---------------|--------------|-------------|
| İstasyon       | 13.318 kişi/km² | 7                | 1.2           | 6            | 8           |
| Karakaş        | 19.653 kişi/km² | 8                | 1.5           | 5            | 9           |
| Cumhuriyet     | 3.932 kişi/km²  | 5                | 1.0           | 7            | 6           |


Çıktı Örneği:
Mahalleler için Ağırlıklı Toplam Puanlar:
İstasyon Mahallesi Puan: 19677.1216
Karakaş Mahallesi Puan: 19677.1216
Cumhuriyet Mahallesi Puan: 19677.1216

En uygun toplu taşıma hattı için mahalle: İstasyon Mahallesi (Puan: 19677.1216)


Lisans:
MIT Lisansı altında yayınlanmıştır.
