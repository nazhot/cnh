#include <stdio.h>

int main( int argc, char *argv[] ) {

    if ( argc == 1 ) {
        printf( "No arguments provided, doing nothing\n" );
        return 0;
    }

    for ( int i = 1; i < argc; ++i ) {
        char *fileName = argv[i];
        printf( "%s\n", fileName );
        char headerFileName[FILENAME_MAX];
        char sourceFileName[FILENAME_MAX];
        char headerDefine[FILENAME_MAX];
        unsigned int charPosition = 0;
        while ( *fileName && charPosition < FILENAME_MAX ) {
            headerFileName[charPosition] = *fileName;
            sourceFileName[charPosition] = *fileName;
            if ( *fileName >= 97 && *fileName <= 122 ) {
                *fileName -= 32;
            }
            headerDefine[charPosition++] = *fileName++;
        }
        headerFileName[charPosition] = '.';
        sourceFileName[charPosition] = '.';
        headerDefine[charPosition++] = '_';
        headerFileName[charPosition] = 'h';
        sourceFileName[charPosition] = 'c';
        headerDefine[charPosition++] = 'H';
        
        FILE *headerFile = fopen( headerFileName, "w" );
        FILE *sourceFile = fopen( sourceFileName, "w" );

        fprintf( headerFile,
                "#ifndef %s\n"
                "#define %s\n\n"
                "#endif", headerDefine, headerDefine );

        fprintf( sourceFile,
                "#include \"%s\"\n"
                "#include <stdio.h>\n"
                "#include <stdlib.h>\n", headerFileName );

        fclose( headerFile );
        fclose( sourceFile );
    }

    return 0;
}
