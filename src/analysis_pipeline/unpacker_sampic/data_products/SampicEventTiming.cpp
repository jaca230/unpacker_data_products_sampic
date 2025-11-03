#include "analysis_pipeline/unpacker_sampic/data_products/SampicEventTiming.h"

ClassImp(dataProducts::SampicEventTiming);

namespace dataProducts {

void SampicEventTiming::Print(Option_t* /*option*/) const {
    std::cout << "=== SampicEventTiming ===" << std::endl;
    std::cout << "  FE timestamp: " << fe_timestamp_ns << " ns" << std::endl;
    std::cout << "  Hits: " << nhits << ", Parents: " << nparents << std::endl;
    std::cout << "  SAMPIC timing sums (us):" << std::endl;
    std::cout << "    Prepare: " << sp_prepare_us_sum << ", Read: " << sp_read_us_sum << std::endl;
    std::cout << "    Decode: " << sp_decode_us_sum << ", Total: " << sp_total_us_sum << std::endl;
    std::cout << "  SAMPIC timing max (us):" << std::endl;
    std::cout << "    Prepare: " << sp_prepare_us_max << ", Read: " << sp_read_us_max << std::endl;
    std::cout << "    Decode: " << sp_decode_us_max << ", Total: " << sp_total_us_max << std::endl;
}

void SampicEventTiming::Show() const {
    Print();
}

} // namespace dataProducts
