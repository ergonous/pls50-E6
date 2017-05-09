#include <stdio.h>

struct Items
{
    char code[10];
    char description[30];
    int stock;
};

void ReadFile(struct Items items[], size_t len)
{
    /* Do the reading... eg. */
    items[0].stock = 10;
    printf("%d", items[0].stock);
}

int main(void)
{
    struct Items MyItems[10];

    ReadFile(MyItems, sizeof(MyItems) / sizeof(*MyItems));

    return 0;
}
