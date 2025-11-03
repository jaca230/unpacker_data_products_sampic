#include "analysis_pipeline/unpacker_sampic/data_products/SampicCollectorTiming.h"

ClassImp(dataProducts::SampicCollectorTiming);

namespace dataProducts {

void SampicCollectorTiming::Print(Option_t* /*option*/) const {
    std::cout << "=== SampicCollectorTiming ===" << std::endl;
    std::cout << "  Collector timestamp: " << collector_timestamp_ns << " ns" << std::endl;
    std::cout << "  Events: " << n_events << ", Total hits: " << total_hits << std::endl;
    std::cout << "  Timing (us):" << std::endl;
    std::cout << "    Wait:     " << wait_us << std::endl;
    std::cout << "    Group:    " << group_build_us << std::endl;
    std::cout << "    Finalize: " << finalize_us << std::endl;
    std::cout << "    Total:    " << total_us << std::endl;
}

void SampicCollectorTiming::Show() const {
    Print();
}

} // namespace dataProducts
