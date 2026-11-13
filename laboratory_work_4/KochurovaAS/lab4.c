#include <stdio.h>

int main() {
    int vybor; 
    int shtrih; 
    int itog = 0;
    
    char name[6][100] = {"Bread", "Meat", "Milk", "Butter", "Chocolate", "Cookies"}; 
    int kod[6] = {1001, 1002, 1003, 1004, 1005, 1006}; 
    int price[6] = {40, 500, 70, 100, 80, 150}; 
    int skidka[6] = {0}; 
    int kolvo[6] = {0};

    printf("ELEKTRONNAYA KASSA\n");
    
    do {
        printf("\n1. Skanirovat tovar \n2. Chek \n3. Zavershit raboty \n Vybor: ");
        scanf("%d", &vybor);
        
        if (vybor == 1) {
            printf("Vvedite shtrihkod: "); 
            scanf("%d", &shtrih);
            
            int flag = -1;
            for (int i = 0; i < 6; i++) {
                if (kod[i] == shtrih) {
                    flag = i;
                    break;
                }
            }
            
            if (flag != -1) {
                printf("\n OPISANIE TOVARA \n");
                printf("Shtrihkod: %d\n", kod[flag]);
                printf("Name: %s\n", name[flag]);
                printf("Price: %d rub\n", price[flag]);
                
                int dobavit;
                printf("Dobavit tovar v chek? (1 - Yes, 0 - No): ");
                scanf("%d", &dobavit);
                
                if (dobavit == 1) {
                    if (kolvo[flag] == 0) {
                        int discount;
                        do {
                            printf("Vvedite skidku %s (1-50): ", name[flag]);
                            scanf("%d", &discount);
                            if (discount < 1 || discount > 50) { 
                                printf("Oshibka!\n"); 
                            }
                        } while (discount < 1 || discount > 50);
                        skidka[flag] = discount;
                    } else {
                        printf("Tovar v cheke. Skidka: %d%%\n", skidka[flag]);
                    }
                    kolvo[flag]++;
                    printf("Tovar dobavlen! Kol-vo v cheke: %d sht.\n", kolvo[flag]);
                } else {
                    printf("Tovar ne dobavlen v chek.\n");
                }
            } else {
                printf("Oshibka! Tovar so shtrihkodom %d ne nayden\n", shtrih);
            }
            
        } else if (vybor == 2 || vybor == 3) {
            int pust = 1;
            for (int i = 0; i < 6; i++) {
                if (kolvo[i] > 0) { pust = 0; break; }
            }
            
            if (pust == 1) {
                printf("\n Oshibka! Chek pust. \n");
                continue;
            }
            
            printf("\n CHEK \n");
            int summa_bez_skidki = 0;
            int summa_skidki = 0;
            itog = 0;
            
            for (int i = 0; i < 6; i++) {
                if (kolvo[i] > 0) {
                    int stoimost_bez = price[i] * kolvo[i];
                    int summa_tovara = stoimost_bez * (100 - skidka[i]) / 100;
                    
                    printf("%s | Price: %d | Kol-vo: %d | Itog: %d rub\n", 
                           name[i], price[i], kolvo[i], summa_tovara);
                    
                    summa_bez_skidki += stoimost_bez;
                    summa_skidki += (stoimost_bez - summa_tovara);
                    itog += summa_tovara;
                }
            }
            
            printf("Stoimost bez skidki: %d rub.\n", summa_bez_skidki);
            printf("Summarnaya skidka: %d rub.\n", summa_skidki);
            printf("K OPLATE: %d rub.\n", itog);
            
            if (vybor == 3) {
                printf("Spasibo za pokupku!\n");
            }
        }
    } while (vybor != 3);
    
    return 0;
}