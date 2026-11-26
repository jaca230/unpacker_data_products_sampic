#pragma once
#include "analysis_pipeline/unpacker_core/data_products/DataProduct.h"
#include <cstdint>
#include <vector>
#include <string>
namespace dataProducts {
// BTnn: source acquisition durations in microseconds, aggregated per builder cycle.
struct SampicBuilderTimingSummary {
    std::uint16_t crate = 0;
    std::uint64_t cycle_id = 0;
    std::uint64_t read_count = 0;
    std::uint64_t hit_count = 0;
    std::uint64_t prepare_us_sum = 0;
    std::uint64_t read_us_sum = 0;
    std::uint64_t decode_us_sum = 0;
    std::uint64_t total_us_sum = 0;
    std::uint64_t prepare_us_max = 0;
    std::uint64_t read_us_max = 0;
    std::uint64_t decode_us_max = 0;
    std::uint64_t total_us_max = 0;
    std::uint64_t retries_sum = 0;
    std::uint64_t retries_max = 0;
    std::uint64_t first_acquisition_id = 0;
    std::uint64_t last_acquisition_id = 0;
};
// BC00: builder durations in nanoseconds; start_ns is relative to run start.
struct SampicBuilderCollectorCycle {
    std::uint64_t cycle_id = 0;
    std::uint64_t start_ns = 0;
    std::uint64_t input_events = 0;
    std::uint64_t input_hits = 0;
    std::uint64_t output_events = 0;
    std::uint64_t output_hits = 0;
    std::uint64_t selected_events = 0;
    std::uint64_t rejected_events = 0;
    std::uint64_t input_read_ns = 0;
    std::uint64_t group_build_ns = 0;
    std::uint64_t cuts_ns = 0;
    std::uint64_t finalize_ns = 0;
    std::uint64_t output_wait_ns = 0;
    std::uint64_t total_ns = 0;
    std::uint64_t flags = 0;
};
// BS00: per-cycle counters, in effective priority/ID order. Later cuts only
// evaluate events that survive earlier cuts. Disabled cuts report zero counters.
struct SampicBuilderCutSummary {
    std::string id;
    bool enabled=false;
    std::int32_t priority=0;
    std::uint64_t evaluated_events=0, rejected_events=0, evaluated_hits=0, rejected_hits=0;
};
class SampicBuilderDiagnostics : public DataProduct {
public:
    std::vector<SampicBuilderTimingSummary> acquisition_summaries;
    bool has_collector_cycle = false;
    SampicBuilderCollectorCycle collector_cycle;
    bool has_cut_summary=false;
    std::uint64_t cut_cycle_id=0;
    std::vector<SampicBuilderCutSummary> cut_summaries;
    ClassDefOverride(SampicBuilderDiagnostics, 2);
};
} // namespace dataProducts
