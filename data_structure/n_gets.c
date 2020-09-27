#include <stdio.h>
#include <string.h>

typedef struct Hash {
    int key;
    char data[1000];
} hash_t;

void initial(hash_t hash_table[]) {
    for(int i = 0; i < 26; i++) {
        hash_table[i].key = -1;
        strcpy(hash_table[i].data, "");
    }
}

int main()
{
    char name[1000];
    while(gets(name) && strlen(name)) {
        hash_t hash_table[26];
        initial(hash_table);

        int first_char_index = name[0] - 'A';
        hash_table[first_char_index].key = first_char_index;
        strcpy(hash_table[first_char_index].data, name);
        for(int i = 0; i < 25; i++) {
            gets(name);
            first_char_index = name[0] - 'A';
            int current_index = first_char_index;
            while(1) {
                current_index = current_index % 26;
                if(hash_table[current_index].key != -1) {
                    current_index++;
                    continue;
                }
                else {
                    hash_table[current_index].key = first_char_index;
                    strcpy(hash_table[current_index].data, name);
                    break;
                }
            }
        }

        for(int i = 0; i < 26; i++) {
            printf("%d %d %s\n", i, hash_table[i].key, hash_table[i].data);
        }
    } 

    return 0;
}