#include <stdio.h>
#include <stdlib.h>
#include <string.h>





int main(){
    char input[150];

    for(;;) {
        printf("~ ");

        fgets(input, 150, stdin);
        input[strcspn(input, "\n")] = 0;

        if(strcmp(input, "print") == 0) {

            printf("hi\n");
            continue;

        } else if(strcmp(input, "rand") == 0) {

            printf("%d\n", rand() % 100);
            continue;

        } else if(strcmp(input, "help") == 0) {

            printf("Command list \n");
            printf("help - shows this page \n");
            printf("rand - gives random number from 1 to 100 \n");
            printf("clear - clears the screen \n");
            printf("calc - cool calculator \n");
            printf("exit - exits this shell thingy (kernel panics if you use cbsh as init)\n");
            printf("vim - opens the vim text editor\n");
            printf("insvim - install vim text editor\n");
            printf("ver - shows version\n");
            printf("bird - prints out bird :)\n");
            printf("yourmom - gives a yo mama joke \n");
            printf("login - login to an account\n");
            printf("dev - shows cbsh developer tools\n");
            continue;

        } else if(strcmp(input, "clear") == 0) {

            printf("\033[H\033[J");
            continue;

        } else if(strcmp(input, "calc") == 0) {

            float firstDigit;
            float secondDigit;
            char mathOperation[3];
            printf("Enter the first number: ");
            scanf("%f", &firstDigit);
            printf("Enter the second number: \n");
            scanf("%f", &secondDigit);

            printf("Enter the mathematical operation (add/sub/div/mul)\n");
            scanf(" %s", mathOperation);

            if(strcmp(mathOperation, "add") == 0){

                printf("The answer is %.2f\n", firstDigit + secondDigit);
                continue;
            }else if(strcmp(mathOperation, "sub") == 0){

                printf("The answer is %.2f\n", firstDigit - secondDigit);
                continue;
            }else if(strcmp(mathOperation, "div")== 0){

                printf("The answer is %.2f\n", firstDigit / secondDigit);
                continue;
            }else if(strcmp(mathOperation, "mul")== 0){

                printf("The answer is %.2f\n", firstDigit * secondDigit);
                continue;
            }else{

                printf("Error\n");
                return -1; // im quirky

            }
        } else if(strcmp(input, "exit") == 0) {

            return EXIT_SUCCESS;
        } else if(strcmp(input, "ver") == 0){

            printf("cool bird shell (cbsh) | version 1.3 \n");
            continue;

        } else if(strcmp(input, "bird") == 0) {

            printf("     _\\|      __     |/_ \n");
            printf("   _-  \\_   _/\"->   _/  -_\n");
            printf("   -_    `-'(   )`-'    _-\n");
            printf("    `=.__.=-(   )-=.__.='\n");
            printf("            |/-\\|\n");
            printf("            Y   Y\n");
            continue;

        } else if(strcmp(input, "test") == 0) {

            system("ls");
            continue;

        } else if(strcmp(input, "pwd") == 0) {

            system("pwd");
            continue;

        } else if(strcmp(input, "vim") == 0) {

            system("vim");
            continue;

        } else if(strcmp(input, "yourmom") == 0){

            switch (rand()%10) {
                case 1:
                    printf("Yo mama's so fat, when she fell I didn't laugh, but the sidewalk cracked up.\n ");
                    continue;
                case 2:
                    printf("Yo mama's so ugly, she threw a boomerang and it refused to come back.\n ");
                    continue;
                case 3:
                    printf("Yo mama's so old, she walked out of a museum and the alarm went off.\n ");
                    continue;
                case 4:
                    printf("Yo mama's so short, you can see her feet on her driver's license.\n ");
                    continue;
                case 5:
                    printf("Yo mama's so nasty, they used to call them jumpolines 'til yo mama bounced on one.\n ");
                    continue;
                case 6:
                    printf("Yo mama's so lazy, she stuck her nose out the window and let the wind blow it.\n ");
                    continue;
                case 7:
                    printf("Yo mama's so depressing, blues singers come to visit her when they've got writer's block.\n ");
                    continue;
            }
        } else if(strcmp(input, "login") == 0){

            char userName[20];
            char login[20] = "su ";
            printf("Enter your username:");
            fgets(userName, 20, stdin);
            strcat(login, userName);
            printf("%s", login);
            system(login);
            continue;

        } else if(strcmp(input, "whoami") == 0){

            system("whoami");
            continue;

        } else if(strcmp(input, "ls") == 0){

            system("ls");
            continue;

        } else if(strcmp(input, "make") == 0){

            printf("Compiling cbsh.c\n");
            system("gcc /home/simon/cbsh.c");
            continue;

        } else if(strcmp(input, "update") == 0){

            printf("Updating /bin/cbsh\n");
            system("cp /home/simon/a.out /bin/cbsh");
            continue;

        } else if(strcmp(input, "dev") == 0){

            printf("Developer tools\n");
            printf("make - compiles cbsh.c\n");
            printf("update - copies compiled cbsh.c (a.out) to /bin/cbsh\n");
            continue;

        } else if(strcmp(input, "insvim") == 0){


            char distro[5];
            printf("What is your distro / distro based off? (debian/fedora/arch)\n");
            scanf(" %s", distro);

            if(strcmp(distro, "debian") == 0){
                printf("Installing vim for debian\n");
                system("apt-get install vim");
                continue;

            } else if(strcmp(distro, "arch") == 0){
                printf("Installing vim for arch");
                system("pacman -S vim");
                continue;

            } else if(strcmp(distro, "fedora") == 0){
                printf("Installing vim for fedora");
                system("dnf install vim");
                continue;
            } else {
                printf("Invalid distro");
                continue;
            }

        }


        if (strcmp(input, "") != 0) {
            printf("Unknown command \"%s\", type 'help' for help\n", input);
            continue;
        }


    }

}
