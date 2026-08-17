Lexical Analyzer – Token Counter Theory
Aim
To develop a program that reads a source-code file and performs lexical analysis by identifying and counting different types of tokens.
Theory
A lexical analyzer is the first phase of a compiler. It reads the source program character by character and groups the characters into meaningful units called tokens.
A token is the smallest meaningful element of a program. The lexical analyzer removes unnecessary white spaces and identifies different types of tokens such as keywords, identifiers, operators, constants, strings, and separators.
For example, consider:
int a = 10;
The tokens are:
int → Keyword
a → Identifier
= → Operator
10 → Constant/Number
; → Separator
