#include <unistd.h>

int main(int ac, char **av)
{
    char *new = malloc(sizeof(char));

    new[0] = '1';
    write(0, new, sizeof(char));
    return 0;
}