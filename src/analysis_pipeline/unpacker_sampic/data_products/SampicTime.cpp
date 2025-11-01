#include "analysis_pipeline/unpacker_sampic/data_products/SampicTime.h"

#include <iostream>

ClassImp(dataProducts::SampicTime);

namespace dataProducts {

SampicTime::SampicTime() = default;
SampicTime::~SampicTime() = default;

void SampicTime::Print(Option_t*) const {
    std::cout << "SampicTime:\n"
              << "  collection_cycle_index: " << time.collection_cycle_index << "\n"
              << "  collection_cycle_timestamp_ns: " << time.collection_cycle_timestamp_ns << "\n"
              << "  udp_time: " << time.udp_time << "\n"
              << "  parse_time: " << time.parse_time << "\n"
              << "  event_time: " << time.event_time << "\n"
              << "  total_time: " << time.total_time << "\n"
              << "  data_processed: " << time.data_processed << "\n"
              << "  data_rate: " << time.data_rate << "\n";
}

void SampicTime::Show() const {
    Print();
}

}  // namespace dataProducts
