#if defined(__ROOTCLING__)

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

// Binary data structures
#pragma link C++ struct dataProducts::SampicHitHeader+;
#pragma link C++ struct dataProducts::SampicHitScalars+;
#pragma link C++ struct dataProducts::SampicEventTimingRecord+;
#pragma link C++ struct dataProducts::SampicCollectorTimingRecord+;
#pragma link C++ struct dataProducts::SampicHitMetadataBankHeader+;
#pragma link C++ struct dataProducts::SampicHitMetadataRecord+;
#pragma link C++ struct dataProducts::SampicTriggerGroupRecord+;
#pragma link C++ struct dataProducts::SampicTriggerRecordBankHeader+;
#pragma link C++ struct dataProducts::SampicTriggerRecord+;

// TObject classes
#pragma link C++ class dataProducts::SampicHitData+;
#pragma link C++ class dataProducts::SampicEvent+;
#pragma link C++ class dataProducts::SampicEventTiming+;
#pragma link C++ class dataProducts::SampicCollectorTiming+;
#pragma link C++ class dataProducts::SampicHitMetadataData+;
#pragma link C++ class dataProducts::SampicHitMetadata+;
#pragma link C++ class dataProducts::SampicTriggerGroup+;
#pragma link C++ class dataProducts::SampicTriggerRecordData+;
#pragma link C++ class dataProducts::SampicTriggerRecords+;

// STL containers
#pragma link C++ class std::vector<float>+;
#pragma link C++ class std::vector<dataProducts::SampicHitData>+;
#pragma link C++ class std::vector<dataProducts::SampicHitMetadataData>+;
#pragma link C++ class std::vector<dataProducts::SampicTriggerRecordData>+;

#endif
