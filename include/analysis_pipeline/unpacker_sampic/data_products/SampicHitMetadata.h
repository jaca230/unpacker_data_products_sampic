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
    double physical_cell0_timestamp_ns;
    int32_t sampic_timestamp_a;
    int32_t sampic_timestamp_b;
    uint64_t fpga_timestamp;
    uint64_t trigger_position_mask;
};
#pragma pack(pop)

class SampicHitMetadataData : public TObject {
public:
    double physical_cell0_timestamp_ns = 0.0;
    int32_t sampic_timestamp_a = 0;
    int32_t sampic_timestamp_b = 0;
    uint64_t fpga_timestamp = 0;
    uint64_t trigger_position_mask = 0;

    ClassDefOverride(SampicHitMetadataData, 2)
};

class SampicHitMetadata : public DataProduct {
public:
    std::vector<SampicHitMetadataData> hits;

    ClassDefOverride(SampicHitMetadata, 1)
};

static_assert(sizeof(SampicHitMetadataBankHeader) == 8, "Unexpected SH bank header size");
static_assert(sizeof(SampicHitMetadataRecord) == 32, "Unexpected SH record size");

} // namespace dataProducts

#endif // SAMPICHITMETADATA_HH
