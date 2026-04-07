add_llvm_component_library(LLVMTRISCVInfo
  TRISCVTargetInfo.cpp

  LINK_COMPONENTS
  MC
  Support

  ADD_TO_COMPONENT
  TRISCV
  )
