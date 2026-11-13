#include <stdio.h>
#include <string.h>
#include "mp3.h"

void read_tag(char file_name[], char required_id[]);

void read_menu(char file_name[]){
    printf("\n");
    printf("____________________ READ MENU ____________________\n");
    printf("1. Title\n");
    printf("2. Artist\n");
    printf("3. Album\n");
    printf("4. Year\n");
    printf("5. Genre\n");
    printf("6. Comment\n");
    printf("7. All\n");
    printf("8. Back\n");
    printf("____________________________________________________\n");


    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if(choice == 1){
        read_tag(file_name, "TIT2");
    }
    else if(choice == 2){
        read_tag(file_name, "TPE1");
    }
    else if(choice == 3){
        read_tag(file_name, "TALB");
    }
    else if(choice == 4){
        read_tag(file_name, "TYER");
    }
    else if(choice == 5){
        read_tag(file_name, "TCON");
    }
    else if(choice == 6){
        read_tag(file_name, "COMM");
    }
    else if(choice == 7){
        printf("All selected\n");
        
        read_tag(file_name, "TIT2");
        read_tag(file_name, "TPE1");
        read_tag(file_name, "TALB");
        read_tag(file_name, "TYER");
        read_tag(file_name, "TCON");
        read_tag(file_name, "COMM");
    }
    else if(choice == 8){
        return;
    }
    else{
        printf("Invalid choice\n");
    }

}


void read_tag(char file_name[], char required_id[]){

    FILE *fp = fopen(file_name, "rb");

    if(fp == NULL)
    {
        printf("File Not present....!\n");
        return;
    }

    char header[10];
    fread(header, 1, 10, fp);

    for(int i = 0; i < 6; i++)
    {
        char frame_id[5];
        fread(frame_id, 1, 4, fp);
        frame_id[4] = '\0';

        unsigned char size_bytes[4];
        fread(size_bytes, 1, 4, fp);

        int size = (size_bytes[0] << 21) |  (size_bytes[1] << 14) | (size_bytes[2] << 7) |  size_bytes[3];

        unsigned char flags[2];
        fread(flags, 1, 2, fp);

        unsigned char encoding;
        fread(&encoding, 1, 1, fp);

        char data[100];

        if(size > 100){
            printf("Tag data is too large\n");
            fclose(fp);
            return;
        }

        fread(data, 1, size - 1, fp);
        data[size - 1] = '\0';

        if(strcmp(frame_id, required_id) == 0)
        {
            if(strcmp(required_id, "TIT2") == 0){
                printf("Title: %s\n", data);
            }
            else if(strcmp(required_id, "TPE1") == 0){
                printf("Artist: %s\n", data);
            }
            else if(strcmp(required_id, "TALB") == 0){
                printf("Album: %s\n", data);
            }
            else if(strcmp(required_id, "TYER") == 0){
                printf("Year: %s\n", data);
            }
            else if(strcmp(required_id, "TCON") == 0){
                printf("Genre: %s\n", data);
            }
            else if(strcmp(required_id, "COMM") == 0){
                printf("Comment: %s\n", data);
            }
            fclose(fp);
            return;
        }
    }

    fclose(fp);

    printf("Tag not found\n");
}