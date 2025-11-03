#include "analysis_pipeline/unpacker_sampic/data_products/SampicEvent.h"
ClassImp(dataProducts::SampicHitData);
ClassImp(dataProducts::SampicEvent);

using namespace dataProducts;

void SampicHitData::Print(Option_t* option) const {
    (void)option;
}

void SampicHitData::Show() const {
    Print();
}

void SampicEvent::Print(Option_t* option) const {
    (void)option;
}

void SampicEvent::Show() const {
    Print();
}
