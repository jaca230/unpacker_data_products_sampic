#pragma once
#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicEvent.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicHitMetadata.h"
#include <cstdint>
#include <vector>
namespace dataProducts {
// BD00 version 4: source crate plus the same corrected SD and advanced SH data.
struct SampicBuilderHit {
    std::uint16_t crate = 0;
    SampicHitData data;
    SampicHitMetadataData metadata;
};
class SampicBuilderEvent : public DataProduct {
public:
    // Collection bounds: hardware grouping keys or host-relative periodic times.
    std::uint64_t start_ns = 0, end_ns = 0;
    std::vector<SampicBuilderHit> hits;
    ClassDefOverride(SampicBuilderEvent, 2);
};
} // namespace dataProducts
