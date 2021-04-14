#include "PacketSerializer.h"

PacketSerializer::PacketSerializer() {}
PacketSerializer::~PacketSerializer() {}

/**
 * @brief Returns the total packet size
 */
const unsigned int PacketSerializer::GetPacketSize() {
    if (_data_groups.size() == 0)
        throw "DataGroup array is 0";

    int lastIndex = 0;
    int element = 0;
    for (int i = 0; i < _data_groups.size(); i++) {
        if (lastIndex < _data_groups[i].index) {
            lastIndex = _data_groups[i].index;
            element = i;
        }
    }
    return  lastIndex + _data_groups[element].body.length();
}

/**
 * @brief Returns pointers to all data groups currently stored.
 */
vector<DataGroup *> PacketSerializer::GetDataGroups() {
    vector<DataGroup *> dataGroupPtrs;
    for (int i = 0; i < _data_groups.size(); i++) {
        dataGroupPtrs.push_back(&_data_groups[i]);
    }
    return dataGroupPtrs;
}

/**
 * @brief Adds a datagroup.
 */
void PacketSerializer::AddDataGroup(DataGroup dg) {
    _data_groups.push_back(dg);
}

/**
 * @brief Contructs and adds a datagroup.
 */
void PacketSerializer::AddDataGroup(unsigned int index, string body) {
    DataGroup dg;
    dg.index = index;
    dg.body = body;
    _data_groups.push_back(dg);
}

/**
 * @brief Construct an ordered byte array based on the data group indexes.
 */
void PacketSerializer::GetBytes(char *out) {
    char bytes[GetPacketSize()];
    for (int i = 0; i < _data_groups.size(); i++) {
        for (int j = 0; j < _data_groups[i].body.length(); j++) {
            bytes[_data_groups[i].index+j] = _data_groups[i].body[j];
        }
    }
    strcpy(out, bytes);
}
