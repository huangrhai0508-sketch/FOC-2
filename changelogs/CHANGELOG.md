# Changelog

All notable changes to project files will be documented in this file.

Format: `[Project-Number] YYYY-MM-DD - Description`

---

## 2026-07-29

- Initial setup: git repo, auto-push hook, changelog system created

## 2026-07-29

### [KO11] CT520 PMSM FOC Model - Backup & Cleanup

**Backup**: Full project backed up to `projects/KO11_2026-0729_CT520_backup/`
  - Source: D:\MBD\KO11_2026_0725_转速精度测试\CT520
  - Contains: controller, model, harnesses, plant, sfun, utilities, Requirement

**Cleaned Model**: `pmsmfoc_cleaned.slx` saved to `projects/KO11_2026-0729_CT520_cleaned/`
  - Auto-arranged layout for readability
  - Color-coded subsystems:
    - CoreMsgIf: lightBlue (Core communication)
    - PMC&SVM: lightGreen (Predictive Model Control + Space Vector Modulation)
    - SAQ: orange (Sample and Quantize)
    - CDD&ISP: cyan (Calibration Data Dictionary & ISP)
  - Added 7 new annotations:
    1. Model description header (project info, key features)
    2. Input signals listing (14 inputs documented)
    3. Output signals listing (16 outputs documented)
    4. Processing chain explanation (PMC -> SVM -> SAQ -> CDD flow)
    5. Rate transitions documentation (13 cross-rate blocks)
    6. Signal routing documentation (Goto/From pattern)
    7. Core communication interface documentation (Core0<->Core2 protocol)

**Dependencies**: Model references FOC, CDD_ISP, MathLib - requires original project on MATLAB path
