# ITC Club Hub · Software Requirements Specification (SRS)
Standard: ISO/IEC/IEEE 29148:2018 Systems and Software Engineering — Life Cycle Processes — Requirements Engineering

## Document History
| Version | Date | Author | Description of Change |
| :---: | :---: | :--- | :--- |
| **0.1** | 2026-11-14 | Sin Meynanon | Initial draft synthesized from requirements.md and user-stories.md |
| **1.0** | 2026-11-14 | Team I2-ISE | Baselined version 1.0 post peer-review and client agreement |

---

## 1. Introduction

### 1.1 Purpose
This Software Requirements Specification (SRS) defines the complete functional and non-functional requirements for the core backend and Command-Line Interface (CLI) of the **ITC Club Hub** software system (Version 1.0). It establishes the technical baseline for architecture modeling (Lab-06) and Sprint 1 development (Lab-07).

### 1.2 Scope
* **In Scope:**
  * Automated club registration and administrative approval workflows.
  * Event scheduling, publishing, and capacity enforcement.
  * Student event registration with duplicate prevention.
  * Strict 24-hour registration cancellation deadline enforcement.
  * Offline-capable event check-in with duplicate ticket detection.
  * Anonymized monthly attendance report generation for university administration.
  * Privacy-aware data management (data minimization and masked console outputs).
* **Out of Scope (Excluded):**
  * Online ticket payments or financial transactions (campus events are free/funded).
  * Real-time in-app chat or messaging (existing Telegram channels remain in use).
  * Direct synchronization with external university registrar ERP databases in Phase 1.

### 1.3 Product Overview
ITC Club Hub replaces unorganized social media posts and manual paper sign-up sheets at the Institute of Technology of Cambodia (ITC). It provides a unified system where clubs publish activities, students reserve seats under strict capacity rules, and organizers verify attendee badges at the door with sub-second response times, even during complete network outages.

### 1.4 Definitions and Acronyms (8 Core Terms)
1. **Club Hub:** The software application managing student clubs, events, and registrations at ITC.
2. **Event Capacity:** The absolute maximum number of students permitted to register for an event, bounded by physical venue safety limits.
3. **PWA (Progressive Web App):** The target front-end application type that provides offline caching capabilities.
4. **Offline Queue:** A client-side local cache storing uncommitted door check-in transactions until network connectivity is restored.
5. **Gherkin:** A business-readable domain language utilizing `Given-When-Then` syntax to define acceptance test criteria.
6. **Cancellation Cutoff:** The strict boundary time, defined as exactly 24 hours prior to event start time, after which a registration cannot be cancelled.
7. **PII (Personally Identifiable Information):** Data that can directly identify an individual (e.g., student name, email, phone number).
8. **Idempotency Key:** A unique transaction identifier (`localId`) generated during offline check-in ensuring duplicate submissions cause no side effects.

---

## 2. References
1. *ISO/IEC/IEEE 29148:2018* — Requirements Engineering.
2. *ISO/IEC 25010:2011* — Systems and Software Quality Requirements and Evaluation (SQuaRE).
3. *ITC Club Hub Architecture Decision Record (ADR-001)* — `lab02/adr-001-application-type.md`.
4. *ITC Club Hub Personal Data Inventory* — `lab03/data-inventory.md`.

---

## 3. Specific Requirements

### 3.1 External Interfaces
* **Command-Line Interface (CLI):** Executable `clubhub` providing human-readable, accessible terminal output conforming to WCAG 2.2 AA and honoring the `NO_COLOR` environment variable.
* **Storage Interface:** Persistent structured CSV file storage in `data/events.csv`, `data/students.csv`, and `data/registrations.csv`.

### 3.2 Functional Requirements (FR)

* **FR-01: Chronological Event Display**  
  The system shall display upcoming events sorted in ascending chronological order by event start time, excluding events whose start time is prior to the current system time.  
  *Priority:* Must · *Source:* UR-01, N-01 · *Verification:* Automated Unit Test

* **FR-02: Seat Reservation**  
  The system shall create a registration record with status `Registered` and decrement the remaining seat count when a valid student registers for an open event.  
  *Priority:* Must · *Source:* UR-02, N-02 · *Verification:* Automated Integration Test

* **FR-03: Capacity Limit Enforcement (Business Rule 1)**  
  The system shall reject any registration attempt for an event whose confirmed registrations equal or exceed its maximum defined capacity.  
  *Priority:* Must · *Source:* UR-05, N-07 · *Verification:* Automated Boundary Test

* **FR-04: Duplicate Registration Rejection (Business Rule 2)**  
  The system shall reject any registration attempt if a record containing the identical `eventId` and `studentId` already exists.  
  *Priority:* Must · *Source:* UR-02, N-08 · *Verification:* Automated Unit Test

* **FR-05: Valid Registration Cancellation (Business Rule 3A)**  
  The system shall cancel an active registration and increment available capacity by 1 if the cancellation timestamp is at least 24 hours prior to event start time.  
  *Priority:* Must · *Source:* UR-03, N-04 · *Verification:* Automated Boundary Test

* **FR-06: Late Cancellation Rejection (Business Rule 3B)**  
  The system shall reject any cancellation attempt if the cancellation timestamp is less than 24 hours prior to event start time, maintaining status as `Registered`.  
  *Priority:* Must · *Source:* UR-03, N-09 · *Verification:* Automated Boundary Test

* **FR-07: Past Event Rejection (Business Rule 4)**  
  The system shall reject registration requests for events whose start timestamp is less than or equal to the current system time.  
  *Priority:* Must · *Source:* UR-01, N-02 · *Verification:* Automated Unit Test

* **FR-08: Approved Club Gatekeeper (Business Rule 5)**  
  The system shall permit event publication exclusively to clubs whose administrative approval status is `Approved`.  
  *Priority:* Must · *Source:* UR-08, N-14 · *Verification:* Automated Integration Test

* **FR-09: Attendance Recording**  
  The system shall record attendee check-in at the door by transitioning ticket status from `Registered` to `CheckedIn` with a recorded timestamp.  
  *Priority:* Must · *Source:* UR-06, N-10 · *Verification:* Automated Integration Test

* **FR-10: Anti-Passback Ticket Fraud Prevention**  
  The system shall reject any check-in attempt using a ticket ID whose status is already `CheckedIn`.  
  *Priority:* Must · *Source:* UR-06, N-12 · *Verification:* Automated Unit Test

* **FR-11: Offline Check-In Queuing**  
  The system shall queue check-in transactions in a local offline buffer when disconnected and synchronize them idempotently upon reconnection.  
  *Priority:* Must · *Source:* UR-07, N-11 · *Verification:* Automated Integration Test

* **FR-12: Anonymized Administrative Reporting**  
  The system shall generate monthly participation reports containing aggregate attendee counts per club while excluding individual student IDs, names, and contact details.  
  *Priority:* Must · *Source:* UR-09, N-15 · *Verification:* Inspection & Test

* **FR-13: Reminders Consent Management**  
  The system shall maintain email and SMS reminder options as disabled by default, activating alerts only upon explicit opt-in and purging numbers upon consent withdrawal.  
  *Priority:* Should · *Source:* UR-04, N-05 · *Verification:* Automated Unit Test

### 3.3 Usability Requirements
* **NFR-01: First-Time Registration Speed**  
  A first-time student user shall complete event registration in less than 60 seconds without operational guidance.

### 3.4 Performance Efficiency Requirements
* **NFR-02: Check-In Transaction Latency**  
  The system shall validate and confirm a door check-in in less than 1.0 second for at least 95% of transactions under a load of 100 students arriving within 10 minutes.

### 3.5 Reliability & Availability Requirements
* **NFR-03: Zero-Data-Loss Offline Operation**  
  The system shall execute door check-ins during complete network absence with 0% transaction data loss.
* **NFR-04: Crash Recovery**  
  The system shall preserve database integrity during unexpected process termination, recovering to the last valid transaction within 5 seconds.

### 3.6 Security & Privacy Requirements
* **NFR-05: Personal Data Masking**  
  The system shall mask student IDs in console output (`Student{id=e2******7}`) and exclude student email and phone numbers from general event logs.
* **NFR-06: Principle of Data Minimization**  
  The system shall collect only student ID, name, and email for registration, treating phone numbers as strictly optional.
* **NFR-07: Right to Erasure / Immediate Consent Purge**  
  Upon withdrawal of SMS reminder consent, the system shall purge the student's phone number from active memory and storage within 1.0 second.

### 3.7 Design & Environmental Constraints
* **CON-01:** The core domain logic shall be implemented in C++20 without proprietary third-party GUI dependencies.
* **CON-02:** Project builds and automated testing shall be managed via CMake 3.28+ and GoogleTest.

---

## 4. Verification Matrix

| Requirement ID | Verification Method | Verification Procedure |
| :---: | :---: | :--- |
| **FR-01** | Test | Execute unit test comparing output list order with known event timestamp sequence. |
| **FR-02** | Test | Submit valid registration; inspect CSV output to confirm count increment. |
| **FR-03** | Test | Inject registration for event at capacity limit; assert `std::invalid_argument` thrown. |
| **FR-04** | Test | Submit duplicate student ID to registered event; assert rejection error message returned. |
| **FR-05** | Test | Execute cancellation at $t_{\text{start}} - 24.0\text{h}$; assert status becomes `Cancelled`. |
| **FR-06** | Test | Execute cancellation at $t_{\text{start}} - 23.99\text{h}$; assert rejection and status unchanged. |
| **FR-07** | Test | Submit registration for timestamp $t_{\text{start}} \le t_{\text{now}}$; assert rejection. |
| **FR-08** | Test | Attempt event publication from unapproved club; assert authorization failure. |
| **FR-09** | Test | Scan valid ticket ID; verify ticket status transitions to `CheckedIn`. |
| **FR-10** | Test | Rescan already checked-in ticket ID; assert duplicate check-in alarm raised. |
| **FR-11** | Test | Disconnect network; execute 10 check-ins; reconnect; assert 10 synchronized records. |
| **FR-12** | Inspection | Inspect monthly report CSV; confirm absence of student name, ID, or phone columns. |
| **FR-13** | Test | Toggle SMS consent off; assert `Student.phone().has_value() == false`. |
| **NFR-01** | Demonstration | Time 5 novice students registering via CLI; compute average time ($\le 60\text{s}$). |
| **NFR-02** | Test | Benchmark 100 check-in calls in automated harness; assert 95th percentile $< 1.0\text{s}$. |
| **NFR-03** | Test | Simulate network failure during check-in burst; confirm 100% queue retention. |
| **NFR-04** | Test | Send `SIGKILL` during write cycle; reboot and verify CSV parse validity. |
| **NFR-05** | Inspection | Scan terminal logs with regular expressions; verify zero raw student IDs or emails. |