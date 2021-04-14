#include "stdlib.h"
#include "string"

using namespace std;

struct DataGroup {
    unsigned int index;
    size_t size;
    char *body;
};