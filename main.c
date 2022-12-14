#include "lib/fetch.h"
#include "lib/function.h"

void account (void);
void accountcreated (void);
void login(void);
void loginsu (void);
void logout (void);
void registermenu(void);
void mainmenu(void);
void welcoming (void);

int main() {
    welcoming();
    registermenu();
    return 0;
}