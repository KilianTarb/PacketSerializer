#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <vector>
#include "Types.h"

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
        void AddDataGroup(unsigned int index, string body);
        void GetBytes(char *out);
};