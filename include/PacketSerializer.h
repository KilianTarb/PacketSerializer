#include <stdlib.h>
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
        void AddDataGroup(DataGroup dg);
        void AddDataGroup(unsigned int index, string body, size_t len);
        vector<unsigned char *> GetBytes();
};