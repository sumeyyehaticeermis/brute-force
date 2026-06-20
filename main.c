#include <stdio.h>
#include <string.h>
/** bu fonksiyon, bir "hakem" görevi görür.
*verilen  harmanlanmış dizinin, orijinal dizilerin (s1 ve s2)
*içsel  sıralamasını koruyup korumadığını denetler.
*/

int sirayi_koruyor_mu (char* harman, char *s1, char *s2) {
    int i=0; //s1 dizisinin hangi karakterinde olduğumuzu tutan imleç
    int j=0; //s2 dizisinin hangi karakterinde olduğumuzu tutan imleç
    int k=0; //test edilen harmanlanmış dizinin hangi karakterinde olduğumuzu tutan imleç
    
    //harmanlanmış dizinin sonunda (null karakterine) kadar her harfi tek tek inceliyoruz.
    while (harman [k] != '\0') {
        //eger harmanlanmıs dizideki karakter s1'in sıradaki karakteriyle aynıysa ve henüz s1'in sonunda gelmediysek
        if (i< strlen (s1) && harman[k] == s1[j]) {
            i++ ; // s1 dizisinde bir sonraki harfe bakabiliriz (sıra doğru gidiyor).
        }
        //degilse eger s2'nin sıradaki karakteriyle aynıysa ve henüz s2'nin sonuna gelmediysek
        else if (j< strlen (s2) && harman [k] == s2[j]) {
            j++; // s2 dizisinde bir sonraki harfe bakılabilir
        }
        //eger harf ne s1 ne s2nin o anki sırasındaki harf değilse bu harmanlama yanlıştır (sira bozulmuş veya yabancı harf girmiştir.)
        k++ ; //harmanlmış dizide bir sonraki harfe geç.
    }
    
    if (i == strlen(s1) && j == strlen(s2)) {
        return 1;
        
    } else {
        return 0;
    }}
    //ana fonksiyon
    int main (void) {
        char s1 [] = "AB" ;
        char s2 [] = "CD" ;
        char sonuc [] = "ACBD" ; //test edilecek harmanlama
        
        printf ("dizi 1: %s, dizi2: %s\n", s1,s2);
        printf("test edilen: %s\n", sonuc);
        
        //kaba kuvvet; bu sonucun kurallara uyup uymadığını kontrol et
        if (sirayi_koruyor_mu(sonuc, s1, s2)) {
            printf ("gecerli bir harmanlama !\n");
        } else
        {
            printf ("gecersiz harmanlama.\n");
        }
        return 0;
    }
