/*
 *  File Name: lab2exe_B.cpp
 *  Assignment: ENSF 614 Lab 2, exercise B
 *  Created by Mahmood Moussavi
 *  Completed by: Emmanuel Alafonye
 *  Submission Date: Sept 27, 2023.
 */

#include <iostream>
#include <cstring>
using namespace std;

int my_strlen(const char *s);

void my_strncat(char *dest, const char *source, int n);

int my_strcmp(const char *s1, const char *s2);
/*
 *  Duplicates strcmp from <cstring>.
 *  Compares two strings lexicographically.
 *
 *  REQUIRES
 *     s1 and s2 point to the beginning of strings.
 *  PROMISES
 *     Returns 0 if s1 is equal to s2.
 *     Returns a positive integer if s1 is greater than s2.
 *     Returns a negative integer if s1 is less than s2.
 */

int main(void) {
    char str1[7] = "banana";
    const char str2[] = "-tacit";
    const char* str3 = "-toe";
    
    /* point 1 */
    char str5[] = "ticket";
    char my_string[100] = "";
    int bytes;
    int length; // Let is initialized.
    
    /* using my_strlen custom function */
    length = my_strlen(my_string);
    cout << "\nLine 1: my_string length is " << length;
  
    /* using sizeof operator */
    bytes = sizeof (my_string);
    cout << "\nLine 2: my_string size is " << bytes << " bytes.";
   
    /* using strcpy library function */
    strcpy(my_string, str1);
    cout << "\nLine 3: my_string contains: " << my_string;
   
    length = my_strlen(my_string);
    cout << "\nLine 4: my_string length is " << length << ".";
   
    my_string[0] = '\0';
    cout << "\nLine 5: my_string contains:\"" << my_string << "\"";
  
    length = my_strlen(my_string);
    cout << "\nLine 6: my_string length is " <<  length << ".";
   
    bytes = sizeof (my_string);
    cout << "\nLine 7: my_string size is still " << bytes << " bytes.";
 
    /* my_strncat appends the first 3 characters of str5 to the end of my_string */
    my_strncat(my_string, str5, 3);
    cout << "\nLine 8: my_string contains:\"" << my_string << "\"";
  
    length = my_strlen(my_string);
    cout << "\nLine 9: my_string length is " << length << ".";
   
    my_strncat(my_string, str2,  4);
    cout << "\nLine 10: my_string contains:\"" << my_string << "\"";
    
    /* my_strncat appends ONLY up to '\0' character from str3 -- not 6 characters */
    my_strncat(my_string, str3, 6);
    cout << "\nLine 11: my_string contains:\"" << my_string << "\"";
   
    length = my_strlen(my_string);
    cout << "\nLine 12; my_string has " << length << " characters.";

    cout << "\n\nUsing my_strcmp - Custom function: ";
    
    cout << "\n\"ABCD\" is less than \"ABCDE\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABCDE");

    cout << "\n\"ABCD\" is less than \"ABND\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABND");
    
    cout << "\n\"ABCD\" is equal than \"ABCD\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABCD");
 
    cout << "\n\"ABCD\" is less than \"ABCd\" ... my_strcmp returns: " <<
    my_strcmp("ABCD", "ABCd");

    cout << "\n\"Orange\" is greater than \"Apple\" ... my_strcmp returns: " <<
    my_strcmp("Orange", "Apple") << endl;
    return 0;
}

int my_strlen(const char *s) {
    int length = 0;
    while (*s != '\0') {
        length++;
        s++;
    }
    return length;
}

void my_strncat(char *dest, const char *source, int n) {
    int dest_len = my_strlen(dest);
    int i;
    for (i = 0; i < n && source[i] != '\0'; i++) {
        dest[dest_len + i] = source[i];
    }
    dest[dest_len + i] = '\0';
}

int my_strcmp(const char *s1, const char *s2) {
    while (*s1 != '\0' && *s2 != '\0') {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
        s1++;
        s2++;
    }
    if (*s1 == '\0' && *s2 == '\0') {
        return 0;
    }
    if (*s1 == '\0') {
        return -(*s2);
    }
    return *s1;
}

