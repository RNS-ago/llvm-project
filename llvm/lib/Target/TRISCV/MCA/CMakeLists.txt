add_llvm_component_library(LLVMRISCVTargetMCA
  RISCVCustomBehaviour.cpp

  LINK_COMPONENTS
  CodeGenTypes
  MC
  MCA
  MCParser
  TRISCVDesc
  TRISCVInfo
  Support
  TargetParser

  ADD_TO_COMPONENT
  TRISCV
  )
