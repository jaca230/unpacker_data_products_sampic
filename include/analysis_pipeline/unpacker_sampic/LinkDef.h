#if defined(__ROOTCLING__)

#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;

#pragma link C++ struct dataProducts::SampicEventHeader+;
#pragma link C++ struct dataProducts::SampicPacket+;
#pragma link C++ struct dataProducts::SampicEventFooter+;
#pragma link C++ class dataProducts::SampicPacketCollection+;
#pragma link C++ class dataProducts::SampicWaveform+;
#pragma link C++ class dataProducts::SampicWaveformCollection+;
#pragma link C++ class dataProducts::SampicEvent+;

#pragma link C++ struct dataProducts::SampicTimeData+;
#pragma link C++ class dataProducts::SampicTime+;

// STL containers
#pragma link C++ class std::vector<short>+;
#pragma link C++ class std::vector<dataProducts::SampicWaveform>+;
#pragma link C++ class std::vector<dataProducts::SampicPacket>+;

#endif
