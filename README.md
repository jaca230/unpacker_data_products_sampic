# unpacker_data_products_sampic

ROOT data products for the current compact SAMPIC MIDAS bank format.

| Bank | Wire layout | ROOT data product |
|---|---|---|
| SD | `SDC1`, version 1, 12-byte header, 154 bytes/hit | `SampicEvent` |
| SH | Version 2, 8-byte header, 32 bytes/hit | `SampicHitMetadata` |
| ST | 56-byte event timing | `SampicEventTiming` |
| SC | 32-byte collection-cycle timing | `SampicCollectorTiming` |
| SR | Version 1, 56-byte periodic-readout record | `SampicReadoutTick` |
| SB | Version 1, 32-byte fixed-time-bin record | `SampicTimeBin` |
| SG | 36-byte trigger association | `SampicTriggerGroup` |
| SV | 4-byte count + 20 bytes/trigger | `SampicTriggerRecords` |

`SampicHitData.encoded_waveform` preserves valid signed 16-bit wire samples.
`corrected_waveform` contains volts when `adc_corrected` is true (wire value /
10000), otherwise ADC counts. Both arrays contain only the valid `waveform_size`
samples; every wire record always reserves 64 samples. The flags byte and its
six decoded flags preserve correction, waveform clipping/nonfinite, and raw-TOT
clipping information. The old amplitude, baseline, peak, and derived timing
scalars are no longer supplied by compact SD and are removed from the data model.

SH contains physical-cell-zero timestamp, SAMPIC timestamps A/B, FPGA timestamp,
and a 64-bit trigger-position mask. Record i corresponds to SD hit i.

SR times are host steady-clock nanoseconds relative to collection start, not
hardware time; flags are late=1, coalesced=2, final-readout=4. SB uses hardware
nanoseconds and a signed bin index; its end time is exclusive.

Historical unversioned SD and SH v1 are not supported by the compact decoders.
The DAQ's optional `verbose_banks` output is not the target of these data products;
use `verbose_banks=false` for this pipeline.
