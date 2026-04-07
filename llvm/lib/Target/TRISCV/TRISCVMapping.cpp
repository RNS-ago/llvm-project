#include "RISCV.h"
#include "RISCVInstrInfo.h"
#include "RISCVSubtarget.h"
#include "llvm/CodeGen/MachineFunctionPass.h"
#include "llvm/CodeGen/MachineInstrBuilder.h"

using namespace llvm;

#define DEBUG_TYPE "riscv-instr-remap"

namespace llvm {  // Add this
namespace {
class RISCVInstrRemap : public MachineFunctionPass {
public:
  static char ID;
  RISCVInstrRemap() : MachineFunctionPass(ID) {
    initializeRISCVInstrRemapPass(*PassRegistry::getPassRegistry());
  }
  bool runOnMachineFunction(MachineFunction &MF) override {
    const RISCVSubtarget &ST = MF.getSubtarget<RISCVSubtarget>();
    const RISCVInstrInfo *TII = ST.getInstrInfo();
    bool Changed = false;

    for (MachineBasicBlock &MBB : MF) {
      for (MachineBasicBlock::iterator MI = MBB.begin(), E = MBB.end(); MI != E; ) {
        MachineInstr &Inst = *MI++;

        if (remapInstruction(Inst, TII))
          Changed = true;
      }
    }
    return Changed;
  }

  StringRef getPassName() const override {
    return "RISC-V to TRISC-V Instruction Remap";
  }

private:
  bool remapInstruction(MachineInstr &MI, const RISCVInstrInfo *TII) {
    switch (MI.getOpcode()) {

    // Register ALU
    case RISCV::ADDW: {
    	MI.setDesc(TII->get(RISCV::ADD));
      	  return true;
    }
    case RISCV::SUBW: {
          MI.setDesc(TII->get(RISCV::SUB));
          return true;
    }
    case RISCV::SLTU: {
          MI.setDesc(TII->get(RISCV::SLT));
          return true;
    }

    // Immediat ALU
    case RISCV::ADDIW: {
      MI.setDesc(TII->get(RISCV::ADDI));
      return true;
    }


    // Control Flow
    case RISCV::BLTU: {
          MI.setDesc(TII->get(RISCV::BLT));
          return true;
    }
    case RISCV::BGEU: {
          MI.setDesc(TII->get(RISCV::BGE));
          return true;
    }


    // Memory Access
    case RISCV::SB:
    case RISCV::SH:
    case RISCV::SW:
    case RISCV::SD: {
          MI.setDesc(TII->get(RISCV::SB)); // ST equivaletn
          return true;
    }




    default:
      return false;
    }
  }
};
}
char RISCVInstrRemap::ID = 0;

}

INITIALIZE_PASS(RISCVInstrRemap, DEBUG_TYPE,
                "RISC-V instruction remapping", false, false)

namespace llvm {

FunctionPass *createRISCVInstrRemapPass() {
  return new RISCVInstrRemap();
}

}
