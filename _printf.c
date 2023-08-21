#include <stdarg.h>
#include <stdio.h>


int _printf(const char *format, ...) {
    va_list args; /*Liste d'arguments variables */
        va_start(args, format); /*Initialisation de la liste d'arguments*/ 

    int len = 0; /*Variable pour stocker la longueur totale des caractères imprimés*/ 
    const char *ch = format; /*Pointeur pour parcourir le format*/ 

    /* Parcours du format caractère par caractère */ 
    while (*ch != '\0') {
        if (*ch == '%') { /*Si on trouve un '%'*/ 
            ch++; /*Avance d'un caractère pour accéder au format spécifié*/ 
            int len = 0;
            int num = 0; 
            /*Gestion des spécificateurs de format*/
            switch (*ch) {
                case 'd':
                case 'i':
                    /*Gestion du format entier */
                    int num = va_arg(args, int); /*Récupération de l'entier*/ 
                    len += printf("%d", num); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'u':
                    /*Gestion du format entier non signé*/ 
                    unsigned int u_num = va_arg(args, unsigned int); /*Récupération de l'entier non signé*/ 
                    len += printf("%u", u_num); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'o':
                    /*Gestion du format octal non signé*/ 
                    unsigned int octal_num = va_arg(args, unsigned int); /*Récupération de l'entier non signé*/ 
                    len += printf("%o", octal_num); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'x':
                case 'X':
                    /*Gestion du format hexadécimal non signé*/ 
                    unsigned int hex_num = va_arg(args, unsigned int); /*Récupération de l'entier non signé*/ 
                    len += printf((*ch == 'x') ? "%x" : "%X", hex_num); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'c':
                    /*Gestion du format caractère*/ 
                    int character = va_arg(args, int); /*Récupération du caractère*/ 
                    len += printf("%c", character); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 's':
                    /*Gestion du format chaîne de caractères*/ 
                    char *str = va_arg(args, char *); /*Récupération de la chaîne de caractères*/ 
                    len += printf("%s", str); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'p':
                    /*Gestion du format pointeur*/ 
                    void *ptr = va_arg(args, void *); /*Récupération du pointeur*/ 
                    len += printf("%p", ptr); /*Impression et mise à jour de la longueur*/ 
                    break;
                case '%':
                    len += printf("%%"); /*Impression du caractère '%' et mise à jour de la longueur*/ 
                    break;
                default:
                    len += printf("Unknown format specifier"); /*Gestion du spécificateur inconnu*/ 
            }
        } else {
            putchar(*ch); /*Impression du caractère actuel*/ 
            len++; /*Mise à jour de la longueur*/ 
        }
        ch++; /*Passage au caractère suivant dans le format*/ 
    }

    va_end(args); /*Fermeture de la liste d'arguments*/ 
    return len; /*Retourne la longueur totale imprimée*/ 
}

