#define _CRT_SECURE_NO_WARNINGS
#define MAX_LINES 20
#define MAX_LINE_LENGTH 200
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include "attribute_parser.h"

bool is_element_close(char* element, char* line)
{
    if (*(line + 1) != '/') {
        return false;
    }
    int closeNameLength = strcspn(line + 2, ">");
    int elementNameLength = strcspn(element + 1, "> ");
    if (closeNameLength != elementNameLength) {
        return false;
    }
    for (int i = 0; i < elementNameLength; i++) {
        if ((element + 1)[i] != (line + 2)[i]) {
            return false;
        }
    }
    return true;
}

bool element_matches(char* element, char* query)
{
    int elementNameLength = strcspn(element + 1, "> ");
    int queryWordLength = strcspn(query, ".~");
    if (elementNameLength != queryWordLength) {
        return false;
    }
    for (int i = 0; i < elementNameLength; i++) {
        if ((element + 1)[i] != query[i]) {
            return false;
        }
    }
    return true;
}

char* find_query_match(char* hrml, char* query)
{
    // If the current line of hrml doesn't start with
    // < then it isn't HRML.
    if (*hrml != '<') {
        return NULL;
    }
    // If the current line represents an element close
    // this steps us up the HRML tree and the query is
    // no longer matching.
    if (*(hrml + 1) == '/') {
        return NULL;
    }
    
    // If the current element start matches the query
    // either the query is exhaused or update and recurse.
    if (element_matches(hrml, query)) {
        char* pch = strchr(query, '.');
        if (pch == NULL) {  // found the last element of the query
            return hrml;
        }
        else {
            return find_query_match(hrml + MAX_LINE_LENGTH, pch + 1);
        }
    }
    else {  // Move beyond the current element and end or recurse
        int lineToConsider = 1;
        while (!is_element_close(hrml, hrml + (MAX_LINE_LENGTH * lineToConsider))) {
            lineToConsider++;
        }
        return find_query_match(hrml + (MAX_LINE_LENGTH * (lineToConsider + 1)), query);
    }
}

char* get_attribute(char* element, char* key)
{
    char fullKey[MAX_LINE_LENGTH];
    strcpy(fullKey, key);
    fullKey[strlen(key) - 1] = '\0';
    strcat(fullKey, " = ");
    char * pntr = strstr(element, fullKey);
    if (pntr == NULL) {
        return NULL;
    }
    else {
        return pntr + strlen(fullKey) + 1;
    }
}

int hackerrank::attribute_parser()
{
    int n, q;
    scanf("%d %d\n", &n, &q);

    // read the HRML lines
    char hrml[MAX_LINES * MAX_LINE_LENGTH];
    for (int i = 0; i < n; i++) {
        fgets(hrml + i * MAX_LINE_LENGTH, MAX_LINE_LENGTH, stdin);
    }

    // parse the queries
    // search for the results
    // and store them
    char results[MAX_LINES * MAX_LINE_LENGTH];
    char query[MAX_LINE_LENGTH];
    for (int i = 0; i < q; i++) {
        fgets(query, MAX_LINE_LENGTH, stdin);
        char* match = find_query_match(hrml, query);
        if (match == NULL) {
            strcpy(results + MAX_LINE_LENGTH * i, "Not Found!");
        }
        else {
            char* value = get_attribute(match, strchr(query, '~') + 1);
            if (value == NULL) {
                strcpy(results + MAX_LINE_LENGTH * i, "Not Found!");
            }
            else {
                int num = strcspn(value, "\"");
                strncpy(results + MAX_LINE_LENGTH * i, value, num);
                (results + MAX_LINE_LENGTH * i)[num] = '\0';
            }
        }
    }
    
    // print the results
    for (int i = 0; i < q; i++) {
        printf("%s\n", results + i * MAX_LINE_LENGTH);
    }
    return 0;
}
