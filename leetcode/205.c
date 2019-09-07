#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Map {
    char key;
    char val;
    struct Map* next;
}Map;

bool is_contain_key(Map* map, char c) {
    while(map) {
        if(c == map->key) return true;
        map = map->next;
    }
    return false;
}

bool is_contain_val(Map* map, char value) {
    while(map) {
        if(value == map->val) return true;
        map = map->next;
    }
    return false;
}

Map* add_map(Map* map, char key, char value) {
    Map* node = (Map*)malloc(sizeof(Map));
    node->key = key;
    node->val = value;
    node->next = map;
    return node; 
}

char map_val(Map* map, char key) {
    while(map) {
        if(map->key == key) return map->val;
        map = map->next;
    }
    return '$';
}

bool isIsomorphic(char* s, char* t) {
    Map* map = (Map*)malloc(sizeof(Map));
    map->key = '\0';
    map->val = '\0';
    map->next = NULL;
    size_t len = strlen(s);
    for(size_t i = 0; i < len; ++i) {
        if(!is_contain_key(map, s[i])) {
            if(!is_contain_val(map, t[i])) {
                map = add_map(map, s[i], t[i]);
            }
        }
    }
    char tmp;
    for(size_t i = 0; i < len; ++i) {
        tmp = map_val(map, s[i]);
        if(tmp != t[i]) return false;
    }
    return true;
}

int main() {
    char* s = "ab";
    char* t = "aa";
    char* r = "hry";
    printf("%d\n", isIsomorphic(s, t));
    // printf("%d\n", isIsomorphic(s, r));
    return 0;
}