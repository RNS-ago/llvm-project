add_llvm_component_library(LLVMTRISCVDisassembler
  RISCVDisassembler.cpp

  LINK_COMPONENTS
  MC
  MCDisassembler
  TRISCVDesc
  TRISCVInfo
  Support

  ADD_TO_COMPONENT
  TRISCV
  )
