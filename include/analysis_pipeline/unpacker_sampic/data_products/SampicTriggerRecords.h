#ifndef SAMPIC_TRIGGER_RECORDS_HH
#define SAMPIC_TRIGGER_RECORDS_HH

#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"

#include <TObject.h>

#include <cstdint>
#include <vector>

namespace dataProducts {

#pragma pack(push, 1)
struct SampicTriggerRecordBankHeader {
    uint32_t count;
};

struct SampicTriggerRecord {
    uint32_t fpga_trigger_id;
    uint32_t external_trigger_id;
    uint16_t spill_number;
    uint16_t raw_extra_word;
    double trigger_timestamp_ns;
};
#pragma pack(pop)

class SampicTriggerRecordData : public TObject {
public:
    uint32_t fpga_trigger_id = 0;
    uint32_t external_trigger_id = 0;
    uint16_t spill_number = 0;
    uint16_t raw_extra_word = 0;
    double trigger_timestamp_ns = 0.0;

    ClassDefOverride(SampicTriggerRecordData, 1)
};

class SampicTriggerRecords : public DataProduct {
public:
    std::vector<SampicTriggerRecordData> triggers;

    ClassDefOverride(SampicTriggerRecords, 1)
};

static_assert(sizeof(SampicTriggerRecordBankHeader) == 4, "Unexpected SV bank header size");
static_assert(sizeof(SampicTriggerRecord) == 20, "Unexpected SV record size");

} // namespace dataProducts

#endif // SAMPIC_TRIGGER_RECORDS_HH
