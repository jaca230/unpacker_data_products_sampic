#include "analysis_pipeline/unpacker_sampic/data_products/SampicEventTiming.h"

ClassImp(dataProducts::SampicEventTiming);

namespace dataProducts {

void SampicEventTiming::Print(Option_t* option) const {
    (void)option;
}

void SampicEventTiming::Show() const {
    Print();
}

} // namespace dataProducts
