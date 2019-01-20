#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct WORDS{
    char eng[200];
    char pol[200];
};
void ADD();
void TRANSLATE();

int main (){
int choice=0;
printf("Hello there, weary traveller! You stumbled upon a translator. What would you like to do? Add a word(1) or translate(2)?\n");
scanf("%d", &choice);

switch(choice){
    case 1: /*For adding an entry*/
        ADD();
    break;
    case 2: /*For translation*/
        TRANSLATE();
    break;
    default: printf("there is no such choice, try again");
}

return 0;
}

/*ADDING*/
void ADD(){
    struct WORDS entry;
    int found=0;
    FILE *fp;
    fp=fopen("dictonary.txt", "a+");
    /*in case opening a file results in an error*/
    if(fp == NULL){
            printf("Error while opening the file!");
            exit(1);
            }

    printf("please type an English word you would like to add: ");
    scanf("%s", &entry.eng);
    /*checking if a word is already in dictionary*/
    while(fscanf(fp,"%s",&entry.pol)==1){
        if(strcmp(entry.pol, entry.eng)==0){
            found=1;
            break;
            }
        }
    if(found!=1){
    printf("now type in the Polish equivalent: ");
    scanf("%s", &entry.pol);
    fprintf(fp, "%s %s;\n", entry.eng, entry.pol);
    printf("you succesfully added an entry: \"%s = %s\", congratulations!", entry.eng, entry.pol);
    rewind(fp);
    fclose(fp);
    }
    else{printf("There already exists an entry like that, you can try translating \"%s\" to Polish", entry.eng);}
}
/*TRANSLATION*/
void TRANSLATE(){
    struct WORDS entry;
    char c;
    int found=0;
    FILE *fp;
    fp=fopen("dictonary.txt", "r");
    /*in case opening a file results in an error*/
    if(fp == NULL){
            printf("Error while opening the file!");
            exit(1);
            }

    printf("please type in an English word you would like to translate: ");
    scanf("%s", &entry.eng);
    /*Check if specified word is found, if yes, set parameter f to 1*/
    while(fscanf(fp,"%s",&entry.pol)==1){
        if(strcmp(entry.pol, entry.eng)==0){
            found=1;
            break;
            }
        }
    /*Detecting if there is no such entry*/
    if(found!=1){printf("There is no such entry yet. Perhaps the archives are incomplete?");}
    /*Specified word found, print its Polish equivalent*/
    else{
    printf("\n%s in Polish:", entry.eng);
    while(fscanf(fp,"%c",&c)==1){
        /*checking for end of line, marked with ";"*/
        if(c!=59){
            printf("%c", c);
            }
        if(c==59){break;}
    }}
rewind(fp);
fclose(fp);
}

