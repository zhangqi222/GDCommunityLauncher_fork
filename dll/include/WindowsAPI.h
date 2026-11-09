#ifndef INC_GDCL_DLL_WINDOWS_API_H
#define INC_GDCL_DLL_WINDOWS_API_H

namespace WindowsAPI
{
constexpr char WAPI_NAME_DELETE_FILE[] = "DeleteFileA";
constexpr char WAPI_NAME_DESTROY_WINDOW[] = "DestroyWindow";
}

constexpr char KERNEL_DLL[] = "KERNEL32.dll";
constexpr char USER_DLL[] = "USER32.dll";

#endif//INC_GDCL_DLL_WINDOWS_API_H