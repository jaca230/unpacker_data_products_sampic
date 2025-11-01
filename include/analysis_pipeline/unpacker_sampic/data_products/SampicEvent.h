#ifndef SAMPICEVENT_HH
#define SAMPICEVENT_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

#include "analysis_pipeline/unpacker_sampic/data_products/SampicEventHeader.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicPacketCollection.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicEventFooter.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicWaveformCollection.h"

#include <vector>
#include <sstream>
#include <iostream>

namespace dataProducts {

class SampicEvent : public DataProduct {
public:
    SampicEvent();
    ~SampicEvent();

    SampicEventHeader header;
    SampicPacketCollection packets;
    SampicEventFooter footer;
    SampicWaveformCollection waveforms;

    void BuildWaveformsFromPackets();

    void Print(Option_t* option = "") const override;
    void Show() const override;

    ClassDefOverride(SampicEvent,1)
};

} // namespace dataProducts

#endif // SAMPICEVENT_HH
