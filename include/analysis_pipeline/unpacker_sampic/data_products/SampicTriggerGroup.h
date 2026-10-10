#ifndef SAMPIC_TRIGGER_GROUP_HH
#define SAMPIC_TRIGGER_GROUP_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

#include <cstdint>

namespace dataProducts {

#pragma pack(push, 1)
struct SampicTriggerGroupRecord {
    uint32_t fpga_trigger_id;
    uint32_t external_trigger_id;
    uint32_t trigger_index_in_sampic_event;
    uint32_t assigned_hits;
    uint32_t ambiguous_hits;
    double trigger_timestamp_ns;
    double hit_reference_timestamp_ns;
};
#pragma pack(pop)

class SampicTriggerGroup : public DataProduct {
public:
    uint32_t fpga_trigger_id = 0;
    uint32_t external_trigger_id = 0;
    uint32_t trigger_index_in_sampic_event = 0;
    uint32_t assigned_hits = 0;
    uint32_t ambiguous_hits = 0;
    double trigger_timestamp_ns = 0.0;
    double hit_reference_timestamp_ns = 0.0;

    ClassDefOverride(SampicTriggerGroup, 1)
};

static_assert(sizeof(SampicTriggerGroupRecord) == 36, "Unexpected SG record size");

} // namespace dataProducts

#endif // SAMPIC_TRIGGER_GROUP_HH
