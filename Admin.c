#include <stdio.h>
#include <string.h>
#include "admin.h"

unsigned int adminLogin(const Admin *admin)
{
    if (strcmp(admin->username, "sufian") == 0 &&
        strcmp(admin->password, "123") == 0)
    {
        return 1;
    }

    return 0;
}
