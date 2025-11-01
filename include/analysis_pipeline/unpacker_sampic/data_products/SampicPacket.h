#ifndef SAMPICPACKET_HH
#define SAMPICPACKET_HH

#include <cstdint>
#include <array>
#include <TObject.h>

namespace dataProducts {

#pragma pack(push, 1)
struct SampicPacket {
    // --- Header ---
    uint16_t packet_header;
    uint8_t packet_info;
    uint8_t channel;
    uint32_t trigger_time;
    uint16_t logical_position;
    uint16_t window_position;

    // --- Payload ---
    std::array<uint16_t, 32> trace;

    // --- Footer ---
    uint16_t parser_index;
    uint16_t packet_footer;
};
#pragma pack(pop)

} // namespace dataProducts

#endif // SAMPICPACKET_HH
