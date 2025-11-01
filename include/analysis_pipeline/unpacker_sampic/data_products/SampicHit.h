#ifndef SAMPICHIT_HH
#define SAMPICHIT_HH

#include <cstdint>
#include <TObject.h>

namespace dataProducts {

// Maximum number of samples in SAMPIC waveform
constexpr int MAX_SAMPIC_SAMPLES = 64;

/**
 * @brief Binary structure matching SAMPIC HitStruct header
 * This is the data written to AD banks (header + CorrectedDataSamples + scalars)
 */
#pragma pack(push, 1)
struct SampicHitHeader {
    int32_t fe_board_index;
    int32_t channel;  // 0 to 63
    int32_t hit_number;
    int32_t sampic_index;
    int32_t channel_index;
    int32_t data_size;  // Number of samples

    // Correction flags
    int32_t inl_corrected;
    int32_t adc_corrected;
    int32_t residual_pedestal_corrected;

    // Cell information
    int32_t cell_info;
    int32_t first_cell_physical_index;
};

struct SampicHitScalars {
    int32_t raw_tot_value;  // ADC Count
    float tot_value;  // ns

    float amplitude;
    float baseline;
    float peak;

    float time_index;
    double time_instant;  // ns
    float time_amplitude;
    double first_cell_timestamp;  // ns
};
#pragma pack(pop)

} // namespace dataProducts

#endif // SAMPICHIT_HH
