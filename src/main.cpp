#include"tests.h"

int main()
{
        int choice = 0;

        printf("Choose a function to test:\n"
               "1) strlen_f()\n"
               "2) scrcpy_f()\n"
               "3) strchr_f()\n"
               "4) strcmp_f()\n"
               "5) strcat_f()\n");

        while(scanf("%d", &choice)) {
                while (getchar() != '\n')
                        ;

                switch (choice) {
                        case 1:
                                test_strlen_f();
                                break;
                        case 2:
                                test_strcpy_f();
                                break;
                        case 3:
                                test_strchr_f();
                                break;
                        case 4:
                                test_strcmp_f();
                                break;
                        case 5:
                                test_strcat_f();
                                break;
                        default: 
                                printf("Wrong input.\n");
                }
        }

        return 0;
}

