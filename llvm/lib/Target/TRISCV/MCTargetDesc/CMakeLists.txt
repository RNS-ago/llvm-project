add_llvm_component_library(LLVMTRISCVDesc
  RISCVAsmBackend.cpp
  RISCVBaseInfo.cpp
  RISCVELFObjectWriter.cpp
  RISCVInstPrinter.cpp
  RISCVMCAsmInfo.cpp
  RISCVMCCodeEmitter.cpp
  RISCVMCExpr.cpp
  RISCVMCObjectFileInfo.cpp
  RISCVMCTargetDesc.cpp
  RISCVMachObjectWriter.cpp
  RISCVMatInt.cpp
  RISCVTargetStreamer.cpp
  RISCVELFStreamer.cpp

  LINK_COMPONENTS
  BinaryFormat
  MC
  TRISCVInfo
  Support
  TargetParser

  ADD_TO_COMPONENT
  TRISCV
)
