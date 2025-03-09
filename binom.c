#include <stdio.h>

// Faktöriyel hesaplayan fonksiyon
int faktoriyel(int sayi) {
    int sonuc = 1;
    for (int i = 1; i <= sayi; i++) {
        sonuc *= i;
    }
    return sonuc;
}

// Kombinasyon hesaplayan fonksiyon C(n, k) = n! / (k! * (n-k)!)
int kombinasyon(int n, int k) {
    return faktoriyel(n) / (faktoriyel(k) * faktoriyel(n - k));
}

// Binom açılımı fonksiyonu
void binom_acilimi(int a, int b, int n) {
    printf("(%d + %d)^%d acilimi:\n", a, b, n);
    for (int k = 0; k <= n; k++) {
        int katsayi = kombinasyon(n, k);
        int terim1 = 1, terim2 = 1;
        
        // a^(n-k) ve b^k hesaplanıyor
        for (int i = 0; i < n - k; i++) terim1 *= a;
        for (int i = 0; i < k; i++) terim2 *= b;
        
        // Terim ekrana yazdırılıyor
        printf("%d", katsayi * terim1 * terim2);
        
        if (n - k > 0) printf("x^%d", n - k); // x^üslü terimler
        if (k < n) printf(" + "); // Son terimden sonra "+" koyma
    }
    printf("\n");
}

// Ana fonksiyon
int main() {
    int a, b, n;
    
    printf("Binom acilimi için a, b ve n degerlerini girin (a + b)^n: ");
    scanf("%d %d %d", &a, &b, &n);
    
    binom_acilimi(a, b, n);
    
    return 0;
}