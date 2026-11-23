#pragma once
#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include <cstdint>
namespace dataProducts {
// Host steady-clock times relative to collection start. Flags: late=1, coalesced=2, final=4.
#pragma pack(push, 1)
struct SampicReadoutTickRecord {
    uint16_t format_version;
    uint16_t record_size;
    uint32_t flags;
    uint64_t first_tick;
    uint64_t ticks_elapsed;
    uint64_t start_ns;
    uint64_t end_ns;
    uint64_t actual_readout_ns;
    uint32_t hit_count;
    uint32_t parent_count;
};
#pragma pack(pop)
static_assert(sizeof(SampicReadoutTickRecord) == 56);
class SampicReadoutTick : public DataProduct {
public:
    uint16_t format_version = 0;
    uint16_t record_size = 0;
    uint32_t flags = 0;
    uint64_t first_tick = 0;
    uint64_t ticks_elapsed = 0;
    uint64_t start_ns = 0;
    uint64_t end_ns = 0;
    uint64_t actual_readout_ns = 0;
    uint32_t hit_count = 0;
    uint32_t parent_count = 0;
    ClassDefOverride(SampicReadoutTick, 1)
};
} // namespace dataProducts
