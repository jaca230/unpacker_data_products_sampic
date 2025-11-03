#include "analysis_pipeline/unpacker_sampic/data_products/SampicTiming.h"

ClassImp(dataProducts::SampicTiming);

namespace dataProducts {

void SampicTiming::Print(Option_t* /*option*/) const {
    std::cout << "=== SampicTiming ===" << std::endl;
    std::cout << "Event-level timing:" << std::endl;
    std::cout << "  Prepare:  " << event_prepare_time_us << " us" << std::endl;
    std::cout << "  Read:     " << event_read_time_us << " us" << std::endl;
    std::cout << "  Decode:   " << event_decode_time_us << " us" << std::endl;
    std::cout << "  Total:    " << event_total_time_us << " us" << std::endl;

    std::cout << "Collector-level timing:" << std::endl;
    std::cout << "  Wait:     " << collector_wait_time_us << " us" << std::endl;
    std::cout << "  Group:    " << collector_group_time_us << " us" << std::endl;
    std::cout << "  Finalize: " << collector_finalize_time_us << " us" << std::endl;
    std::cout << "  Banks:    " << collector_bank_creation_time_us << " us" << std::endl;
    std::cout << "  Total:    " << collector_total_time_us << " us" << std::endl;
}

void SampicTiming::Show() const {
    Print();
}

} // namespace dataProducts
