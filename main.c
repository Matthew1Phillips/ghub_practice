/* Dear reader: 
 * 
 * Please run this before reviewing the code for a surprise. 
 * 
 * How to: Linux: If you have gcc: in Terminal type: 
 *                gcc -o main.o main.c
 *
 *                Following, type:
 *                ./main.o
 */

#include <stdio.h>

/* Preprocessor defines. */
#define FALSE    0
#define TRUE     1
//#define DEBUG_MODE        // User selection before build.

/* Helper functions for print statements. */
void printThankYou(void);
void printBuzz(void);
void printFizz(void);
void printBuzzFizz(void);

/* Check if input is a prime number (2, 3, 5, 7, etc.).
 * Return 0 if false, 1 if true.
 */
int isPrime(int num) {
    /* It's not prime if less than 2; return FALSE. */
    if (num < 2)
        return FALSE;
    else if (num == 2) {
        return TRUE;
    }
    
    /* Start with half of input plus 1. This takes
     * care of both even and odd numbered values.
     * Ex: 11/2 = 5 (in C that is). Then +1 = 6. Also
     * use efficient data types (unsigned int).
     */
    unsigned int nnum = (unsigned int)num;
    unsigned int i = (unsigned int)(num/2 + 1);
    
    /* A faster version of mod, taking into account data
     * types that have the potential to speed up the algorithm.
     * Also recognizing that comparisons to zero have smaller form      * factor in some assembly languages.
     *
     * This is the equivalent of:
     * while (i % num != 0) {
     *       i--;
     *        if (i == 1) {
     *           return TRUE;
     *        }
     *    }
     *    return FALSE;
     */
    while (nnum - i * (nnum / i) != 0) {
        if (!((--i) - 1)) {
            return TRUE;
        }
    }
    return FALSE;
}

/* A helper function to check for the possible
 * conditions from the code, and print the desired
 * strings.:
 * – Is the number divisible by 3?
 * – Is the number divisible by 5?
 * – Is the number prime?
 */
void fizzBuzz(unsigned int val) {
    unsigned int flag = 0;
    
    /* Simple cases that don't play nice with the 
     * following mod equations. 
     */
    if (val < 2) {
        printf("\n%u\n", val);
        return;
    }
    
    /* Check if divisible by 3, using efficient mod. */
    if (!(val - 3 * (val / 3))) {
        flag++;
        #ifdef DEBUG_MODE
        printf("%u\n", val);
        #endif
        printBuzz();
    }
    
    /* Check if divisible by 5, using efficient mod. */
    if (!(val - 5 * (val / 5))) {
        flag++;
        #ifdef DEBUG_MODE
        printf("%u\n", val);
        #endif
        printFizz();
    }
    
    /* If from above we know it's divisible,
     * don't do this inefficient step. But 
     * iff val is more than 5. */
    if (!flag || val < 6) {
        
        /* Check if it's prime. */
        if (isPrime(val)) {
            flag++;
            #ifdef DEBUG_MODE
            printf("%u\n", val);
            #endif
            printBuzzFizz();
        }
    }
    
    /* If none of the above apply, print the value. */
    if (!flag) {
        printf("\n%u\n", val);
    }
    
    //printf("\n");
}

void F(unsigned int n) {
    unsigned int curr  = 0,
                 prev1 = 1,
                 prev2 = 0;
    
    for (int i = 0; i < n; i++) {
        /* Print out the correct string. */
        fizzBuzz(prev2);
        
        /* Update key values in the sequence. */
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
}

int main(void) {
    unsigned int val;
    
    printf("Hello! \nSo you want to have some fun with the Fibonacci? Excellent, excellent. \n\
It's not quite a mandlebrot, but it will do. :)\n\
Enter the number of fibonacci numbers you would like to know (ex. 20): \n");
    scanf("%d", &val);
    printf("\n\n");
    
    /* Give a warning... */
    if (val > 50)
        printf("That might take awhile...(ctrl+c to quit)\n");
    
    F(val);
    printf("\n\n");
    printThankYou();
    
    return 0;
}

/* Typical shenanigans. */
void printThankYou(void) {
    printf(" _____ _                 _                        _\n");
    printf("|_   _| |__   __ _ _ __ | | __  _   _  ___  _   _| |\n");
    printf("  | | | '_ \\ / _` | '_ \\| |/ / | | | |/ _ \\| | | | |\n");
    printf("  | | | | | | (_| | | | |   <  | |_| | (_) | |_| |_|\n");
    printf("  |_| |_| |_|\\__,_|_| |_|_|\\_\\  \\__, |\\___/ \\__,_(_)\n");
    printf("                                |___/\n");
}

void printBuzz(void) {
    printf(" ____\n");
    printf("| __ ) _   _ ________\n");
    printf("|  _ \\| | | |_  /_  /\n");
    printf("| |_) | |_| |/ / / /\n");
    printf("|____/ \\__,_/___/___|\n");
}

void printFizz(void) {
    printf(" _____ _\n");
    printf("|  ___(_)________\n");
    printf("| |_  | |_  /_  /\n");
    printf("|  _| | |/ / / /\n");
    printf("|_|   |_/___/___|\n");
}

void printBuzzFizz(void) {
    printf(" ____                _____ _\n");
    printf("| __ ) _   _ _______|  ___(_)________\n");
    printf("|  _ \\| | | |_  /_  / |_  | |_  /_  /\n");
    printf("| |_) | |_| |/ / / /|  _| | |/ / / /\n");
    printf("|____/ \\__,_/___/___|_|   |_/___/___|\n");
}
