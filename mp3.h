#ifndef MP3_H
#define MP3_H

void read_menu(char file_name[]);

void read_tag(char file_name[], char required_id[]);
void edit_tag(char file_name[], char required_id[], char new_data[]);

#endif