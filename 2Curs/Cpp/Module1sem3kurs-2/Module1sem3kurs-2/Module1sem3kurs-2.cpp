#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <Windows.h>
void one() {
    int buffer;
    char buf[20];
    printf("Введіть кількість кодів у масиві >> ");
    scanf("%d", &buffer);
    char** kod = (char**)malloc(sizeof(char*) * buffer);
    for (int i = 0; i < buffer; i++) {
        kod[i] = (char*)malloc(sizeof(char) * 6);
        printf("Ведіть код номер [%d] : ",i+1);
        scanf("%s", &buf);
        kod[i][0] = buf[0];
        kod[i][1] = buf[1];
        kod[i][2] = buf[2];
        kod[i][3] = buf[3];
        kod[i][4] = buf[4];
        kod[i][5] = '\0';
    }
    printf("\nДо перетворення \n");
    for (int i = 0; i < buffer; i++) printf("Код номер[%d] = %s\n",i+1, kod[i]);
    printf("\nПісля перетворення \n");
    for (int i = 0; i < buffer; i++) {
        printf("Код номер [%d] ::\t", i + 1);
        for (int z = 0; z < 5; z++) {
            int ex = rand() % 256;
            while (ex == 95 || (ex > 190 && ex < 224)) ex = rand() % 256;
            kod[i][z] = ex + 'A';
            printf("%c", kod[i][z]);
        }
        printf("\n");
    }
}
void two() {
    int** F = (int**)malloc(sizeof(int*) * 3);
    for (int i = 0; i < 3; i++) F[i] = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < 6; i++) {
        if (i == 0 || i == 2 || i == 4) {
            printf("Ведіть значення для [%d] рядку розмежовуючи пробілом: ", i / 2 + 1);
            scanf("%d", &F[i / 2][i % 2]);
        } else {
            scanf("%d", &F[i / 2][i % 2]);
            F[i / 2] = (int*)realloc(F[i / 2], sizeof(int) * 4);
            F[i / 2][2] = F[i / 2][1] + F[i / 2][0];
            F[i / 2][3] = F[i / 2][1] * F[i / 2][0];
        }
    }
    for (int i = 0; i < 3; i++) printf("значення у [%d] стопчику: %d %d %d %d\n",i+1, F[i][0],F[i][1], F[i][2], F[i][3]);
}
void three(int index = 0) {
    for (int one = 1; one <= 9; one += 2) 
        for (int two = 1; two <= 9; two += 2) 
            for (int three = 1; three <= 9; three += 2) 
                for (int four = 1; four <= 9; four += 2) 
                    for (int five = 1; five <= 9; five += 2) 
                        printf("[%d]: %d%d%d%d%d\n", index++, one, two, three, four, five);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    printf("\nВаріант 4 завадання 1 \n\n");
    one();
    printf("\nВаріант 4 завадання 2 \n\n");
    two();
    printf("\nВаріант 8 завадання 3 \n\n");
    three();
}
