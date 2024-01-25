#include <stdio.h>
#include <stdlib.h>


int main( int argc, char *argv[] ) {

    if ( argc == 1 ) {
        printf( "No arguments provided, doing nothing\n" );
        return 0;
    }

    for ( int i = 1; i < argc; ++i ) {
        char *fileName = argv[i];
        printf( "%s\n", fileName );
        char headerFileName[256];
        char sourceFileName[256];
        unsigned int charPosition = 0;
        while ( *fileName ) {
            headerFileName[charPosition] = *fileName;
            sourceFileName[charPosition++] = *fileName;
            fileName++;
        }
        headerFileName[charPosition] = '.';
        sourceFileName[charPosition++] = '.';
        headerFileName[charPosition] = 'h';
        sourceFileName[charPosition++] = 'c';
        
        FILE *headerFile = fopen( headerFileName, "w" );
        FILE *sourceFile = fopen( sourceFileName, "w" );
    }

    return 0;
}
