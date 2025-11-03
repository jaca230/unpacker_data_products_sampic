#if defined(__ROOTCLING__)

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

// Binary data structures
#pragma link C++ struct dataProducts::SampicHitHeader+;
#pragma link C++ struct dataProducts::SampicHitScalars+;
#pragma link C++ struct dataProducts::SampicEventTimingRecord+;
#pragma link C++ struct dataProducts::SampicCollectorTimingRecord+;

// TObject classes
#pragma link C++ class dataProducts::SampicHitData+;
#pragma link C++ class dataProducts::SampicEvent+;
#pragma link C++ class dataProducts::SampicEventTiming+;
#pragma link C++ class dataProducts::SampicCollectorTiming+;

// STL containers
#pragma link C++ class std::vector<float>+;
#pragma link C++ class std::vector<dataProducts::SampicHitData>+;

#endif
