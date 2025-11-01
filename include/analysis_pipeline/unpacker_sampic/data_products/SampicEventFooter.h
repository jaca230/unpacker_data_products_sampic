#ifndef SAMPICEVENTFOOTER_HH
#define SAMPICEVENTFOOTER_HH

#include <cstdint>

namespace dataProducts {

#pragma pack(push, 1)
struct SampicEventFooter {
    uint16_t event_footer;
};
#pragma pack(pop)

} // namespace dataProducts

#endif // SAMPICEVENTFOOTER_HH
