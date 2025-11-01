#include "analysis_pipeline/unpacker_sampic/data_products/SampicEvent.h"
#include <iostream>

ClassImp(dataProducts::SampicHitData);
ClassImp(dataProducts::SampicEvent);

using namespace dataProducts;

void SampicHitData::Print(Option_t* option) const {
    std::cout << "SampicHitData:\n";
    std::cout << "  FE Board: " << fe_board_index << ", Channel: " << channel << "\n";
    std::cout << "  Hit Number: " << hit_number << ", SAMPIC: " << sampic_index << "\n";
    std::cout << "  Waveform samples: " << corrected_waveform.size() << "\n";
    std::cout << "  Amplitude: " << amplitude << ", Baseline: " << baseline << "\n";
    std::cout << "  Time instant: " << time_instant << " ns\n";

    if (std::string(option) == "full" && !corrected_waveform.size()) {
        std::cout << "  First 10 samples: ";
        for (size_t i = 0; i < std::min(size_t(10), corrected_waveform.size()); ++i) {
            std::cout << corrected_waveform[i] << " ";
        }
        std::cout << "\n";
    }
}

void SampicHitData::Show() const {
    Print();
}

void SampicEvent::Print(Option_t* option) const {
    std::cout << "SampicEvent Summary:\n";
    std::cout << "  Number of hits: " << hits.size() << "\n";

    if (event_total_time_us > 0) {
        std::cout << "  Event timing (us): prepare=" << event_prepare_time_us
                  << ", read=" << event_read_time_us
                  << ", decode=" << event_decode_time_us
                  << ", total=" << event_total_time_us << "\n";
    }

    if (collector_total_time_us > 0) {
        std::cout << "  Collector timing (us): wait=" << collector_wait_time_us
                  << ", group=" << collector_group_time_us
                  << ", finalize=" << collector_finalize_time_us
                  << ", total=" << collector_total_time_us << "\n";
    }

    if (std::string(option) == "full") {
        for (size_t i = 0; i < hits.size(); ++i) {
            std::cout << "\n  Hit " << i << ":\n";
            hits[i].Print();
        }
    }
}

void SampicEvent::Show() const {
    Print();
}

