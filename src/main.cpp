#include <BeUUID.h>

int main()
{
    std::cout << BeUUID::uuidgen() << std::endl;
    std::cout << BeUUID::uuidgen("MYID_") << std::endl;
    std::cout << BeUUID::uuidgen("Test-", 8) << std::endl;
}