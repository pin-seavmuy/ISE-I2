# Lab-03 · Record of What Changed Version 1.0 · 2026-10-26 · Team: I2-ISE

## 1. Deliverable Files

| File | Task | Status | Description |
|---|:---:|:---:|---|
| `lab03/data-inventory.md` | Task 1 | New | Personal data inventory, minimisation decisions & phone lifecycle diagram |
| `lab03/privacy-notice.md` | Task 2 | New | Plain-language privacy notice (< 300 words) |
| `lab03/consent-flow.mmd` | Task 2 | New | Mermaid diagram of opt-in consent and withdrawal flow |
| `lab03/retention-rules.md` | Task 2 | New | Data retention triggers, deletion actions, and verification |
| `include/clubhub/Student.h` | Task 2 | New | Privacy-aware domain model with `redacted()` and input validation |
| `src/Student.cpp` | Task 2 | New | Implementation of `Student` and `maskId()` |
| `tests/StudentPrivacyTest.cpp` | Task 2 | New | 6 GoogleTest unit tests verifying PII masking & validation |
| `lab03/licence-decision.md` | Task 3 | New | Comparison matrix, rationale, and member sign-offs for MIT licence |
| `LICENSE` | Task 3 | New | Standard MIT licence at repository root |
| `THIRD_PARTY_NOTICES.md` | Task 3 | New | Attribution for GoogleTest v1.15.2 (BSD-3-Clause) |
| `licenses/googletest-LICENSE.txt` | Task 3 | New | Full upstream GoogleTest licence text |
| `lab03/accessibility-checklist.md` | Task 4 | New | 12 WCAG 2.2 criteria audit & contrast measurements for 2 screens |
| `lab03/cli-output-rules.md` | Task 4 | New | 6 accessible CLI output rules with Good/Bad examples |
| `include/clubhub/ConsoleOutput.h` | Task 4 | New | Accessible status labels, `NO_COLOR` handling & error formatting |
| `src/ConsoleOutput.cpp` | Task 4 | New | Implementation of accessible console helpers |
| `tests/ConsoleOutputTest.cpp` | Task 4 | New | 3 GoogleTest unit tests for color independence and error text |
| `lab03/ethics-cases.md` | Task 5 | New | 7-step ethical analysis for Scenarios A & B + messages and issue links |
| `CMakeLists.txt` | 2, 4 | Updated | Integrated GoogleTest, `Student`, and `ConsoleOutput` targets |
| `README.md` | Task 3 | Updated | Added Licence and Third-Party attribution section |

---

## 2. Inputs Reused from Earlier Labs

| Input | File | Source Commit |
|---|---|---|
| Team Charter & Member Roles | `lab01/team-charter.md` | Branch `main` (Lab-01 merge) |
| Decision Rules | `lab01/decisions.md` | Branch `main` (Lab-01 merge) |
| Architecture & App Type | `lab02/adr-001-application-type.md` | Branch `main` (Lab-02 merge) |
| Quality Attributes (QAS) | `lab02/quality-scenarios.md` | Branch `main` (Lab-02 merge) |

---

## 3. Change Log

| Date | Change Summary | Author |
|---|---|---|
| 2026-10-26 | Complete Lab-03: Data inventory, privacy notice, C++ Student, MIT licence, WCAG checklist, ConsoleOutput, and ethics analysis | Team KoPrei |

---

## 4. Open Questions for the Client (Student Affairs Office)

1. **Student ID Masking format:** Does the door organizer need to see the first two digits (entry year, e.g., `e2022****`) for visual batch verification, or should the entire ID be masked except the last 3 digits?
2. **Graduation Retention Trigger:** When a student graduates, should their account deletion trigger immediately upon registrar sync, or after a 6-month grace period to allow alumni to export certificates of attendance?
3. **SMS Alerts Cost:** If students opt in to SMS reminders, does the Student Affairs Office cover university SMS gateway costs, or should we encourage Telegram push notifications instead?
