#include "main.h"

int main(int argc, char *argv[])
{
    (void)argv;  // Unused parameter, casting to void to avoid warning
    printf("%d\n", argc - 1);  // Subtract 1 to exclude the program name argument
    return 0;
}
