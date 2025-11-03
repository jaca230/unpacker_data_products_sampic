#ifndef SAMPICTIMING_HH
#define SAMPICTIMING_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include <TObject.h>
#include <iostream>

namespace dataProducts {

/**
 * @brief Diagnostic timing data for SAMPIC event processing
 *
 * Contains timing information from both the event-level processing (AT banks)
 * and the collector-level processing (AC banks). This is diagnostic data
 * separate from the physics data.
 */
class SampicTiming : public DataProduct {
public:
    SampicTiming() = default;
    ~SampicTiming() = default;

    // Event-level timing information (from AT banks)
    double event_prepare_time_us = 0.0;
    double event_read_time_us = 0.0;
    double event_decode_time_us = 0.0;
    double event_total_time_us = 0.0;

    // Collector-level timing information (from AC banks)
    double collector_wait_time_us = 0.0;
    double collector_group_time_us = 0.0;
    double collector_finalize_time_us = 0.0;
    double collector_bank_creation_time_us = 0.0;
    double collector_total_time_us = 0.0;

    void Print(Option_t* option = "") const override;
    void Show() const;

    ClassDefOverride(SampicTiming, 1)
};

} // namespace dataProducts

#endif // SAMPICTIMING_HH
