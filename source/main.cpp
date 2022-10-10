#include"init.hpp"
#include"load_media.hpp"
#include"coreloop.hpp"

int main()
{
    init();

    load_media();

    loop();

    free_media();

    close();
    
    return 0;
}