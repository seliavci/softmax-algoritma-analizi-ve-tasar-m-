//
//  main.c
//  softmax algortima ve tasarımı
//
//  Created by Selin Avcı on 10.02.2025.
//

#include <stdio.h>
#include <math.h>

// Softmax fonksiyonu
void softmax(double *data, int size, double *result) {
    double max_value = data[0];
    // İlk olarak, en büyük değeri buluyoruz (overflow önlemek için)
    for (int i = 1; i < size; i++) {
        if (data[i] > max_value) {
            max_value = data[i];
        }
    }

    // Her değeri normalize ediyoruz
    double sum = 0.0;
    for (int i = 0; i < size; i++) {
        result[i] = exp(data[i] - max_value); // Stabilize etmek için max_value çıkarıyoruz
        sum += result[i];
    }

    // Son olarak, her değeri normalize ediyoruz
    for (int i = 0; i < size; i++) {
        result[i] /= sum;
    }
}

// Ağırlıklı toplam hesaplama fonksiyonu
double calculate_weighted_sum(double *softmax_result, double *values, int size) {
    double weighted_sum = 0.0;
    for (int i = 0; i < size; i++) {
        weighted_sum += softmax_result[i] * values[i];
    }
    return weighted_sum;
}

int main() {
    // Mahalle isimleri
    char *mahalleler[] = {"İstasyon Mahallesi", "Karakaş Mahallesi", "Cumhuriyet Mahallesi"};
    
    // Veriler: Nüfus Yoğunluğu, Ulaşım Altyapısı, Maliyet, Çevresel Etki, Sosyal Fayda
    double nufus_yogunlugu[] = {13318, 19653, 3932}; // 3 mahalle
    double ulasim_altyapisi[] = {7, 8, 5};
    double maliyet[] = {1.2, 1.5, 1};
    double cevresel_etki[] = {6, 5, 7};
    double sosyal_fayda[] = {8, 9, 6};

    int size = 3; // 3 mahalle var

    double result[3]; // Softmax sonuçları için

    // Her kriter için Softmax hesaplamaları
    double nufus_yogunlugu_softmax[3];
    double ulasim_altyapisi_softmax[3];
    double maliyet_softmax[3];
    double cevresel_etki_softmax[3];
    double sosyal_fayda_softmax[3];

    // Softmax hesaplamaları
    softmax(nufus_yogunlugu, size, nufus_yogunlugu_softmax);
    softmax(ulasim_altyapisi, size, ulasim_altyapisi_softmax);
    softmax(maliyet, size, maliyet_softmax);
    softmax(cevresel_etki, size, cevresel_etki_softmax);
    softmax(sosyal_fayda, size, sosyal_fayda_softmax);

    // Ağırlıklı toplam hesaplamaları
    double total_scores[3];

    for (int i = 0; i < size; i++) {
        total_scores[i] = calculate_weighted_sum(nufus_yogunlugu_softmax, nufus_yogunlugu, size) +
                          calculate_weighted_sum(ulasim_altyapisi_softmax, ulasim_altyapisi, size) +
                          calculate_weighted_sum(maliyet_softmax, maliyet, size) +
                          calculate_weighted_sum(cevresel_etki_softmax, cevresel_etki, size) +
                          calculate_weighted_sum(sosyal_fayda_softmax, sosyal_fayda, size);
    }

    // En yüksek puanı bulan mahalleyi belirleme
    int best_mahalle = 0;
    double max_score = total_scores[0];
    for (int i = 1; i < size; i++) {
        if (total_scores[i] > max_score) {
            max_score = total_scores[i];
            best_mahalle = i;
        }
    }

    // Sonuçları yazdırıyoruz
    printf("Mahalleler için Ağırlıklı Toplam Puanlar:\n");
    for (int i = 0; i < size; i++) {
        printf("%s Puan: %.4f\n", mahalleler[i], total_scores[i]);
    }

    printf("\nEn uygun toplu taşıma hattı için mahalle: %s (Puan: %.4f)\n", mahalleler[best_mahalle], max_score);

    return 0;
}
