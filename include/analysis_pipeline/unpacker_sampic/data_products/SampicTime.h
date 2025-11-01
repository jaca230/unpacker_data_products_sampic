#ifndef SAMPICTIME_HH
#define SAMPICTIME_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicTimeData.h"

#include <TObject.h>

namespace dataProducts {

class SampicTime : public DataProduct {
public:
    SampicTime();
    ~SampicTime();

    SampicTimeData time;

    void Print(Option_t* option = "") const override;
    void Show() const override;

    ClassDefOverride(SampicTime, 1);
};

}  // namespace dataProducts

#endif  // SAMPICTIME_HH
