%%
[0-9]+  printf("?");
#       return 0;
[a-z]       ECHO;
%%

int main(int argc, char* argv[]) {
    yylex();
    return 0;
}

int yywrap() { 
    return 1;
}