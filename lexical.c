#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch, token[100];
    int i;

    int keywords = 0;
    int identifiers = 0;
    int numbers = 0;
    int operators = 0;
    int separators = 0;
    int strings = 0;

    fp = fopen("input.c", "r");

    if (fp == NULL)
    {
        printf("Unable to open source file.\n");
        return 1;
    }

    printf("Tokens found in the source file:\n\n");

    while ((ch = fgetc(fp)) != EOF)
    {
        /* Ignore white spaces */
        if (isspace(ch))
            continue;

        /* Identifier or Keyword */
        if (isalpha(ch) || ch == '_')
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF &&
                   (isalnum(ch) || ch == '_'))
            {
                token[i++] = ch;
            }

            token[i] = '\0';

            if (strcmp(token, "int") == 0 ||
                strcmp(token, "float") == 0 ||
                strcmp(token, "char") == 0 ||
                strcmp(token, "double") == 0 ||
                strcmp(token, "if") == 0 ||
                strcmp(token, "else") == 0 ||
                strcmp(token, "for") == 0 ||
                strcmp(token, "while") == 0 ||
                strcmp(token, "return") == 0 ||
                strcmp(token, "void") == 0)
            {
                printf("Keyword     : %s\n", token);
                keywords++;
            }
            else
            {
                printf("Identifier  : %s\n", token);
                identifiers++;
            }

            if (ch != EOF)
                ungetc(ch, fp);
        }

        /* Number */
        else if (isdigit(ch))
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF && isdigit(ch))
            {
                token[i++] = ch;
            }

            token[i] = '\0';

            printf("Number      : %s\n", token);
            numbers++;

            if (ch != EOF)
                ungetc(ch, fp);
        }

        /* String */
        else if (ch == '"')
        {
            i = 0;
            token[i++] = ch;

            while ((ch = fgetc(fp)) != EOF && ch != '"')
            {
                token[i++] = ch;
            }

            if (ch == '"')
                token[i++] = ch;

            token[i] = '\0';

            printf("String      : %s\n", token);
            strings++;
        }

        /* Operators */
        else if (ch == '+' || ch == '-' || ch == '*' ||
                 ch == '/' || ch == '=' || ch == '<' ||
                 ch == '>' || ch == '%' || ch == '!')
        {
            printf("Operator    : %c\n", ch);
            operators++;
        }

        /* Separators */
        else if (ch == ';' || ch == ',' || ch == '(' ||
                 ch == ')' || ch == '{' || ch == '}' ||
                 ch == '[' || ch == ']')
        {
            printf("Separator   : %c\n", ch);
            separators++;
        }
    }

    fclose(fp);

    printf("\n--- Token Count ---\n");
    printf("Keywords     : %d\n", keywords);
    printf("Identifiers  : %d\n", identifiers);
    printf("Numbers      : %d\n", numbers);
    printf("Operators    : %d\n", operators);
    printf("Separators   : %d\n", separators);
    printf("Strings      : %d\n", strings);

    return 0;
}
