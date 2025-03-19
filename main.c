#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#include "resource.h"
#endif

int main(int argc, char **argv) {
#ifdef _WIN32
  HRSRC handle = FindResource(NULL, MAKEINTRESOURCE(TEST_RESOURCE_ID), RT_RCDATA);
  if (!handle) {
    printf("resource not found\n");
    return 1;
  }
  HGLOBAL res = LoadResource(NULL, handle);
  if (!res) {
    printf("resource could not be loaded\n");
    return 1;
  }
  LPVOID data = LockResource(res);
  if (!data) {
    printf("could not lock resource\n");
    return 1;
  }
  DWORD size = SizeofResource(NULL, handle);
  printf("%.*s", (int)size, (char*)data);
  return 0;
#else
  printf("not windows\n");
  return 1;
#endif
}
