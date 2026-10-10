#ifndef SAMPICHITMETADATA_HH
#define SAMPICHITMETADATA_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

#include <TObject.h>

#include <cstdint>
#include <vector>

namespace dataProducts {

#pragma pack(push, 1)
struct SampicHitMetadataBankHeader {
    uint16_t version;
    uint16_t record_size;
    uint32_t hit_count;
};

struct SampicHitMetadataRecord {
    uint16_t sampic_data_header;
    int32_t first_trigger_position_cell;
    int32_t trigger_position_cell;
    double physical_cell0_timestamp_ns;
    int32_t sampic_timestamp_a;
    int32_t sampic_timestamp_b;
    uint64_t fpga_timestamp;
    int32_t adc_counter_latched_at_end_of_conversion;
    int32_t start_of_adc_ramp;
    uint64_t trigger_position_mask;
    int32_t time_physical_index;
};
#pragma pack(pop)

class SampicHitMetadataData : public TObject {
public:
    uint16_t sampic_data_header = 0;
    int32_t first_trigger_position_cell = 0;
    int32_t trigger_position_cell = 0;
    double physical_cell0_timestamp_ns = 0.0;
    int32_t sampic_timestamp_a = 0;
    int32_t sampic_timestamp_b = 0;
    uint64_t fpga_timestamp = 0;
    int32_t adc_counter_latched_at_end_of_conversion = 0;
    int32_t start_of_adc_ramp = 0;
    uint64_t trigger_position_mask = 0;
    int32_t time_physical_index = 0;

    ClassDefOverride(SampicHitMetadataData, 1)
};

class SampicHitMetadata : public DataProduct {
public:
    std::vector<SampicHitMetadataData> hits;

    ClassDefOverride(SampicHitMetadata, 1)
};

static_assert(sizeof(SampicHitMetadataBankHeader) == 8, "Unexpected SH bank header size");
static_assert(sizeof(SampicHitMetadataRecord) == 54, "Unexpected SH record size");

} // namespace dataProducts

#endif // SAMPICHITMETADATA_HH
