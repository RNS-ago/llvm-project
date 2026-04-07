add_llvm_component_library(LLVMTRISCVAsmParser
  RISCVAsmParser.cpp

  LINK_COMPONENTS
  MC
  MCParser
  TRISCVDesc
  TRISCVInfo
  Support
  TargetParser

  ADD_TO_COMPONENT
  TRISCV
  )
