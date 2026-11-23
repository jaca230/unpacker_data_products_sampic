#pragma once
#include <cstdint>

namespace dataProducts {
constexpr int MAX_SAMPIC_SAMPLES = 64;
// Current compact SD wire format, little endian. Not the vendor HitStruct.
#pragma pack(push, 1)
struct SampicHitBankHeader {
    char magic[4]; // SDC1
    uint16_t version;
    uint16_t record_size;
    uint32_t hit_count;
};
struct SampicHitRecord {
    uint8_t fe_board_index;
    uint8_t channel;
    int32_t hit_number;
    uint8_t sampic_index;
    uint8_t channel_index;
    uint8_t waveform_size;
    uint8_t flags;
    uint8_t cell_info;
    uint8_t first_cell_physical_index;
    int16_t waveform[64];
    uint16_t raw_tot_value;
    float tot_value;
    double first_cell_timestamp;
};
#pragma pack(pop)
static_assert(sizeof(SampicHitBankHeader) == 12);
static_assert(sizeof(SampicHitRecord) == 154);
} // namespace dataProducts
