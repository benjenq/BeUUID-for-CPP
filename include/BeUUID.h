
#ifndef __BEUUID_H__
#define __BEUUID_H__
#include <iostream>

#include <algorithm>

#if defined(_WIN32)
#include <objbase.h>
#elif defined(__linux__) || defined(__APPLE__)
#include <uuid/uuid.h> // uuid-dev installed required for Linux (sudo apt install uuid-dev)
#else
#error "uuid unsupport platform"
#endif

namespace BeUUID
{
        /**
         * @brief Method  to generate UUID string
         * 
         * @param prefix Prefix-string, default = ""
         * @param len Length of generate uuid-string, default = 37
         * @return const std::string - Prefix+uuid string
         */
        const std::string uuidgen(std::string prefix = "", int len = 37)
        {
#if defined(_WIN32)
                char buf[64] = {0};
                GUID guid;

                if (CoCreateGuid(&guid))
                {
                        return std::move(std::string(""));
                }

                sprintf(buf,
                        "%08X-%04X-%04x-%02X%02X-%02X%02X%02X%02X%02X%02X",
                        guid.Data1, guid.Data2, guid.Data3,
                        guid.Data4[0], guid.Data4[1], guid.Data4[2],
                        guid.Data4[3], guid.Data4[4], guid.Data4[5],
                        guid.Data4[6], guid.Data4[7]);
                std::string u_str = std::string(buf);
                std::for_each(u_str.begin(), u_str.end(), [](char &c) { // https://thispointer.com/converting-a-string-to-upper-lower-case-in-c-using-stl-boost-library/
                        c = ::toupper(c);
                });
                u_str = u_str.substr(0, len);
                char result[150];
                std::sprintf(result, "%s%s", prefix.c_str(), u_str.c_str());
                return std::string(result);
#elif defined(__linux__) || defined(__APPLE__)

                uuid_t uuid;
                // generate
                uuid_generate_random(uuid);
                // unparse (to string)
                char uuid_str[64]; // ex. "1b4e28ba-2fa1-11d2-883f-0016d3cca427" + "\0"
                uuid_unparse_upper(uuid, uuid_str);
                std::string u_str = std::string(uuid_str);
                u_str = u_str.substr(0, len);
                char result[150];
                std::sprintf(result, "%s%s", prefix.c_str(), u_str.c_str());
                return std::string(result);
#endif
        }
} // namespace BeUUID

#endif // __BEUUID_H__