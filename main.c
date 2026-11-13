#include <stdio.h>
#include <string.h>

#include "mp3.h"

int main(int argc, char *argv[]){

    printf("=============================================================================== \n");
    printf("                            MP3 TAG READER & EDITOR \n");
    printf("=============================================================================== \n");

    // Check command line arguments
    if(argc < 2)
    {
        printf("Invalid arguments\n");
        printf("Use -h or -help for help\n");
        return 0;
    }

    /* Help */
    if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "-help") == 0){

        printf("\nMP3 TAG READER & EDITOR\n\n");

        printf("Help:\n");
        printf("./a.out -h\n");
        printf("./a.out -help\n\n");

        printf("View:\n");
        printf("./a.out -v song.mp3\n\n");
                
        printf("Edit:\n");
        printf("./a.out -e song.mp3 -t New Title --title\n");
        printf("./a.out -e song.mp3 -A New Artist --artist\n");
        printf("./a.out -e song.mp3 -a New Album --album\n");
        printf("./a.out -e song.mp3 -y New Year --year\n");
        printf("./a.out -e song.mp3 -C New Comment --comment\n");
        printf("./a.out -e song.mp3 -c New data --genre\n");

        return 0;
    }



                                                    /* View */
    if(strcmp(argv[1], "-v") == 0){

        if(strstr(argv[2], ".mp3") == NULL){
            printf("Error: File must be an MP3 file\n");
            return 0;
        }

        FILE *fp = fopen(argv[2], "rb");

        if(fp == NULL){
            printf("File does not exist\n");
            return 0;
        }
        fclose(fp);

        if(argc < 3){
            printf("MP3 file name is missing\n");
            return 0;
        }

        read_menu(argv[2]);

        return 0;
    }

                                                    /* Edit */
    
    /* Edit */
    if(strcmp(argv[1], "-e") == 0)
    {
        if(argc < 3)
        {
            printf("MP3 file name is missing\n");
            return 0;
        }

        if(strstr(argv[2], ".mp3") == NULL)
        {
            printf("Error: File must be an MP3 file\n");
            return 0;
        }

        FILE *fp = fopen(argv[2], "rb");

        if(fp == NULL){
            printf("File does not exist\n");
            return 0;
        }
        fclose(fp);

        if(argc < 5){
            printf("Invalid edit command\n");
            printf("Example: ./a.out -e sample.mp3 -t New Title \n");
            return 0;
        }

        char required_id[5];
        char new_data[100] = "";

        // Select the tag
        if(strcmp(argv[3], "-t") == 0)
            strcpy(required_id, "TIT2");
        else if(strcmp(argv[3], "-A") == 0)
            strcpy(required_id, "TPE1");
        else if(strcmp(argv[3], "-a") == 0)
            strcpy(required_id, "TALB");
        else if(strcmp(argv[3], "-y") == 0)
            strcpy(required_id, "TYER");
        else if(strcmp(argv[3], "-C") == 0)
            strcpy(required_id, "COMM");
        else if(strcmp(argv[3], "-c") == 0)
            strcpy(required_id, "TCON");
        else
        {
            printf("Invalid tag option\n");
            return 0;
        }

        for(int i = 4; i < argc; i++)
        {
            strcat(new_data, argv[i]);

            if(i < argc - 1)
                strcat(new_data, " ");
        }

        edit_tag(argv[2], required_id, new_data);

        return 0;
    }


    printf("Invalid command\n");
    printf("Use -h or -help for help\n");

    return 0;
}

