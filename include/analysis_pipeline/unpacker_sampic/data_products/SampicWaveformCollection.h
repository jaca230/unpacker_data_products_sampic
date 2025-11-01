#ifndef SAMPICWAVEFORMCOLLECTION_HH
#define SAMPICWAVEFORMCOLLECTION_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include "analysis_pipeline/unpacker_sampic/data_products/SampicWaveform.h"
#include <vector>

namespace dataProducts {

class SampicWaveformCollection : public DataProduct {
public:
    SampicWaveformCollection();
    ~SampicWaveformCollection();

    void AddWaveform(SampicWaveform&& wf);
    void SetWaveforms(std::vector<SampicWaveform>&& new_waveforms);

    void Clear();
    void Print(Option_t* option = "") const override;
    void Show() const override;

    std::vector<SampicWaveform> waveforms;

    ClassDefOverride(SampicWaveformCollection, 1);
};

} // namespace dataProducts

#endif // SAMPICWAVEFORMCOLLECTION_HH
