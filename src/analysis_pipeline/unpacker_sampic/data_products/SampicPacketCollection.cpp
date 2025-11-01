#include "analysis_pipeline/unpacker_sampic/data_products/SampicPacketCollection.h"

ClassImp(dataProducts::SampicPacketCollection)

namespace dataProducts {

void SampicPacketCollection::AddPacket(SampicPacket&& pkt) {
    packets.emplace_back(std::move(pkt));
}

void SampicPacketCollection::SetPackets(std::vector<SampicPacket>&& new_packets) {
    packets = std::move(new_packets);
}

void SampicPacketCollection::Clear() {
    packets.clear();
}

void SampicPacketCollection::Print(Option_t*) const {
    std::cout << "SampicPacketCollection with " << packets.size() << " packet(s)" << std::endl;
}

void SampicPacketCollection::Show() const {
    Print();
}

} // namespace dataProducts
