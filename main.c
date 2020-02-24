#include <stdio.h>
#include <stdlib.h>

void help()
{
    printf("<program.exe> -i <input-file> -o <output-file>\n");
    printf("-> <program.exe> -- path to this program\n");
    printf("-> <input-file> -- path to text file for processing\n");
    printf("-> <output-file> --path to text file for storing results\n");
}
void fastSwap (char **i,char **d)
{
    char *t = *d;
    *d = *i;
    *i = t;
}

int main(int argc,char **argv)
{
    if (argc < 5 ||(argv[1][0] =='-' && argv[1][1] == 'h' && argv[1][2] == '\0' )|| argc > 5) //checks if there is -h or if there are too many/not enough arguments
    {
        help();
    }
    else if (argc == 5 )
    {
        if(argv[1][0] != '-'&& argv[1][1] != 'i' && argv[1][2] != '\0' && argv[3][0] != '-' && argv[3][1] != 'o' && argv[3][2] != '\0') // checks if there is proper order of arguments
        {
            printf("Wrong parameters. Check help");
            help();
        }
        else if( (argv[1][0] == '-'&& argv[1][1] == 'o' && argv[1][2] == '\0' && argv[3][0] == '-' && argv[3][1] == 'i' && argv[3][2] == '\0')) // is i/o swapped
        {
            printf("It looks like you have swapped input with output. \nDon't worry, your program will still work!\n");

            fastSwap(&argv[2],&argv[4]);
            argv[1][1]= 'i';
            argv[3][1]= 'o';
        }

        int c = 0 ;
        int stan = 0; //
        int cn=0; // temporary symbols in line
        int lines = 0;
        int allsymbols = -1;
        int allwords = 0;
        int word = 0 ; // temporary words in line

        FILE* input;
        input = fopen(argv[2],"r");
        FILE* output;
        output = fopen(argv[4],"w");
        if (input!=NULL)
        {
            if (output!=NULL)
            {
                while(!feof(input))
                {

                    allsymbols++;
                    c = fgetc(input);
                    cn++;


                    if(stan==0 && ((c>='a' && c<='z') || (c>='A' && c<='Z'))) //if counter meets first letter
                    {
                        stan=1;
                        allwords++;
                        word++;
                    }

                    if(stan==1 && (!((c>='a' && c<='z') || (c>='A' && c<='Z'))))
                    {
                        stan=0;
                    }
                    if(c=='\n'||c=='\r'||c=='\r\n')
                    {

                        lines++;

                        fprintf(output,"Number of symbols in line %d : %d\n",lines,cn);
                        fprintf(output,"Number of words in line %d : %d\n",lines,word);
                        printf("Number of symbols in line %d : %d\nNumber of words in line %d : %d \n",lines,(cn-1), lines, word);
                        cn=0;
                        word = 0;
                    }

                }
                lines++;
                printf("Number of symbols in line %d : %d\nNumber of words in line %d : %d \n",lines,(cn-1), lines, word);
                fprintf(output,"Number of symbols in line %d : %d\n",lines,cn);
                fprintf(output,"Number of words in line %d : %d\n",lines,word);
                cn=0;
                word=0;


                fprintf(output,"All Lines: %d \nAll symbols: %d \nAll words: %d", lines, allsymbols, allwords );

                printf("Lines : %d \n", lines);
                printf("All symbols: %d \n", allsymbols);
                printf("All words: %d \n", allwords);

                fclose(output);
                fclose(input);

            }
            else
            {
                printf("Couldn't open an output file!\n");
            }
        }
        else
        {
            printf("Couldn't open an input file!\n");
        }



    }




    return 0;


}
