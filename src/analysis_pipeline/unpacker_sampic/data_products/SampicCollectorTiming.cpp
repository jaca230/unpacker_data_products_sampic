#include "analysis_pipeline/unpacker_sampic/data_products/SampicCollectorTiming.h"

ClassImp(dataProducts::SampicCollectorTiming);

namespace dataProducts {

void SampicCollectorTiming::Print(Option_t* option) const {
    (void)option;
}

void SampicCollectorTiming::Show() const {
    Print();
}

} // namespace dataProducts
