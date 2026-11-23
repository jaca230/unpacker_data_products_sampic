#pragma once
#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include <cstdint>
namespace dataProducts {
// Hardware timestamp domain; end_ns is exclusive.
#pragma pack(push, 1)
struct SampicTimeBinRecord {
    uint16_t format_version;
    uint16_t record_size;
    uint32_t hit_count;
    int64_t bin_index;
    double start_ns;
    double end_ns;
};
#pragma pack(pop)
static_assert(sizeof(SampicTimeBinRecord) == 32);
class SampicTimeBin : public DataProduct {
public:
    uint16_t format_version = 0;
    uint16_t record_size = 0;
    uint32_t hit_count = 0;
    int64_t bin_index = 0;
    double start_ns = 0;
    double end_ns = 0;
    ClassDefOverride(SampicTimeBin, 1)
};
} // namespace dataProducts
