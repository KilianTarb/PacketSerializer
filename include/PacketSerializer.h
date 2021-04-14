#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "Types.h"
#include <algorithm>

class PacketSerializer
{
    private:
        vector<DataGroup> _data_groups;
        
    public:
        PacketSerializer();
        ~PacketSerializer();

        vector<DataGroup *> GetDataGroups();
        const unsigned int GetPacketSize();
        void AddDataGroup(DataGroup dg);
        void AddDataGroup(unsigned int index, size_t size, char *body);
        void AddDataGroup(unsigned int index, char *body);
        void GetBytes(char *out);
};