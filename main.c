#include<stdio.h>
#include<stdlib.h>

void welcome_message();
int insert();
int append();
int view();

int main()
{
    FILE *fp;
    int operation;
    int num;
    First:
    printf("\n\n\t***********************************\n");
    printf("\t*NOTES APPLICATION BY MURITALA DAVID*\n");
    printf("\t***********************************\n");
    printf("        '1' <----> Create a note     \n");
    printf("        '2' <----> Append on the note    \n");
    printf("        '3' <----> View Previous note     \n");
    printf("        '4' <----> Exit The Program     \n\n");
    printf("-------------------------------\n\n");

    while(1)
    {
        scanf("%d",&operation);

        switch(operation)

        {

            case 1:
                insert();
                printf("operation '1' for continue\n'0' for Exit\n");
                scanf("%d", &num);
                if (num == 1){
                    goto First;
                }
                break;

            case 2:
                append();
                printf("operation '1' for continue\n'0' for Exit\n");
                scanf("%d", &num);
                if (num == 1){
                    goto First;
                }
                break;

            case 3:
                view();
                printf("operation '1' for continue\n'0' for Exit\n");
                scanf("%d", &num);
                if (num == 1){
                    goto First;
                }
                break;

            case 4:

                printf("\n\n\t\tTHANK YOU FOR USING THE NOTES CLI-APP ");
                exit(0);

            default:

                printf("\nYOU ENTERED WRONG CHOICE..");
                printf("\nPRESS ANY KEY TO TRY AGAIN");

                break;

        }
    }
}

void welcome_message() {
    printf("---***---***----***----***----***---\n\n");
    printf("|<--     Welcome to Notes Application    -->|\n\n");
    printf("---***---***----***----***---***---\n\n");
}

int insert(){
    FILE *fp;
    char note[2000], date[20] ;
    welcome_message();
    printf("Enter date of your note : ");
    scanf("%s", date);
    printf("\n");
    printf("Just write your note from here....\n---->>");
    scanf(" %[^\n]s",note);
    fp = fopen("note.txt", "w");
    fprintf(fp, date);
    fprintf(fp, "\n");
    fprintf(fp, note);
    fprintf(fp, "\n\n");
    printf("\nSuccessfully Copied.....:)\n");
    fclose(fp);
    return 0;
}

int append() {
    FILE *fp;
    char note[2000], date[20] ;
    welcome_message();
    printf("Enter date of your note : ");
    scanf("%s", date);
    //printf("%s",date);
    printf("\n");
    printf("Just write your note from here....\n---->>");
    scanf(" %[^\n]s", note);
    fp = fopen("note.txt", "a");
    fprintf(fp, date);
    fprintf(fp, "\n");
    fprintf(fp, note);
    fprintf(fp, "\n\n");
    printf("\nSuccessfully Copied.....:)\n");
    fclose(fp);
    return 0;
}

int view() {
    FILE *fp;
    char ch;
    fp = fopen("note.txt", "r");
    if (fp == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nYour previous note : \n\n");
    printf("===============================================================================\n");

    while( ( ch = fgetc(fp) ) != EOF ){
        printf("%c", ch);
    }
    printf("\n");
    printf("===============================================================================\n");
    fclose(fp);
    return 0;
}