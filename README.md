# C++ UUID Generator (BeUUID::uuidgen)<br>
UUID sring generator for C++. Test passed on Linux / macOS / [MinGW-w64](http://mingw-w64.org/) in Windows (7/10 x64)

### Feature:
- Generate a UUID string with prefix and UUID-length parameter. Super easy to use and works on Linux & macOS & MinGW-w64 on Windows.

### How to use ?
- Just `#include <BeUUID.h>` and coding `BeUUID::uuidgen`. Super easy.

### Notice : 
Different `CXX_FLAGS` for each supported OS platform :

- MinGW on Windows : `-lole32`.
- macOS : none.
- Linux : `-luuid` with uuid-dev installed. ( $ sudo apt install uuid-dev)

See [Makefile](Makefile) for more detail.


### Sample Code:
```cpp
#include <BeUUID.h>

int main()
{
    std::cout << BeUUID::uuidgen() << std::endl;
    std::cout << BeUUID::uuidgen("MYID_") << std::endl;
    std::cout << BeUUID::uuidgen("Test-", 8) << std::endl;
}
```
Console output (sample):
```
C5DF2550-EBE4-41F2-813D-49495E571E0B
MYID_DF9A5421-BE24-49E0-BD17-FF74D0A806E0
Test-E7E4D7D5
```




