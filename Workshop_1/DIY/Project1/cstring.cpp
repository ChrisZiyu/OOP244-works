/***********************************************************************
// Intro. to Object Oriented Programming
// Workshop 1 Part 2
// Version 1.0
// Description
// professor's tester program
//
// Revision History
// -----------------------------------------------------------
// Name  Christian Ziyu Ukiike          Date:5/22/2023            Reason
//
/////////////////////////////////////////////////////////////////
***********************************************************************/
#include "cstring.h"

namespace sdds {

    // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src) {
        while (*src != '\0') {
            *des = *src;
            des++;
            src++;
        }
        *des = '\0';
    }

    // Copies the source character string into the destination upto "len"
    // characters. The destination will be null terminated only if the number
    // of the characters copied is less than "len"
    void strnCpy(char* des, const char* src, int len) {
        int i = 0;
        while (i < len && src[i] != '\0') {
            des[i] = src[i];
            i++;
        }
        if (i < len)
        {
            des[i] = '\0';// it will null terminate the strin on index 2 [0][1][2][3] a b c d @@@'\0'd
        }

    }
    //// Compares two C-strings 
    //// returns 0 i thare the same
    //// return > 0 if s1 > s2
    //// return < 0 if s1 < s2
    int strCmp(const char* s1, const char* s2) {
        int i = 0;
        while (s1[i] != '\0' && s2[i] != '\0')
        {
            if (s1[i] > s2[i])
            {
                return 1;
            }
            else if (s1[i] < s2[i])
            {
                return -1;
            }
            i++;
        }
        return 0;
    }
    //// returns 0 i thare the same
    //// return > 0 if s1 > s2
    //// return < 0 if s1 < s2
    int strnCmp(const char* s1, const char* s2, int len) {
        int i = 0;
        while (i < len && s1[i] != '\0' && s2[i] != '\0') {
            if (s1[i] < s2[i]) {
                return -1;
            }
            else if (s1[i] > s2[i]) {
                return 1;
            }
            i++;
        }
        return 0;
    }

    // returns the lenght of the C-string in characters
    int strLen(const char* s) {
        int lenght = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            lenght++;
        }
        return lenght;
    }
    //// returns the address of first occurance of "str2" in "str1"
    //// returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2) {
       
        for (; *str1 != '\0'; str1++) {
            if (*str1 == *str2) {
                const char* p1 = str1;
                const char* p2 = str2;

                /* Start matching subsequent characters*/
                while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
                    p1++;
                    p2++;
                }

                // If we reached the end of str2, a match was found
                if (*p2 == '\0') {
                    return str1;
                }
            }
        }

        // No match found
        return nullptr;
    }

    //// Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src) {
        int desLen = strLen(des);
        int srcLen = strLen(src);

        // Copy the characters from src to the end of des
        strnCpy(des + desLen, src, srcLen);

        des[desLen + srcLen] = '\0';
    }

}