#include "analysis_pipeline/unpacker_sampic/data_products/SampicWaveformCollection.h"
#include <iostream>

ClassImp(dataProducts::SampicWaveformCollection)

namespace dataProducts {

SampicWaveformCollection::SampicWaveformCollection() = default;
SampicWaveformCollection::~SampicWaveformCollection() = default;

void SampicWaveformCollection::AddWaveform(SampicWaveform&& wf) {
    waveforms.emplace_back(std::move(wf));
}

void SampicWaveformCollection::SetWaveforms(std::vector<SampicWaveform>&& new_waveforms) {
    waveforms = std::move(new_waveforms);
}

void SampicWaveformCollection::Clear() {
    waveforms.clear();
}

void SampicWaveformCollection::Print(Option_t*) const {
    std::cout << "SampicWaveformCollection with " << waveforms.size() << " waveform(s)" << std::endl;
}

void SampicWaveformCollection::Show() const {
    Print();
}

} // namespace dataProducts
