#ifndef SAMPICEVENT_HH
#define SAMPICEVENT_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicHit.h"
#include <TObject.h>
#include <vector>
#include <iostream>

namespace dataProducts {

/**
 * @brief TObject container for a single SAMPIC hit with waveform
 */
class SampicHitData : public TObject {
public:
    SampicHitData() = default;
    ~SampicHitData() = default;

    // Hit metadata
    int fe_board_index = 0;
    int channel = 0;
    int hit_number = 0;
    int sampic_index = 0;
    int channel_index = 0;

    // Correction flags
    bool inl_corrected = false;
    bool adc_corrected = false;
    bool residual_pedestal_corrected = false;

    // Cell information
    int cell_info = 0;
    int first_cell_physical_index = 0;

    // Waveform data
    std::vector<float> corrected_waveform;

    // Scalar analysis results
    int raw_tot_value = 0;
    float tot_value = 0.0f;
    float amplitude = 0.0f;
    float baseline = 0.0f;
    float peak = 0.0f;
    float time_index = 0.0f;
    double time_instant = 0.0;
    float time_amplitude = 0.0f;
    double first_cell_timestamp = 0.0;

    void Print(Option_t* option = "") const override;
    void Show() const;

    ClassDefOverride(SampicHitData, 1)
};

/**
 * @brief Top-level SAMPIC event container
 */
class SampicEvent : public DataProduct {
public:
    SampicEvent() = default;
    ~SampicEvent() = default;

    // Collection of hits in this event
    std::vector<SampicHitData> hits;

    // Event-level timing information (optional, from AT banks)
    double event_prepare_time_us = 0.0;
    double event_read_time_us = 0.0;
    double event_decode_time_us = 0.0;
    double event_total_time_us = 0.0;

    // Collector-level timing information (optional, from AC banks)
    double collector_wait_time_us = 0.0;
    double collector_group_time_us = 0.0;
    double collector_finalize_time_us = 0.0;
    double collector_bank_creation_time_us = 0.0;
    double collector_total_time_us = 0.0;

    void Print(Option_t* option = "") const override;
    void Show() const;

    ClassDefOverride(SampicEvent, 1)
};

} // namespace dataProducts

#endif // SAMPICEVENT_HH
