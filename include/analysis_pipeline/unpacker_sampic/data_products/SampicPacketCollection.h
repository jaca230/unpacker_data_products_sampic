#ifndef SAMPICPACKETCOLLECTION_HH
#define SAMPICPACKETCOLLECTION_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicPacket.h"
#include <TObject.h>
#include <vector>
#include <iostream>

namespace dataProducts {

class SampicPacketCollection : public DataProduct {
public:
    SampicPacketCollection() = default;
    ~SampicPacketCollection() = default;

    void AddPacket(SampicPacket&& pkt);
    void SetPackets(std::vector<SampicPacket>&& new_packets);

    void Clear();
    void Print(Option_t* option = "") const override;
    void Show() const override;

    // Exposed directly, no getter
    std::vector<SampicPacket> packets;

    ClassDefOverride(SampicPacketCollection, 1);
};

} // namespace dataProducts

#endif // SAMPICPACKETCOLLECTION_HH
