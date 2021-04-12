#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "Types.h"

class PacketSerializer
{
    private:
        vector<DataGroup> _data_groups;
        const unsigned int _calculdatePacketSize();
        
    public:
        PacketSerializer();
        ~PacketSerializer();

        vector<DataGroup *> GetDataGroups();
        void AddDataGroup(DataGroup dg);
        void AddDataGroup(unsigned int index, string body);
        char *GetBytes();
};