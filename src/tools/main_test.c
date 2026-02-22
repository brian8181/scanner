#include <stdio.h>
#include "mylibrary.h"

int main(int argc, char** argv)
{
    create_logger();
    log_message_c("loggin msg in 'c'");
    destroy_logger();
    return 0;
}
