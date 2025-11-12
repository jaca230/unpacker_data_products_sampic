#ifndef SAMPICEVENTTIMING_HH
#define SAMPICEVENTTIMING_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include <TObject.h>
#include <cstdint>

namespace dataProducts {

/**
 * @brief Binary format for event timing banks (e.g., AT banks)
 *
 * Structure written by FrontendEventBankEventTiming in SAMPIC DAQ
 */
#pragma pack(push, 1)
struct SampicEventTimingRecord {
    uint64_t fe_timestamp_ns;      // Frontend event timestamp
    uint32_t nhits;                // Number of hits in event
    uint32_t nparents;             // Number of parent SAMPIC events
    uint32_t sp_prepare_us_sum;    // Sum of SAMPIC prepare times
    uint32_t sp_read_us_sum;       // Sum of SAMPIC read times
    uint32_t sp_decode_us_sum;     // Sum of SAMPIC decode times
    uint32_t sp_total_us_sum;      // Sum of SAMPIC total times
    uint32_t sp_prepare_us_max;    // Max SAMPIC prepare time
    uint32_t sp_read_us_max;       // Max SAMPIC read time
    uint32_t sp_decode_us_max;     // Max SAMPIC decode time
    uint32_t sp_total_us_max;      // Max SAMPIC total time
    uint32_t sp_acq_retry_max;     // Max acquisition retries
    uint32_t sp_acq_retry_sum;     // Sum of acquisition retries
};
#pragma pack(pop)

/**
 * @brief Event-level timing data for SAMPIC processing
 *
 * Contains timing information from the event-level processing (AT banks).
 * This is diagnostic data separate from physics data.
 */
class SampicEventTiming : public DataProduct {
public:
    SampicEventTiming() = default;
    ~SampicEventTiming() = default;

    // Frontend event metadata
    uint64_t fe_timestamp_ns = 0;
    uint32_t nhits = 0;
    uint32_t nparents = 0;

    // SAMPIC timing sums (microseconds)
    uint32_t sp_prepare_us_sum = 0;
    uint32_t sp_read_us_sum = 0;
    uint32_t sp_decode_us_sum = 0;
    uint32_t sp_total_us_sum = 0;

    // SAMPIC timing maxima (microseconds)
    uint32_t sp_prepare_us_max = 0;
    uint32_t sp_read_us_max = 0;
    uint32_t sp_decode_us_max = 0;
    uint32_t sp_total_us_max = 0;

    // Acquisition retry stats
    uint32_t sp_acq_retry_max = 0;
    uint32_t sp_acq_retry_sum = 0;

    void Print(Option_t* option = "") const override;
    void Show() const;

    ClassDefOverride(SampicEventTiming, 2)
};

} // namespace dataProducts

#endif // SAMPICEVENTTIMING_HH
