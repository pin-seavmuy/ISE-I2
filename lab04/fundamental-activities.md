# Fundamental Activities · Team I2-ISE · v1.0 (2026-11-03)

## 1. Activities in ITC Club Hub

| Activity | What happens in Club Hub | Who leads (role, name) | Weeks | Artifact | Done when |
| :--- | :--- | :--- | :---: | :--- | :--- |
| **Specification** | Interview client (Student Affairs Office); define business rules (24h cancellation, room capacity); write user stories for students and club leaders. | Product Owner | 5–6 | `docs/srs.md` & `lab05/backlog.md` | Client reviews and signs off on the user stories and rules. |
| **Design and Implementation** | Draw 3-tier architecture and UML diagrams; code C++20 domain classes (`Event`, `Student`, `Registration`); parse CSV data files. | Lead Developer | 7, 9–12 | `src/`, `include/clubhub/`, `CMakeLists.txt` | Code compiles cleanly with 0 warnings using CMake. |
| **Validation** | Write GoogleTest unit tests for registration limits; test check-in at the door; verify accessible CLI output (`ConsoleOutputTest`). | Scrum Master | 9–13 | `tests/` & test reports | All automated GoogleTests pass 100% in CI/CD pipeline. |
| **Evolution** | Fix bugs found during client demo; adjust registration rules based on student feedback; refactor code for Sprint 2. | Lead Developer & PO | 11–14 | GitHub Issues & Pull Requests | Bug issues are resolved and closed with passing regression tests. |

---

## 2. Sub-activities and ISO/IEC/IEEE 12207 Processes

- **Specification:**
  - *Sub-activities:* Elicitation interviews, requirements analysis, backlog prioritization, boundary definition.
  - *ISO/IEC/IEEE 12207 standard:* **Stakeholder needs and requirements definition process** & **System/Software requirements definition process**.

- **Design and Implementation:**
  - *Sub-activities:* Architectural design, database/file schema design, writing C++ classes, code reviews on PRs.
  - *ISO/IEC/IEEE 12207 standard:* **Architecture definition process** & **Implementation process**.

- **Validation:**
  - *Sub-activities:* Writing automated unit tests, edge-case checking, manual door-scanner testing, accessibility audit.
  - *ISO/IEC/IEEE 12207 standard:* **Verification process** (did we build it right?) & **Validation process** (did we build the right thing?).

- **Evolution:**
  - *Sub-activities:* Bug fixing, client review feedback handling, code refactoring, adding new features.
  - *ISO/IEC/IEEE 12207 standard:* **Maintenance process** & **Change management process**.

---

## 3. Overlaps and Loops (Feedback in Real Life)

Software is not a one-way street. We repeat steps when we learn new things:

1. **Loop 1: Validation ➔ Design & Implementation (Bug Fix Loop in Sprint 1)**  
   During Sprint 1 testing (Week 10), our automated test discovers that students can cancel registrations 1 hour before an event starts because of a time-zone bug. We loop back from **Validation** to **Implementation** to fix the `canCancel` check in C++.

2. **Loop 2: Client Review ➔ Specification (Scope Change Loop in Sprint 2)**  
   During the Sprint 1 review demo (Week 11), the client sees our event list and requests: *"Can we also add a waiting list when an event is full?"* We loop back from **Review** to **Specification** to write a new user story and acceptance criteria for the waiting list.