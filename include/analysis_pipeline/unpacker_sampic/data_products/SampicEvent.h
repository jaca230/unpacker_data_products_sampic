#ifndef SAMPICEVENT_HH
#define SAMPICEVENT_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicHit.h"
#include <TObject.h>
#include <vector>

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
    // Preserve all compact SD flags, including waveform/TOT quality flags.
    uint8_t flags = 0;
    bool waveform_clipped = false;
    bool waveform_nonfinite = false;
    bool raw_tot_clipped = false;

    // Cell information
    int cell_info = 0;
    int first_cell_physical_index = 0;

    // Exact signed wire values. ADC-corrected samples use 0.1 mV/count;
    // otherwise these are rounded ADC counts.
    std::vector<int16_t> encoded_waveform;
    // Volts when adc_corrected, otherwise ADC counts.
    std::vector<float> corrected_waveform;

    // Scalar analysis results
    int raw_tot_value = 0;
    float tot_value = 0.0f;
    double first_cell_timestamp = 0.0;

    void Print(Option_t* option = "") const override;
    void Show() const;

    ClassDefOverride(SampicHitData, 2)
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

    void Print(Option_t* option = "") const override;
    void Show() const;

    ClassDefOverride(SampicEvent, 1)
};

} // namespace dataProducts

#endif // SAMPICEVENT_HH
