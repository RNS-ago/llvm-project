//===-- TRISCVInstrInfo.td - New TRISC-V ISA instructions ---*- tablegen -*-===//

// SDNode type profile and node definition         
def SDT_TRISCV_CAST_TAG : SDTypeProfile<1, 2,
                             [SDTCisVT<0, i64>,
                              SDTCisVT<1, i64>,
                              SDTCisVT<2, i64>]>;

def triscv_cast_tag : SDNode<"RISCVISD::CAST_TAG", SDT_TRISCV_CAST_TAG>;

// Cast instruction using I-type encoding

let hasSideEffects = 0, mayLoad = 0, mayStore = 0 in
def CAST_TAG : RVInstI<0b001, OPC_CUSTOM_0,
                        (outs GPR:$rd), (ins GPR:$rs1, uimm3:$imm12),
                        "cast", "$rd, $rs1, $imm12">;

def : Pat<(i64 (triscv_cast_tag GPR:$rs1, uimm3:$imm12)),
          (CAST_TAG GPR:$rs1, uimm3:$imm12)>;