# Lab-04 · Software Development Processes · Team I2-ISE
Version 1.0 · 2026-11-04

## 1. Deliverable Files of this Lab

| File | Task | Description |
| :--- | :---: | :--- |
| `lab04/fundamental-activities.md` | Task 1 | 4 fundamental software engineering activities mapped to ISO/IEC/IEEE 12207 and feedback loops. |
| `lab04/scores/*.md` | Task 2 | Individual process scoring files (one per team member). |
| `lab04/process-comparison.md` | Task 2 | Weighted process decision matrix (Waterfall vs. Incremental vs. Scrum) with sensitivity analysis. |
| `lab04/process-decision.md` | Task 3 | PDR-001 decision record documenting the tailored Scrum process and team approvals. |
| `lab04/process.mmd` | Task 3 | Mermaid flowchart source visualizing semester development flow from Weeks 5 to 14. |
| `lab04/iteration-plan.md` | Task 4 | Mermaid Gantt chart starting Nov 2, 2026, with iteration goals and sprint capacity calculations. |
| `lab04/reuse-inventory.md` | Task 5 | Make-or-reuse matrix for 8 technical needs, licence checks, and CTest verification. |
| `CMakeLists.txt` | Task 5 | Updated build file using `FetchContent` to manage `googletest` v1.17.0 and `rapidcsv` v8.84. |
| `tests/data/events.csv` | Task 5 | Test fixture containing sample event CSV data. |
| `tests/csv_smoke_test.cpp` | Task 5 | Automated unit test verifying that `rapidcsv` correctly parses event titles and capacities. |
| `lab04/README.md` | Task 5 | Summary record of files, reused inputs, dependencies, and change log. |

---

## 2. Inputs Reused from Earlier Labs

| Input | Reused File | Commit / Branch Reference |
| :--- | :--- | :--- |
| **Team Charter** | `lab01/team-charter.md` | Branch `main` (member roles, weekly hours) |
| **Problem Statement** | `lab01/problem-statement.md` | Branch `main` (stakeholder needs, core problems) |
| **Application Type** | `lab02/adr-001-application-type.md` | Branch `main` (C++20 CLI with CSV storage) |
| **Project Licence** | `LICENSE` | Branch `main` (MIT Licence) |

---

## 3. External Dependencies Managed via FetchContent

| Library | Version | Licence | Purpose |
| :--- | :---: | :---: | :--- |
| **GoogleTest** | `v1.17.0` | BSD-3-Clause | Automated unit testing framework. |
| **rapidcsv** | `v8.84` | BSD-3-Clause | Header-only CSV parser for event data persistence. |

---

## 4. Change Log

| Date | Change Summary | Author |
| :---: | :--- | :--- |
| 2026-11-04 | Complete Lab-04: Fundamental activities, process comparison, PDR-001, iteration plan Gantt chart, reuse inventory, and FetchContent smoke test. | Team I2-ISE |