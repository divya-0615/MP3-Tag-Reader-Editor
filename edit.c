#include <stdio.h>
#include<string.h>
#include<stdlib.h>

#include "mp3.h"

void edit_tag(char file_name[], char required_id[], char new_data[]){

    FILE *src = fopen(file_name, "rb");
    FILE *temp = fopen("temp.mp3", "wb");

    if(src == NULL || temp == NULL){
        printf("File Not present....!\n");
        return;
    }

    //Copy ID3 header 10 Bytes
    char header[10];

    fread(header, 1, 10, src);
    fwrite(header, 1, 10, temp);


    /* Read 6 frames */
    for(int i = 0; i < 6; i++){

        char frame_id[5];

        fread(frame_id, 1, 4, src);
        frame_id[4] = '\0';

        unsigned char size_bytes[4];

        fread(size_bytes, 1, 4, src);
        int size = (size_bytes[0] << 21) |  (size_bytes[1] << 14) | (size_bytes[2] << 7) |  size_bytes[3];

        unsigned char flags[2];
        fread(flags, 1, 2, src);

        unsigned char encoding;
        fread(&encoding, 1, 1, src);

        char data[100];
        fread(data, 1, size - 1, src);

        //Check required frame
        if(strcmp(frame_id, required_id) == 0)
        {
            int new_size = strlen(new_data) + 1;

            fwrite(frame_id, 1, 4, temp);

            unsigned char new_size_bytes[4];

            new_size_bytes[0] = (new_size >> 21) & 0x7F;
            new_size_bytes[1] = (new_size >> 14) & 0x7F;
            new_size_bytes[2] = (new_size >> 7) & 0x7F;
            new_size_bytes[3] = new_size & 0x7F;

            fwrite(new_size_bytes, 1, 4, temp);

            fwrite(flags, 1, 2, temp);

            fwrite(&encoding, 1, 1, temp);

            fwrite(new_data, 1, strlen(new_data), temp);
        }

        else{
            // Copying unchanged frame

            fwrite(frame_id, 1, 4, temp);
            fwrite(size_bytes, 1, 4, temp);
            fwrite(flags, 1, 2, temp);
            fwrite(&encoding, 1, 1, temp);
            fwrite(data, 1, size - 1, temp);
        }
    }


    // Copy remaining MP3 audio data 
    char buffer[1024];

    int bytes;

    while((bytes = fread(buffer, 1, 1024, src)) > 0){
        fwrite(buffer, 1, bytes, temp);
    }

    fclose(src);
    fclose(temp);

    // Replace old file 
    remove(file_name);
    rename("temp.mp3", file_name);

    printf("Tag updated successfully\n");
}