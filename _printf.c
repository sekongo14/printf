#include <stdarg.h>
#include <stdio.h>


int _printf(const char *format, ...) {
    int len = 0;
    const char *ch = format;
    int num = 0;
    unsigned int u_num = 0;
    unsigned int octal_num = 0;
    unsigned int hex_num = 0;
    char *str = NULL;
    void *ptr = NULL;
    int character = 0;
    va_list args; /*Liste d'arguments variables */
    va_start(args, format); /*Initialisation de la liste d'arguments*/ 

    
    /* Parcours du format caractère par caractère */ 
    while (*ch != '\0') {
        if (*ch == '%') { /*Si on trouve un '%'*/ 
            ch++; /*Avance d'un caractère pour accéder au format spécifié*/ 
            
            /*Gestion des spécificateurs de format*/
            switch (*ch) {
                case 'd':
                case 'i':
                    /*Gestion du format entier */
                    num = va_arg(args, int); /*Récupération de l'entier*/ 
                    len += printf("%d", num); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'u':
                    /*Gestion du format entier non signé*/ 
                    u_num = va_arg(args, unsigned int); /*Récupération de l'entier non signé*/ 
                    len += printf("%u", u_num); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'o':
                    /*Gestion du format octal non signé*/ 
                    octal_num = va_arg(args, unsigned int); /*Récupération de l'entier non signé*/ 
                    len += printf("%o", octal_num); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'x':
                case 'X':
                    /*Gestion du format hexadécimal non signé*/ 
                    hex_num = va_arg(args, unsigned int); /*Récupération de l'entier non signé*/ 
                    len += printf((*ch == 'x') ? "%x" : "%X", hex_num); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'c':
                    /*Gestion du format caractère*/ 
                    character = va_arg(args, int); /*Récupération du caractère*/ 
                    len += printf("%c", character); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 's':
                    /*Gestion du format chaîne de caractères*/ 
                    str = va_arg(args, char *); /*Récupération de la chaîne de caractères*/ 
                    len += printf("%s", str); /*Impression et mise à jour de la longueur*/ 
                    break;
                case 'p':
                    /*Gestion du format pointeur*/ 
                    ptr = va_arg(args, void *); /*Récupération du pointeur*/ 
                    len += printf("%p", ptr); /*Impression et mise à jour de la longueur*/ 
                    break;
                case '%':
                    len += printf("%%"); /*Impression du caractère '%' et mise à jour de la longueur*/ 
                    break;
                default:
                    len += printf("%r"); /*Gestion du spécificateur inconnu*/ 
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

