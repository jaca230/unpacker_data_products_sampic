#ifndef SAMPICCOLLECTORTIMING_HH
#define SAMPICCOLLECTORTIMING_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include <TObject.h>
#include <iostream>
#include <cstdint>

namespace dataProducts {

/**
 * @brief Binary format for collector timing banks (e.g., AC banks)
 *
 * Structure written by FrontendEventBankCollectorTiming in SAMPIC DAQ
 */
#pragma pack(push, 1)
struct SampicCollectorTimingRecord {
    uint64_t collector_timestamp_ns;  // Collection cycle start timestamp
    uint32_t n_events;                // Number of frontend events emitted
    uint32_t total_hits;              // Total hits across all events
    uint32_t wait_us;                 // Wait duration
    uint32_t group_build_us;          // Grouping phase duration
    uint32_t finalize_us;             // Finalization duration
    uint32_t total_us;                // Total collection time
};
#pragma pack(pop)

/**
 * @brief Collector-level timing data for SAMPIC processing
 *
 * Contains timing information from the collector-level processing (AC banks).
 * This is diagnostic data separate from physics data.
 * Note: AC banks may not be present in every event.
 */
class SampicCollectorTiming : public DataProduct {
public:
    SampicCollectorTiming() = default;
    ~SampicCollectorTiming() = default;

    // Collection cycle metadata
    uint64_t collector_timestamp_ns = 0;
    uint32_t n_events = 0;
    uint32_t total_hits = 0;

    // Collector timing information (microseconds)
    uint32_t wait_us = 0;
    uint32_t group_build_us = 0;
    uint32_t finalize_us = 0;
    uint32_t total_us = 0;

    void Print(Option_t* option = "") const override;
    void Show() const;

    ClassDefOverride(SampicCollectorTiming, 1)
};

} // namespace dataProducts

#endif // SAMPICCOLLECTORTIMING_HH
