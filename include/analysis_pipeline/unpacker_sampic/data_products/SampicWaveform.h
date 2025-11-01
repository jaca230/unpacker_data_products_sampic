#ifndef SAMPICWAVEFORM_HH 
#define SAMPICWAVEFORM_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicPacket.h"

#include <vector>
#include <string>

namespace dataProducts {

class SampicWaveform : public DataProduct {
public:
    SampicWaveform();
    ~SampicWaveform();

    void buildFromPackets(const std::vector<const SampicPacket*>& packets);

    uint64_t channel_num = 0;
    std::vector<short> trace;

    // New member: samples per packet, default 32
    size_t samples_per_packet = 32;

    void Print(Option_t* option = "") const override;
    void Show() const override;

    ClassDefOverride(SampicWaveform, 1)
};


} // namespace dataProducts

#endif // SAMPICWAVEFORM_HH
